program test7;
var
  n,i:byte;
  a,b,c:longint;
begin
  readln(n);
  case n of
    1: writeln(0);
    2: writeln(1);
  end;

  1:
    a := 1;
    b := 2;
  goto 1;
end.