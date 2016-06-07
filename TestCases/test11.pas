program test4;

var 
x:integer;
y: longint;
z: integer;
h: char;	

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
	x:=1;
y:= 32000;
h:='a';
for x:=y to 60000 do begin
	h := 'a';
end;


end.
