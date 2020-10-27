# Release 0.2.5 (development release)

<h3>New features since last release</h3>

* Arrays and variables now support being defined as parameters (using braces) in
  a Blackbird template.
  [(#34)](https://github.com/XanaduAI/blackbird/pull/34)

* Time-domain multiplex programs are now supported, using the syntax `type tdm
  (temporal_modes=3, copies=1)`.
  [(#30)](https://github.com/XanaduAI/blackbird/pull/30)

* For-loops are supported inside Blackbird scripts.

  They can be defined using ranges (from:to:step)

  ```python
  for float v in 2:10:3
    MZgate(v, v/2) | [0, 1]
  ```

  or lists

  ```python
  for int m in [0, 2, 4]
    MeasureFock() | m
  ```

  [(#24)](https://github.com/XanaduAI/blackbird/pull/24)

* Keyword arguments are supported inside operations; for example,
  `MeasureHomodyne(select=[0, 1])` or `MeasureFock(dark_counts=[1, 0.5, 3])`
  [(#22)](https://github.com/XanaduAI/blackbird/pull/23)

* Indexing is supported inside both modes and arguments; for example,
  `MZgate(list[2], list[0]) | [list[3], list[1]]))`. All indices allow
  expressions such as `phases[-3 + 2*2]`.
  [(#22)](https://github.com/XanaduAI/blackbird/pull/23)

<h3>Improvements</h3>

<h3>Breaking changes</h3>

<h3>Bug fixes</h3>

* Templates are no longer changed when calling them and replacing the parameters with actual values.
  [(#34)](https://github.com/XanaduAI/blackbird/pull/34)

<h3>Documentation</h3>

This release contains contributions from (in alphabetical order):

Theodor Isacsson
