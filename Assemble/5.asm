.data 0x10000000

	endl:	.asciiz	"\n"
	bp:	.word	0
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
	# read
	li $v0, 5
	syscall
	lw $t0, t0
	sw $v0, 0($t0)
	# direct jump
	j L0
	# print
	li $a0, 1111111
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
	# print
	li $a0, 2222222
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
	# print
	li $a0, 3333333
	li $v0, 1
	syscall
	la $a0, endl
	li $v0, 4
	syscall
	# direct jump
	j L1
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
	# if_false jump
	lw $t1, *t0
	lw $t1, 0($t1)
	beq $t1, $0, 1
	# if_false jump
	lw $t1, *t0
	lw $t1, 0($t1)
	beq $t1, $0, 2
	# if_false jump
	lw $t1, *t0
	lw $t1, 0($t1)
	beq $t1, $0, 3
	# if_false jump
	lw $t1, *t0
	lw $t1, 0($t1)
	beq $t1, $0, 4
L1:
	# calculation
	addi, $sp, $sp, 4
	jr $ra
