var
    n:longint;
function fact(x:longint):longint;
begin
    if (x=0) then fact:=1 else fact := x * fact(x-1);
end;
begin
    readln(n);
    n:=fact(n);
    writeln(n);
end.
