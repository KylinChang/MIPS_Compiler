entry _f
sp = sp - 20
point int t0
t0 = bp - 4
point int t1
t1 = bp + 20
point int t2
t2 = bp + 16
var int t3
t3 = *t1 + *t2
point int t1
t1 = bp + 12
var int t2
t2 = t3 + *t1
point int t1
t1 = bp + 8
var int t3
t3 = t2 + *t1
*t0 = t3
sp = sp + 20
ret
entry main
sp = sp - 4
point int t0
t0 = bp - 4
arg 10
arg 20
arg 30
arg 40
call _f
point int t1
t1 = sp - 28
var int t2
t2 = *t1
*t0 = t2
point int t0
t0 = bp - 4
var int t1
t1 = *t0
println t1
sp = sp + 4
