# MIPS_Compiler
This is a compiler for translating C language into MIPS assemble language.
It doesn't support pointer, nested record declaration.

##lex

##yacc

###summary

The syntax tree has following features:

* The tree is a multi-way tree. The same-priority ascendants of a parent will be hanged by the same parent.

* The grammar expression expr term will be a little bit different, they are under the form of left-sibling-right-child

###about syntax tree

* The const part is in form of "const_var := const_val", where 'const_val' is integer, real, char ,string or system constant 'maxint' 'maxlongint' 'true' 'false'

* The record part doesn't support nested form