PREFIX := $(shell echo $(PREFIX))

ANTLR4 := java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$(CLASSPATH)" org.antlr.v4.Tool
GRUN := java org.antlr.v4.gui.TestRig

PYTHON3 := $(shell which python3 2>/dev/null)

PYTHON := python3
COVERAGE := --cov=blackbird_python/blackbird --cov-report term-missing --cov-report=html:coverage_html_report
TESTRUNNER := -m pytest tests

GRAMMAR := blackbird.g4

.PHONY: help
help:
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  install            to install Blackbird"
	@echo "  wheel              to build the Blackbird wheel"
	@echo "  dist               to package the source distribution"
	@echo "  clean              to delete all temporary, cache, and build files"
	@echo "  clean-docs         to delete all built documentation"
	@echo "  test               to run the Python test suite"
	@echo "  test-grammar       to run the grammar test suite"
	@echo "  coverage           to generate a coverage report"

install: build/libblackbird.so
	cd build && make install

build/libblackbird.so: blackbird-cpp

.PHONY: wheel
wheel:
	$(PYTHON) setup.py bdist_wheel

.PHONY: dist
dist:
	$(PYTHON) setup.py sdist

.PHONY : clean
clean:
	rm -rf blackbird_python/blackbird/__pycache__
	rm -rf blackbird_python/blackbird/tests/__pycache__
	rm -rf dist
	rm -rf build
	rm -rf build_examples
	rm -rf .coverage coverage_html_report/

docs:
	make -C doc html

.PHONY : clean-docs
clean-docs:
	make -C doc clean

grammar: grammar-python grammar-cpp

grammar-python: src/$(GRAMMAR)
	cd src && $(ANTLR4) -Dlanguage=Python3 $(GRAMMAR) -o ../blackbird_python/blackbird

grammar-cpp: src/$(GRAMMAR)
	cd src && $(ANTLR4) -Dlanguage=Cpp -visitor -no-listener $(GRAMMAR) -o ../blackbird_cpp

blackbird-cpp:
	mkdir -p build
ifeq ($(PREFIX),)
	cd build && cmake ../blackbird_cpp && make -j4
else
	cd build && cmake -DCMAKE_INSTALL_PREFIX:PATH=$(PREFIX) ../blackbird_cpp && make -j4
endif

cpp-examples:
	mkdir -p build_examples
	cd build_examples && cmake ../cpp_examples && make -j4

test-grammar: src/$(GRAMMAR)
	mkdir -p _test
	cd src && $(ANTLR4) $(GRAMMAR) -o ../_test
	cd _test && javac *.java
	cd _test && $(GRUN) blackbird start ../examples/example.xbb -gui
	rm -rf _test

coverage:
	@echo "Generating coverage report..."
	$(PYTHON) $(TESTRUNNER) $(COVERAGE)
