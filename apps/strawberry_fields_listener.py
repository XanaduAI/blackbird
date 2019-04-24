# Copyright 2019 Xanadu Quantum Technologies Inc.

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at

#     http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# pylint: disable=too-many-return-statements,too-many-branches,too-many-instance-attributes
"""Strawberry Fields Blackbird parser"""
import sys
import antlr4

import numpy as np

import strawberryfields as sf
import strawberryfields.ops as sfo

from blackbird import BlackbirdListener, RegRefTransform, parse_blackbird


class StrawberryFieldsListener(BlackbirdListener):
    """Listener to run a Blackbird program using Strawberry Fields"""
    def __init__(self):
        super().__init__()
        self.eng = None
        self.q = None

        self.state = None
        self.result = []

    def run(self):
        if self.target is None:
            raise ValueError("Blackbird program has no target backend")

        self.eng, self.q = sf.Engine(
            len(self.active_modes),
            hbar=self.target['options'].get('hbar', 2)
        )

        self.target['options'].pop('hbar', None)

        with self.eng:
            for statement in self.queue:
                modes = statement['modes']

                if 'args' in statement:
                    args = statement['args']
                    kwargs = statement['kwargs']

                    for idx, a in enumerate(args):
                        if isinstance(a, RegRefTransform):
                            regrefs = [self.q[i] for i in a.regrefs]
                            args[idx] = sf.engine.RegRefTransform(regrefs, a.func, a.func_str)

                    op = getattr(sfo, statement['op'])(*args, **kwargs)
                else:
                    op = getattr(sfo, statement['op'])

                op | [self.q[i] for i in modes] #pylint:disable=pointless-statement

        shots = self.target['options'].get('shots', 1)
        self.target['options'].pop('shots', None)

        for _ in range(shots):
            self.eng.reset(keep_history=True)
            self.state = self.eng.run(self.target['name'], **self.target['options'])
            self.result.append([q.val for q in self.q])

    def print_results(self):
        """Print the results of the blackbird program execution"""
        print('Program')
        print('-------')
        self.eng.print_applied()
        print()

        print('Results')
        print('-------')
        for row in self.result:
            print(row)


def run(file):
    """Parse and run a blackbird program using Strawberry Fields.

    Args:
        file (str): location of the .xbb blackbird file to run
    Returns:
        list: list of size ``[shots, num_subsystems]``, representing
        the measured qumode values for each shot
    """
    simulation = parse_blackbird(file, listener=StrawberryFieldsListener)
    simulation.run()
    simulation.print_results()


if __name__ == '__main__':
    run(sys.argv[1])
