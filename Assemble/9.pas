program test9;
var
    a:record
        a:real;
        b:integer;
    end;

    sum:real;

begin
    a.a := 123.456;
    a.b := 777;
    sum := a.a + a.b;
    writeln(sum);
end.
