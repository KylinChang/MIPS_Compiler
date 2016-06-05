program test8;
const
    haha = true;
PI=3.14 ;

type
color = a;

var
    n,i:byte;
    a,b,c:longint;
    book: record
        title : integer;
        author : integer;
    end;


procedure findMin(x, y:integer; var m:integer);
begin

    if x<y then
        m:=x
    else
        m:=y;
end;

function max(num1, num2: integer): integer;
var
    result: integer;
begin
    if (num1 > num2) then
        result := num1
    else
        result := num2;
    max := result;
end;

function add(num1, num2: integer): integer;
var
    result: integer;
begin
    result := num1 + num2;
    add := result;
end;

begin
    readln(n);
    case n of
    1: writeln(0);
    2: writeln(1);
    end;

    1:
        a:=1;
        b:=2;
    goto 1;


end.