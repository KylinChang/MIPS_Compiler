entry _f
sp = sp - 4
point int t0
t0 = bp - 4
point int t1
t1 = bp + 8
arg *t1
call _f2
point int t1
t1 = sp - 12
var int t2
t2 = *t1
point int t1
t1 = bp + 8
var int t3
t3 = t2 * *t1
*t0 = t3
sp = sp + 4
ret
entry _f1
sp = sp - 4
point int t0
t0 = bp - 4
point int t1
t1 = bp + 8
var int t2
t2 = *t1 * 3
*t0 = t2
sp = sp + 4
ret
entry _f2
sp = sp - 4
point int t0
t0 = bp - 4
point int t1
t1 = bp + 8
arg *t1
call _f1
point int t1
t1 = sp - 12
var int t2
t2 = *t1
point int t1
t1 = bp + 8
var int t3
t3 = t2 + *t1
*t0 = t3
sp = sp + 4
ret
entry main
sp = sp - 4
point int t0
t0 = bp - 4
*t0 = 2
point int t0
t0 = bp - 4
arg *t0
call _f
point int t0
t0 = sp - 12
var int t1
t1 = *t0
println t1
sp = sp + 4
