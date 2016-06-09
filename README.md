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

* we do not support array[integer/char] declaration form, 

## Symbol Table

* we support enum type just like C(by adding those token into constant table), so you could use symbolTable.findConst to get the corresponding int value.

##Special Points

* we do not support pointer.

* the label can only be integer.

* in the for statement(for id := var1 to var2), if var1 or var2 is a constant value, then it must be a shortint, when the constant values is larger than 32767, the compiler will output an error. However, if var1 or var2 is variable, then they do not obey the rule.

* if a function or a procedure does not have any arguments, it is called by directly write its name without any parenthesis, for example:

function func() : integer;
begin
end;

func;

* char cannot be assigned to integer or real.

* record can be assigned as a whole, but array can not.

* expression should be checked when there exists type difference in assignment, just consider the following example:

var
x, y:longint;
a, c: longint;
b, d: dword;

a:= 2147483645;
b:=5;
c:=-10;
d:=5;

x := a+b;

y := c+d;

In the above example, x is -2147483646 and y is -5, but when writeln(a+b), it outputs 2147483650, which means the pascal can auto translates the values according to type. So we let the final expression as a longint-dword type.

The code generation step should carefully consider this case and know that if the type is different here, it means that the value may be auto-transformed.

* the arguments can only be integer, boolean, real, string, char.

* keyword 'not', 'and', 'or' can only be followed by integer or boolean. for example, not 1 is -2 and not true is false.




