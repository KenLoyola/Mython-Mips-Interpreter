
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

	li $t1, 3
	slt $t0, $t0, $t1
	beqz $t0, L1

	lw $t0, global_x

	li $v0, 1
	move $a0, $t0
	syscall

.data
str0: .asciiz "\n"

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall

	lw $t0, global_x

	li $t1, 1
	add $t0, $t0, $t1

	sw $t0, global_x
j L0
L1:

	lw $t0, global_x

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
