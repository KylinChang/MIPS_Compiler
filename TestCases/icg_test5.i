entry _f
sp = sp - 40
point double t0
t0 = bp - 8
point double t1
t1 = bp + 32
point double t2
t2 = bp + 24
var double t3
t3 = *t1 + *t2
point double t1
t1 = bp + 16
var double t2
t2 = t3 + *t1
point double t1
t1 = bp + 8
var double t3
t3 = t2 + *t1
*t0 = t3
sp = sp + 40
ret
entry main
sp = sp - 8
point double t0
t0 = bp - 8
arg 10
arg 20
arg 30
arg 40
call _f
point double t1
t1 = sp - 48
var double t2
t2 = *t1
*t0 = t2
point double t0
t0 = bp - 8
var double t1
t1 = *t0
println t1
goto L0
Label L2
point double t0
t0 = bp - 8
*t0 = 0
goto L1
Label L3
point double t1
t1 = bp - 8
*t1 = 0.1
goto L1
label L0
if 1 == 1 then goto L2
if 1 == 2 then goto L3
label L1
sp = sp + 8
