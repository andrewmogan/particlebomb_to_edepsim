# particlebomb_to_edepsim

This repository was generated using `LiteFMWK`, a framework generator for linking C++ and python code. The documentation for LiteFMWK is copied here for convenience. All credit for the documentation and creation of LiteFMWK goes to the user drinkingkazu. 

`LiteFMWK` is a software development base that allows you to:
* Generate a software _package_ where you can generate arbitrary number of C++ class/function and compile into 1 library
* Automatically generate ROOT cling dictionary to access compiled class/function from cling/python interpreters (latter via PyROOT)
* Support a structure for introducing inter-package dependencies

## How to use it?
Just try:
```
source setup.sh
```
This sets up necessary shell env. variables. 
You need to have `ROOT6` (if not, you get an error message from `setup.sh`).
There's a support to detect `numpy` and provide a few handy compiler directives as well.

## How to make a new _package_?
Just try:
```
gen_my_package Aho
```
... which will generate a directory named `Aho` under the repository top directory.
A new package comes with `GNUmakefile` which allows you to compile a package by simply typing `make` in the package directory.
You also find `sample.h` and `sample.cxx`. 
These are very much empty C++ classes just to demonstrate that you can `make` and access them from an interpreter.
```
python -c "import ROOT;print ROOT.Aho.sample()"
```

## Generating a new class
In a package directory you can generate a new class. You can of course just type-it-up from scratch.
You can also try:
```
gen_my_class Tako
```
... which generates `Tako.h` and `Tako.cxx` much like `sample` class.  Again, to compile, you can just type  `make`.

If you have written your class from scratch, make sure you add your class to `LinkDef.h` if you want a dictionary generation (e.g. if you want an access from an interpreter).

## Example?
You can find an example in this branch:
```
git checkout example
```

## Compiling multiple packages
No one wants to `cd` package directory and `make` for every package. You can utilize the top level `GNUmakefile` which is extremely simple and hopefully self-descriptive. All you need to do is to list (space-separated) packages in `SUBDIRS` variable.

## Excluding a class from dictionary generation
Sometimes you don't want to expose your C++ class to an interpreter.
Assuming your C++ class is already registered in the dictionary (a mechanism to make your class available in an interpreter), simply exclude it from `LinkDef.h`.

