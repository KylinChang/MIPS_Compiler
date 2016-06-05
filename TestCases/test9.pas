program test9;
var
    x:real;
    y:byte;
    z:integer;
    v: array[1..2,2..3] of integer;
    tt : array['a'..'z'] of integer;
    kk : array[1..2] of array[2..3] of integer;
begin
    y := 2;
    z:=1;
    x := y+z;

    writeln(x);
    v[1,2] := 1;
    kk[1][2] := 1;
    writeln(v[1,2]);
    writeln(kk[1][2]);
end.