program test7;
var
    n:integer;
function nabs(x:integer):integer;
begin
    if (x<0) then nabs:=x else nabs:=0-x;
end;
begin
    read(n);
    n:=nabs(n);
    writeln(n);
end.
