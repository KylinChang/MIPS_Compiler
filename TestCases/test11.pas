program test4;

var 
x,y:longint;
a, c: longint;
b, d: dword;
arr : array[0..10] of integer;
e, f: integer;


begin
a:= 2147483645;
b:=5;
c:=-10;
d:=5;

x := a+b;
writeln(a+b);

y:=c+d;
writeln(y);

arr[0] := 10;


    e := 10;
    f := 5;
    e := e DIV f;
    writeln(e);

end.
