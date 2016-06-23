entry _findmin
sp = sp - 0
point int t0
t0 = bp + 16
point int t1
t1 = bp + 12
var boolean t2
t2 = *t0 < *t1
if_false t2 goto L0
point int t0
t0 = bp + 8
point int t1
t1 = bp + 16
*t0 = *t1
goto L1
label L0
point int t0
t0 = bp + 8
point int t1
t1 = bp + 12
*t0 = *t1
label L1
sp = sp + 0
ret
entry _max
sp = sp - 8
point int t0
t0 = bp + 12
point int t1
t1 = bp + 8
var boolean t2
t2 = *t0 > *t1
if_false t2 goto L2
point int t0
t0 = bp - 8
point int t1
t1 = bp + 12
*t0 = *t1
goto L3
label L2
point int t0
t0 = bp - 8
point int t1
t1 = bp + 8
*t0 = *t1
label L3
point int t0
t0 = bp - 4
point int t1
t1 = bp - 8
*t0 = *t1
sp = sp + 8
ret
entry main
sp = sp - 4
point int t0
t0 = bp - 4
*t0 = 14
sp = sp + 4
