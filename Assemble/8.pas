program test8;
var
    n:longint;
function fact(x:longint):longint;
begin
    if (x=0) then fact:=1 else fact := x * fact(x-1);
end;
begin
    n:=3;
    n:=fact(fact(n));
    writeln(n);
end.
