entry _fact
sp = sp - 8
point int t0
t0 = bp + 8
var boolean t1
t1 = *t0 > 1
if_false t1 goto L0
point int t0
t0 = bp - 4
point int t1
t1 = bp + 8
var int t2
t2 = *t1 - 1
arg t2
call _fact
var int t1
t1 = *sp
*t0 = t1
goto L1
label L0
point int t0
t0 = bp - 4
*t0 = 1
label L1
sp = sp + 8
ret
entry main
sp = sp - 8
arg 10
call _fact
var int t0
t0 = *sp
println t0
sp = sp + 8
