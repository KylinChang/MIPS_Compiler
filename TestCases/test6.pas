program test6;
var
m,n:integer;

function com(x,y:integer):real;
	function fac(a:integer):real;
	var
	b:integer;
	fa:real;
	begin
	fa:=1;
	for b:=1 to a do
		fa:=fa*b;
	fac:=fa;
	end;
begin
	com:=fac(x)/fac(y)/fac(x-y);
end;

begin
	readln(m,n);
	writeln(com(m,n));
end.