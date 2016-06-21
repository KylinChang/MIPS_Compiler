program test1;
const
    str= 123;
var
    x:integer;

procedure findMin(x, y:integer; var m:integer);
begin

    if x<y then
        m:=x
    else
        m:=y;
end;

function max(var num1, num2: integer): integer;
var
    result: integer;
begin
    if (num1 > num2) then
        result := num1
    else
        result := num2;
    max := result;
end;
begin
    x:=1+2+3*3+2;
end.