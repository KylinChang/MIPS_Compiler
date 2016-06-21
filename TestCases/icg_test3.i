entry _f
sp = sp - 12
point int t0
t0 = bp - 4
*t0 = 1
point int t0
t0 = bp - 8
*t0 = 1
var int t1
t1 = -1
label L0
var int t2
t2 = *t0 != 10
if_false t2 goto L1
point int t3
t3 = bp - 4
point int t4
t4 = bp - 4
point int t5
t5 = bp - 8
var int t6
t6 = *t4 * *t5
*t3 = t6
*t0 = *t0 + t1
goto L0
label L1
label L2
var int t2
t2 = *t0 == 10
if_false t2 goto L3
point int t3
t3 = bp - 4
point int t4
t4 = bp - 4
point int t5
t5 = bp - 8
var int t6
t6 = *t4 * *t5
*t3 = t6
*t0 = *t0 + t1
goto L2
label L3
point int t2
t2 = bp - 4
point int t3
t3 = bp - 4
point int t4
t4 = bp + 8
var int t5
t5 = *t3 + *t4
*t2 = t5
sp = sp + 12
ret
entry main
sp = sp - 12
point int t2
t2 = bp - 8
arg 10
call _f
var int t3
t3 = *sp
*t2 = t3
point int t2
t2 = bp - 8
var int t3
t3 = *t2
println t3
point int t2
t2 = bp - 4
arg *t2
call _read
point int t2
t2 = bp - 4
var int t3
t3 = *t2
println t3
sp = sp + 12
