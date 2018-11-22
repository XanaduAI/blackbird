ANTLR4 := java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$(CLASSPATH)" org.antlr.v4.Tool
GRUN := java org.antlr.v4.gui.TestRig

PYTHON3 := $(shell which python3 2>/dev/null)

PYTHON := python3
COVERAGE := --cov=pennylane --cov-report term-missing --cov-report=html:coverage_html_report
TESTRUNNER := -m pytest tests

GRAMMAR := blackbird.g4

.PHONY: help
help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  install            to install PennyLane"
	@echo "  wheel              to build the PennyLane wheel"
	@echo "  dist               to package the source distribution"
	@echo "  clean              to delete all temporary, cache, and build files"
	@echo "  clean-docs         to delete all built documentation"
	@echo "  test               to run the test suite"
	@echo "  coverage           to generate a coverage report"

.PHONY: install
install:
ifndef PYTHON3
	@echo "To install PennyLane you need to have Python 3 installed"
endif
	$(PYTHON) setup.py install

.PHONY: wheel
wheel:
	$(PYTHON) setup.py bdist_wheel

.PHONY: dist
dist:
	$(PYTHON) setup.py sdist

.PHONY : clean
clean:
	rm -rf pennylane/__pycache__
	rm -rf pennylane/optimize/__pycache__
	rm -rf pennylane/expectation/__pycache__
	rm -rf pennylane/ops/__pycache__
	rm -rf pennylane/plugins/__pycache__
	rm -rf tests/__pycache__
	rm -rf dist
	rm -rf build
	rm -rf .coverage coverage_html_report/

docs:
	make -C doc html

.PHONY : clean-docs
clean-docs:
	make -C doc clean

python: $(GRAMMAR)
	$(ANTLR4) -Dlanguage=Python3 blackbird.g4 -o blackbird_python

cpp: $(GRAMMAR)
	$(ANTLR4) -Dlanguage=Cpp blackbird.g4 -o blackbird_cpp

test: $(GRAMMAR)
	mkdir -p _test
	$(ANTLR4) blackbird.g4 -o _test
	cd _test && javac *.java
	cd _test && $(GRUN) blackbird start ../example.xbb -gui
	rm -rf _test

coverage:
	@echo "Generating coverage report..."
	$(PYTHON) $(TESTRUNNER) $(COVERAGE)
