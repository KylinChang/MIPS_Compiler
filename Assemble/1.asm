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
	addi, $sp, $sp, -4
	# calculation
	lw $t1, bp
	li $t2, 4
	sub $t1, $t1, $t2
	sw $t1, t0
	# stack
	addi $sp, $sp, -4
	sw $sp, t1
	# assign
	lw $t0, t0
	lw $t0, 0($t0)
	lw $t1, t1
	sw $t0, 0($t1)
	# print
	lw $t0, t1
	lw $a0, 0($t0)
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# calculation
	addi, $sp, $sp, 4
	jr $ra
