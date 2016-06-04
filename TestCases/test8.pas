program Area;
const pi=003.14159;
const p=nil;
var s,r:real;
var a,_b:longint;
var c:string;
var d:string;
var e:integer;
var f:cardinal;
var g:dword;
var h:string;
label label1;
begin
	{* readln(r); *}
	{ }
	r:=37.8E6;
	s:=pi*sqr(r);
	a:=1;
	_b:=maxlongint;
	a:=a and (_b*2);
	writeln('s =',s);
	writeln('a =',a);
	writeln('_b =',_b);
	c:='';
	writeln('c=','char\*~!@#$%^&*()_+-={}[]|:;"<>,.?/''');
	d:='ABC'+'DEF';
	writeln('d=',d);
	e:=0256;
	writeln('e=',e);
	f:=$010;
	writeln('f=',f);
	g:=not 1;
	h:='aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaAAAAA';
	writeln('h=',h);
label1:
	goto label1;
end.
