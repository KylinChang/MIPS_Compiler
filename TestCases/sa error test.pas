program sa_errortest;

const
ica = 1;
icb = 10;
fcc = 1.0;
ccd = 'a';
sce = 'hello';
{duplicate identifier}
fcc = 2.0;

type
    ti = integer;
    tf = real;
    
    {duplicate identifer}
    tf = extended;
    {undefined type}
    tu = undefinedType;
    
    tenum = (a, b, c);
    
    {invalid enum item identifier}
    tenum_invalid1 = (ti, d, e);
    tenum_invalid2 = (ica, f, g);
    {duplicate enum item}
    tenum_invalid2 = (e, g, h);
    
    trange1 = (1..2)
    trange2 = (ica, icb)
    trange3 = (-icb, ica)
    
    {range data type mismatch}
    trange_invalid1 = (1, 2.0)
    trange_invalid2 = (fcc, icb)
    {illegal range}
    trange_invalid3 = (2, 1)
    trange_invalid4 = (icb, ica)
    {unsupported range data type}
    trange_invalid5 = (1.0, 2.0)
    {undefined const identifier}
    trange_invalid6 = (undefined1, undefined2)
    
    trecord = record 
    a: integer;
    b: real;
    c: string;
    end;
    
    {duplicate field name}
    trecord_invalid = record 
    a: integer;
    b: real;
    c: string;
    c: integer;
    end;
    

var
    va, vb, vc, vn:integer;
    vrange: trange1;
    vrecord: trecord;
    varray: array[1..2] of integer;
    {duplicate identifier}
    va: real;
    ica: integer;

procedure pa;
begin
end;
function fb: integer;
begin
end;

{duplicate function definition}
function pa: real;
begin
end;

{duplicate procedure definition}
procedure fb;
begin
end;

function fparameter(x, y: integer): integer;
const
{duplicate identifier}
    x = 1;
begin
    fparameter = 1;
end;

{duplicate parameter name}
function fparameter_invalid(x, y: integer, x, z: real): integer;
begin
    fparameter_invalid = 2;
end;


begin
    1: va := 1;
    
    {duplicate label}
    1: vb := 1;
    {undefined variable}
    vx := 1;
    
    {unsupport assignment operator}
    vrange := 1;
    
    {type mismatch between assignment operator}
    vrecord := 1
    
    {cannot automatic downcast data type automatically}
    va := 1.0;
    
    {va is not an array}
    va[1] := 1.0;
    
    {}
    
    read(a);
    readln(n);
    case n of
    1: writeln(0);
    2: writeln(1);
    3: begin
        a := 980*10+100;
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
        a:=a*2+-3-4;
        b:=(-a-b)*(3+4*5);
        c:=2;
    end;

        if (a > b) then
            c := a;
	if (a+8*9 = b) then
		c:=a;
	if (a+8*9 <> b) then
		c:=a;


	findMin(a,b,c);


        for a:= -1+2 to 100 do begin
            c:= c + 2+8*9;	
	end;

	for b:= a+100*10 downto -1 do begin
            c:= c + 2+8*9;	
	end;
   
end.
