program test12;
var
    n,m:integer;
function minsquare(x,y:integer):integer;
var
    temp:integer;

    function min(x,y:integer):integer;
    begin
        if (x<y) then min:=x else min:=y;
    end;

begin
    temp:=min(x,y);
    minsquare:=temp*temp;
end;
begin
    n:=3;
    m:=4;
    n:=minsquare(n,m);
    writeln(n);
end.

