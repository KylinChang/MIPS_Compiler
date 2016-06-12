entry _findmin
	t0 = bp + 4
	t1 = bp + 0
	t2 = *t0 < *t1
	if_false t2 goto L0
	t0 = bp - 4
	t1 = bp + 4
	*t0 = *t1
	goto L1
	label L0
	t0 = bp - 4
	t1 = bp + 0
	*t0 = *t1
	label L1
	ret
t0 = bp - 8
t1 = *t0 > 1
if_false t1 goto L2
t0 = bp - 8
*t0 = 1
goto L3
label L2
t0 = bp - 8
*t0 = 2
label L3
goto L4
Label L6
t0 = bp - 8
*t0 = 0
goto L5
Label L7
t1 = bp - 8
*t1 = 1
goto L5
label L4
if_false 1 != 1 then goto L6
if_false 1 != 2 then goto L7
label L5
label L8
if_false 1 goto L9
t2 = bp - 8
t3 = bp - 8
arg *t3
call sqrt
t3 = *sp
*t2 = t3
goto L8
label L9
t2 = bp - 12
t3 = 1 * 10
t4 = 1000 DIV 10
*t2 = t3
t5 = -1
label L10
t6 = *t2 != t4
if_false t6 goto L11
t7 = bp - 8
t8 = bp - 12
t9 = *t8 DIV 2
t8 = t9 % 2
*t7 = t8
*t2 = *t2 + t5
goto L10
label L11
label L12
t6 = *t2 == t4
if_false t6 goto L13
t7 = bp - 8
t8 = bp - 12
t9 = *t8 DIV 2
t8 = t9 % 2
*t7 = t8
*t2 = *t2 + t5
goto L12
label L13
t3 = bp - 12
*t3 = 2
t4 = -1
label L14
t6 = *t3 != 1
if_false t6 goto L15
t7 = bp - 8
*t7 = 1
*t3 = *t3 + t4
goto L14
label L15
label L16
t6 = *t3 == 1
if_false t6 goto L17
t7 = bp - 8
*t7 = 1
*t3 = *t3 + t4
goto L16
label L17
label L18
t6 = bp - 8
*t6 = 1
t6 = bp - 8
t7 = *t6 > 1
if_false t7 goto L18
