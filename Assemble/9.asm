.data 0x10000000

	endl:	.asciiz	"\n"
	bp:	.word	0
	offset:	.word	0
	t0:	.word	0
	t1:	.word	0
	t2:	.word	0
	t3:	.word	0
	t4:	.word	0
	t5:	.word	0
	t6:	.word	0
	t7:	.word	0
	t8:	.word	0
	t9:	.word	0
	t10:	.word	0
	t11:	.word	0
	t12:	.word	0
	t13:	.word	0
	t14:	.word	0
	t15:	.word	0
	t16:	.word	0
	t17:	.word	0
	t18:	.word	0
	t19:	.word	0

.text

main:
	sw $sp, bp
	# calculation
	addi, $sp, $sp, -20
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t0
	# calculation
	lw $t1, t0
	li $t2, 4
	add $t1, $t1, $t2
	sw $t1, t1
	# assign
	li.s $f0, 123.456001
	cvt.d.s, $f0, $f0
	lw $t0, t1
	s.d $f0, 0($t0)
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t0
	# calculation
	lw $t1, t0
	li $t2, 0
	add $t1, $t1, $t2
	sw $t1, t1
	# assign
	li $t0, 777
	lw $t1, t1
	sw $t0, 0($t1)
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t0
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t1
	# calculation
	lw $t1, t1
	li $t2, 4
	add $t1, $t1, $t2
	sw $t1, t2
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t1
	# calculation
	lw $t1, t1
	li $t2, 0
	add $t1, $t1, $t2
	sw $t1, t3
	# stack
	addi $sp, $sp, -8
	sw $sp, t1
	# calculation
	lw $t3, t2
	l.d $f0, 0($t3)
	lw $t3, t3
	lw $t2, 0($t3)
	mtc1 $t2, $f2
	cvt.s.w $f2, $f2
	cvt.d.s $f2, $f2
	add.d $f4, $f0, $f2
	lw $t3, t1
	s.d $f4, 0($t3)
	# assign
	lw $t0, t1
	l.d $f0, 0($t0)
	lw $t0, t0
	s.d $f0, 0($t0)
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t0
	# stack
	addi $sp, $sp, -8
	sw $sp, t1
	# assign
	lw $t0, t0
	l.d $f0, 0($t0)
	lw $t0, t1
	s.d $f0, 0($t0)
	# print
	lw $t0, t1
	l.d $f12, 0($t0)
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# calculation
	addi, $sp, $sp, 20
	jr $ra
