# MIPS_Compiler
This is a compiler for translating C language into MIPS assemble language.

##lex

##yacc
The syntax tree has following features:

* The tree is a multi-way tree. The same-priority ascendants of a parent will be hanged by the same parent.

* the grammar expression expr term will be a little bit different, they are under the form of left-child-right-sibling
