
.text
.globl main
main:

	li $t0, 1

.data
global_x: .word 0

.text

	sw $t0, global_x
L0:

	lw $t0, global_x

	li $t1, 10
	slt $t0, $t0, $t1
	beqz $t0, L1

	lw $t0, global_x

	li $v0, 1
	move $a0, $t0
	syscall

	lw $t0, global_x

	li $t1, 2
	div $t0, $t0, $t1

.data
global_y: .word 0

.text

	sw $t0, global_y

	lw $t0, global_y

	li $t1, 2
	mul $t0, $t0, $t1

	lw $t1, global_x
	seq $t0, $t0, $t1
	beqz $t0, L2

.data
str0: .asciiz ":even\n"

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall
j L3
L2:

.data
str1: .asciiz ":odd\n"

.text
	la $t0, str1

	li $v0, 4
	move $a0, $t0
	syscall
L3:

	lw $t0, global_x

	li $t1, 1
	add $t0, $t0, $t1

	sw $t0, global_x
j L0
L1:

	li $v0, 10
	syscall
