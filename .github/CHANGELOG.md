# Release 0.6.0 (development release)

<h3>New features since last release</h3>

<h3>Improvements</h3>

<h3>Breaking changes</h3>

<h3>Bug fixes</h3>

<h3>Documentation</h3>

<h3>Contributors</h3>

This release contains contributions from (in alphabetical order):

---

# Release 0.5.0 (current release)

<h3>New features since last release</h3>

* Rebuilds the grammar using ANTLR `v4.9.2`
  [(#51)](https://github.com/XanaduAI/blackbird/pull/51)

<h3>Documentation</h3>

* Updates ANTLR `v4.9.2` version on the _compiling grammar_ section.
  [(#51)](https://github.com/XanaduAI/blackbird/pull/51)

<h3>Contributors</h3>

This release contains contributions from (in alphabetical order):

Kshitij Chhabra (@kshitijc), Sebastián Duque Mesa (@sduquemesa)

---

# Release 0.4.0

<h3>Improvements</h3>

* Remove support for Python 3.5.
  [(#38)](https://github.com/XanaduAI/blackbird/pull/38)

* Add support for Python 3.8 and 3.9.
  [(#40)](https://github.com/XanaduAI/blackbird/pull/39)

* Add public method to retrieve Blackbird program variables via `prog.variables`.
  [(#47)](https://github.com/XanaduAI/blackbird/pull/47)

* Improve `match_template` to automatically return matched parameters with their array values,
  rather than their array names (p0, p1, etc.)
  [(#47)](https://github.com/XanaduAI/blackbird/pull/47)

* Remove p-type parameters from `prog.parameters` since they're only needed there internally and
  are otherwise stored in `prog.variables`. This also changes TDM programs to not be templates
  (`prog.is_template` now returns `False`).
  [(#47)](https://github.com/XanaduAI/blackbird/pull/47)

<h3>Bug fixes</h3>

* Fix bool or string objects in for-loop iterators not working correctly.
  [(#41)](https://github.com/XanaduAI/blackbird/pull/41)

* Update the NumPy scalar types in the Blackbird listener due to being deprecated in NumPy 1.20.
  [(#43)](https://github.com/XanaduAI/blackbird/pull/43)

* Add access to the symbolic expression used when creating a `RegRefTransform`,
  as a class attribute.
  [(#46)](https://github.com/XanaduAI/blackbird/pull/46)

<h3>Contributors</h3>

This release contains contributions from (in alphabetical order):

Theodor Isacsson

---

# Release 0.3.0

<h3>New features since last release</h3>

* Arrays and variables now support being defined as parameters (using braces) in
  a Blackbird template.
  [(#34)](https://github.com/XanaduAI/blackbird/pull/34)

* Time-domain multiplexing programs are now supported, using the syntax `type tdm
  (temporal_modes=3, copies=1)`.
  [(#30)](https://github.com/XanaduAI/blackbird/pull/30)

* For-loops are supported inside Blackbird scripts.
  [(#24)](https://github.com/XanaduAI/blackbird/pull/24)

  They can be defined using ranges via the syntax `from:to:step`:

  ```python
  for float v in 2:10:3
    MZgate(v, v/2) | [0, 1]
  ```

  or lists

  ```python
  for int m in [0, 2, 4]
    MeasureFock() | m
  ```

* Keyword arguments are supported inside operations; for example,
  `MeasureHomodyne(select=[0, 1])` or `MeasureFock(dark_counts=[1, 0.5, 3])`.
  [(#23)](https://github.com/XanaduAI/blackbird/pull/23)

* Indexing is supported inside both modes and arguments; for example,
  `MZgate(list[2], list[0]) | [list[3], list[1]]))`. All indices allow
  expressions such as `phases[-3 + 2*2]`.
  [(#23)](https://github.com/XanaduAI/blackbird/pull/23)

<h3>Bug fixes</h3>

* Templates are no longer changed when calling them and replacing the parameters
  with actual values.
  [(#34)](https://github.com/XanaduAI/blackbird/pull/34)

<h3>Documentation</h3>

* TDM programs, for-loops and array indexing is added to the docs, along with
  other minor updates.
  [(#28)](https://github.com/XanaduAI/blackbird/pull/28)

This release contains contributions from (in alphabetical order):

Theodor Isacsson
