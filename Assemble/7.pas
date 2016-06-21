var
    n:integer;
function f(x:integer):integer;
var
    i:integer;
begin
    f:=0;
    for i:=1 to x do f:=f+i;
end;
begin
    readln(n);
    n:=f(n);
    writeln(n);
end.
