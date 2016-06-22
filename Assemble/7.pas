program test7;
var
    n,sum:integer;
function nabs(x:integer):integer;
begin
    nabs:=0-x;
end;
begin
    read(n);
    sum:=nabs(n);
    writeln(sum);
end.
