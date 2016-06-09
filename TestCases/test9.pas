program test9;

const
    haha = true;
    PI=3.14 ;

type
    innn = integer;
    color = innn;
    xxx = record
        title : integer;
        author : integer;
    end;
    arr = array[1..10] of integer;

var
    n,i:byte;
    a,b,c:longint;
    hhh : real;
    book: record
        title : integer;
        author : integer;
    end;
    arr_var : arr;
    clr_var : color;


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
    arr_var[3] := 2+3;

    1:
    a:=1;
    b:=2;
    goto 1;

    while true do
        begin
            a:=1;
            b:=1;
            c:=2;
        end;


    hhh := (a+b) * a;


end.