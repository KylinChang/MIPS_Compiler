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
    
    trange1 = 1..2;
    trange2 = ica..icb;
    trange3 = -icb..ica;
    
    {range data type mismatch}
    trange_invalid1 = 1..2.0;
    trange_invalid2 = fcc..icb;
    {illegal range}
    trange_invalid3 = 2..1;
    trange_invalid4 = icb..ica;
    {unsupported range data type}
    trange_invalid5 = 1.0..2.0;
    {undefined const identifier}
    trange_invalid6 = undefined1..undefined2;
    
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
    vra: real;
    vba: boolean;
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
    fb := 1;
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
begin
    fparameter := 1;
end;

function fparameter_invalid1(x, y: integer): integer;
const
{duplicate identifier}
    x = 1;
begin
    fparameter_invalid1 := 1;
end;


{duplicate parameter name}
function fparameter_invalid2(x, y: integer; x, z: real): integer;
begin
    fparameter_invalid2 := 2;
end;

function fparameter_invalid3(x, y: integer): integer;
begin
{undefined variable}
    fparameter := 1;
end;


begin
    1: va := 1;
    vra := 1.0;
    vra := 1;
    
    {duplicate label}
    1: vb := 1;
    {undefined variable}
    vx := 1;
    
    {unsupport assignment operator}
    vrange := 1;
    
    {type mismatch between assignment operator}
    vrecord := 1;
    
    {cannot downcast data type automatically}
    va := 1.0;

    varray[1] := 1;
    
    {va is not an array}
    va[1] := 1.0;
    {index must be integer}
    varray[2.0] := 2;
    {type mismatch between assignment operator}
    varray[2] := vrange;
    {cannot downcast data type automatically}
    varray[2] := 2.0;
    
    vrecord.a := 1;
    
    {va is not a record}
    va.a := 1;
    {invalid attribute}
    vrecord.undefined := 1;
    
    pa;
    
    {undefined function or procedure}
    ppa;
    
    read(va);
    
    {read needs a lvalue}
    read(1);
    
    
    if va = 1 then 
        write(va)
    else
        write(vb);
        
    repeat
        va := 1;
    until va = 1;
    
    while va = 1 do
    begin
        va:=2;
    end;
    
    for va := 1 to 2 do
        vb := vb + 1;
    
    {the type of condition clause must be boolean}
    if va then 
        write(va);
        
    repeat
        va := 1;
    until va;
    
    while va do
    begin
        va:=2;
    end;
    
    {ica must be a variable}
    for ica := 1 to 2 do
        vb := vb + 1;
    {undefined variable}
    for undefined := 1 to 2 do
        vb := vb + 1;
    {vra must be integer}
    for vra := 1 to 2 do
        vb := vb + 1;
    {for loop require integer type}
    for va := 1 to vra do
        vb := vb + 1;
    
    case vn of
    1: writeln(0);
    2: writeln(1);
    3: begin
        va := 980*10+100;
        vb := 2;
        end;
    end;
    
    {vra must be integer or char}
    case vra of
    1: writeln(0);
    2: writeln(1);
    3: begin
        a := 980*10+100;
        b := 2;
        end;
    end;
    {label type mismatch}
    case vn of
    1: writeln(0);
    2: writeln(1);
    '3': begin
        a := 980*10+100;
        b := 2;
        end;
    end;
    
    goto 1;
    {use a invalid label}
    goto 2;

    vba := '1' > '2';
    va := 1 + 2;
    vba := (va = 1) or (vb = 1);
    va := 1 * 2;
    vra := 1 / 2;
    va := 1 div 2;
    va := 1 mod 2;
    vba := (va = 1) and (vb = 1);
    
    {type mismatch for cmp operator}
    vba := 1 > '2';
    {type mismatch for + and -}
    va := 1 + '2';
    {type mismatch for or}
    vba := 1 or '2';
    {type mismatch for *}
    va := 1 * '2';
    {type mismatch for /}
    va := 1 / '2';
    {type mismatch for div}
    va := 1 div '2';
    {type mismatch for mod}
    va := 1 mod '2';
    {type mismatch for and}
    vba := (va = 1) and 2;
    
    va := vb;
    va := fb;
    va := fparameter(1,2);
    va := ica;
    va := (vb + (va + vb));
    vba := not vba;
    va := -va;
    
    {undefined variable or const or function}
    va := undefined;
    {undefined function}
    va := f_undefined(2, 1);
    {type mismatch for not}
    va := not va;
    {type mismatch for -}
    vba := -vba;


end.
