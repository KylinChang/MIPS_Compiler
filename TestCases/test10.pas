program test9;

const
    haha = true;
    PI=3.14 ;
    fir = 1;
    sec = 10;
    LARGE = 10000202020202;

type
    arr = array[1..10] of integer;
    car = record
            number : string;
            legal : boolean;
            level : integer;
        end;

var
    a, b, c, n:integer;
    arr_var: arr;
    hhh : integer;
    book: record
        title : integer;
        author : integer;
        content : string;
        pal : boolean;
    end;
    cc : car;
    test_str1 : string;

procedure findMin(x, y:integer; var m:integer);
begin

    if x<y then
        m:=x
    else
        m:=y;
end;

procedure proc1;
begin
end;

function func1:integer;
begin
end;

begin
    read(a);
    readln(n);
    case n of
    1: writeln(0);
    2: writeln(1);
    3: begin
        a := 1;
        b := 2;
        end;
    end;

    arr_var[10]:=10; 

    while true do
    begin
        a:=1;
        b:=1;
        c:=2;
    end;

    proc1;
    func1;

    book.title := 1;
    book.content := '123';

    a:=book.title;
    test_str1 := book.content;

    begin
        a:=1;
        b:=1;
        c:=2;
    end;

        if (a > b) then
            c := a;
 	hhh := (a+b) * a;

	findMin(a,b,c);


        for a:= 1*2 to 100 do begin
            c:= c + 1;	
	end;
   
end.
