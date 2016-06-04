# MIPS_Compiler
This is a compiler for translating C language into MIPS assemble language.

##lex
* 文档里好像没有数字、字符和字符串常量??有的，在const_value中

* 文档里的goto_stmt ： GOTO  INTEGER这句应该写错了 (这句没写错，是我INTEGER理解错了)

* SYS_CON、SYS_TYPE不知道是什么。(应该就是系统自带常量和系统自带type)
pascal中自带标识符：maxint

##yacc
The syntax tree has following features:

* The tree is a multi-way tree. The same-priority ascendants of a parent will be hanged by the same parent.

* the grammar expression expr term will be a little bit different, they are under the form of left-child-right-sibling
