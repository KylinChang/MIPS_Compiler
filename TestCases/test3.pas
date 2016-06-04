program test3;

var x:integer;

procedure findMin(x, y:integer; var m:integer);
begin
	if x<y then
		m:=x
	else
		m:=y;
end;

begin
	x:=1;
	findMin(1,2,x);
end.