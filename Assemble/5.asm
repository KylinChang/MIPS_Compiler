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
	# assign
	li $t0, 3
	lw $t1, t0
	sw $t0, 0($t1)
	# calculation
	lw $t1, bp
	li $t2, 4
	sub $t1, $t1, $t2
	sw $t1, t0
	# direct jump
	j L0
L2:
	# print
	li $a0, 1111111
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
L3:
	# print
	li $a0, 2222222
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
L4:
	# print
	li $a0, 3333333
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
L5:
	# print
	li $a0, 4444444
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
L0:
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	li $t2, 1
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	or $t3, $t4, $t5
	add $t7, $t3, $0
	# if_false jump
	add $t1, $t7, $0
	beq $t1, $0, L2
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	li $t2, 2
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	or $t3, $t4, $t5
	add $t7, $t3, $0
	# if_false jump
	add $t1, $t7, $0
	beq $t1, $0, L3
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	li $t2, 3
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	or $t3, $t4, $t5
	add $t7, $t3, $0
	# if_false jump
	add $t1, $t7, $0
	beq $t1, $0, L4
	# compare
	lw $t3, t0
	lw $t1, 0($t3)
	li $t2, 4
	slt $t4, $t1, $t2
	slt $t5, $t2, $t1
	or $t3, $t4, $t5
	add $t7, $t3, $0
	# if_false jump
	add $t1, $t7, $0
	beq $t1, $0, L5
L1:
	# calculation
	addi, $sp, $sp, 4
	jr $ra
