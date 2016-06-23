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
	li $t2, 4
	sub $t1, $t1, $t2
	sw $t1, t0
	# read
	li $v0, 5
	syscall
	lw $t0, t0
	sw $v0, 0($t0)
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t0
	# assign
	li $t0, 1
	lw $t1, t0
	sw $t0, 0($t1)
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t0
	# assign
	li $t0, 1
	mtc1, $t0, $f0
	cvt.s.w $f0, $f0
	cvt.d.s $f0, $f0
	lw $t0, t0
	s.d $f0, 0($t0)
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t0
	# calculation
	lw $t1, bp
	li $t2, 4
	sub $t1, $t1, $t2
	sw $t1, t1
	# assign
	li $t0, 1
	lw $t1, t0
	sw $t0, 0($t1)
	# stack
	addi $sp, $sp, -4
	sw $sp, t2
	# assign
	lw $t1, t2
	sw $t0, 0($t1)
L0:
	# stack
	addi $sp, $sp, -4
	sw $sp, t3
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	lw $t3, t1
	lw $t2, 0($t3)
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	or $t3, $t4, $t5
	lw $t2, t3
	sw $t3, 0($t2)
	# if_false jump
	lw $t1, t3
	lw $t1, 0($t1)
	beq $t1, $0, L1
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t4
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t5
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t6
	# stack
	addi $sp, $sp, -4
	sw $sp, t7
	# calculation
	lw $t3, t5
	lw $t1, 0($t3)
	lw $t3, t6
	lw $t2, 0($t3)
	mul $t1, $t1, $t2
	lw $t3, t7
	sw $t1, 0($t3)
	# assign
	lw $t0, t7
	lw $t0, 0($t0)
	lw $t1, t4
	sw $t0, 0($t1)
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t4
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t5
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t6
	# stack
	addi $sp, $sp, -8
	sw $sp, t7
	# calculation
	li.d $f0, 1.0
	lw $t3, t6
	lw $t2, 0($t3)
	mtc1 $t2, $f2
	cvt.s.w $f2, $f2
	cvt.d.s $f2, $f2
	div.d $f4, $f0, $f2
	lw $t3, t7
	s.d $f4, 0($t3)
	# stack
	addi $sp, $sp, -8
	sw $sp, t6
	# calculation
	lw $t3, t5
	l.d $f0, 0($t3)
	lw $t3, t7
	l.d $f2, 0($t3)
	add.d $f4, $f0, $f2
	lw $t3, t6
	s.d $f4, 0($t3)
	# assign
	lw $t0, t6
	l.d $f0, 0($t0)
	lw $t0, t4
	s.d $f0, 0($t0)
	# calculation
	lw $t3, t0
	lw $t1, 0($t3)
	lw $t3, t2
	lw $t2, 0($t3)
	add $t1, $t1, $t2
	lw $t3, t0
	sw $t1, 0($t3)
	# direct jump
	j L0
L1:
L2:
	# stack
	addi $sp, $sp, -4
	sw $sp, t3
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	lw $t3, t1
	lw $t2, 0($t3)
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	nor $t3, $t4, $t5
	andi $t3, $t3, 1
	lw $t2, t3
	sw $t3, 0($t2)
	# if_false jump
	lw $t1, t3
	lw $t1, 0($t1)
	beq $t1, $0, L3
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t4
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t5
	# calculation
	lw $t1, bp
	li $t2, 12
	sub $t1, $t1, $t2
	sw $t1, t6
	# stack
	addi $sp, $sp, -4
	sw $sp, t7
	# calculation
	lw $t3, t5
	lw $t1, 0($t3)
	lw $t3, t6
	lw $t2, 0($t3)
	mul $t1, $t1, $t2
	lw $t3, t7
	sw $t1, 0($t3)
	# assign
	lw $t0, t7
	lw $t0, 0($t0)
	lw $t1, t4
	sw $t0, 0($t1)
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t4
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t5
	# calculation
	lw $t1, bp
	li $t2, 8
	sub $t1, $t1, $t2
	sw $t1, t6
	# stack
	addi $sp, $sp, -8
	sw $sp, t7
	# calculation
	li.d $f0, 1.0
	lw $t3, t6
	lw $t2, 0($t3)
	mtc1 $t2, $f2
	cvt.s.w $f2, $f2
	cvt.d.s $f2, $f2
	div.d $f4, $f0, $f2
	lw $t3, t7
	s.d $f4, 0($t3)
	# stack
	addi $sp, $sp, -8
	sw $sp, t6
	# calculation
	lw $t3, t5
	l.d $f0, 0($t3)
	lw $t3, t7
	l.d $f2, 0($t3)
	add.d $f4, $f0, $f2
	lw $t3, t6
	s.d $f4, 0($t3)
	# assign
	lw $t0, t6
	l.d $f0, 0($t0)
	lw $t0, t4
	s.d $f0, 0($t0)
	# calculation
	lw $t3, t0
	lw $t1, 0($t3)
	lw $t3, t2
	lw $t2, 0($t3)
	add $t1, $t1, $t2
	lw $t3, t0
	sw $t1, 0($t3)
	# direct jump
	j L2
L3:
	# calculation
	lw $t1, bp
	li $t2, 20
	sub $t1, $t1, $t2
	sw $t1, t1
	# stack
	addi $sp, $sp, -8
	sw $sp, t3
	# assign
	lw $t0, t1
	l.d $f0, 0($t0)
	lw $t0, t3
	s.d $f0, 0($t0)
	# print
	lw $t0, t3
	l.d $f12, 0($t0)
	li $v0, 3
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# calculation
	addi, $sp, $sp, 20
	jr $ra
