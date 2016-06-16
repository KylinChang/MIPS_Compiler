entry _findmin
sp = sp - 8
point int t0
t0 = bp + 4
point int t1
t1 = bp + 0
var boolean t2
t2 = *t0 < *t1
if_false t2 goto L0
point int t0
t0 = bp - 4
point int t1
t1 = bp + 4
*t0 = *t1
goto L1
label L0
point int t0
t0 = bp - 4
point int t1
t1 = bp + 0
*t0 = *t1
label L1
sp = sp + 12
ret
entry main
point double t0
t0 = bp - 8
var boolean t1
t1 = *t0 > 1
if_false t1 goto L2
point double t0
t0 = bp - 8
*t0 = 1
goto L3
label L2
point double t0
t0 = bp - 8
*t0 = 2
label L3
goto L4
Label L6
point double t0
t0 = bp - 8
*t0 = 0
goto L5
Label L7
point double t1
t1 = bp - 8
*t1 = 1
goto L5
label L4
if_false 1 != 1 then goto L6
if_false 1 != 2 then goto L7
label L5
label L8
if_false 1 goto L9
point double t2
t2 = bp - 8
point double t3
t3 = bp - 8
arg *t3
call sqrt
var double t3
t3 = *sp
*t2 = t3
goto L8
label L9
point int t2
t2 = bp - 12
var int t3
t3 = 1 * 10
var int t4
t4 = 1000 DIV 10
*t2 = t3
var int t5
t5 = -1
label L10
var int t6
t6 = *t2 != t4
if_false t6 goto L11
point double t7
t7 = bp - 8
point int t8
t8 = bp - 12
var int t9
t9 = *t8 DIV 2
var int t8
t8 = t9 % 2
*t7 = t8
*t2 = *t2 + t5
goto L10
label L11
label L12
var int t6
t6 = *t2 == t4
if_false t6 goto L13
point double t7
t7 = bp - 8
point int t8
t8 = bp - 12
var int t9
t9 = *t8 DIV 2
var int t8
t8 = t9 % 2
*t7 = t8
*t2 = *t2 + t5
goto L12
label L13
point int t3
t3 = bp - 12
*t3 = 2
var int t4
t4 = -1
label L14
var int t6
t6 = *t3 != 1
if_false t6 goto L15
point double t7
t7 = bp - 8
*t7 = 1
*t3 = *t3 + t4
goto L14
label L15
label L16
var int t6
t6 = *t3 == 1
if_false t6 goto L17
point double t7
t7 = bp - 8
*t7 = 1
*t3 = *t3 + t4
goto L16
label L17
label L18
point double t6
t6 = bp - 8
*t6 = 1
point double t6
t6 = bp - 8
var boolean t7
t7 = *t6 > 1
if_false t7 goto L18
