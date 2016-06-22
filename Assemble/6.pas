program test6;
var
    n,fact,i:longint;
    a:real;
begin
    read(n);
    fact:=1;
    a:=1.0;
    for i:=1 to n do
        begin
           fact:=fact*i;
           a:=a+1/fact;
        end;
    writeln(a);
end.
