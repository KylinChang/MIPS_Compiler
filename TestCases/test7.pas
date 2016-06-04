program test7;
var
  n,i:byte;
  a,b,c:longint;
begin
  readln(n);
  case n of
    1: writeln(0);
    2: writeln(1);
  else begin
    a:=0;b:=1;
    for i:=3 to n do begin
      c:=(i-1)*(a+b);
      a:=b;b:=c;
    end;
    writeln(c);
  end;
  end;
end.