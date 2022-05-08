
.text
.globl main
main:

.data
str0: .asciiz "Input a number:"

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall

.data
global_x: .word 0

.text
	li $v0,5
	syscall
	sw $v0,global_x

	lw $t0, global_x

	li $t1, 10
	sge $t0, $t0, $t1
	beqz $t0, L0

.data
str1: .asciiz ">=10"

.text
	la $t0, str1

	li $v0, 4
	move $a0, $t0
	syscall
j L1
L0:

.data
str2: .asciiz "<10"

.text
	la $t0, str2

	li $v0, 4
	move $a0, $t0
	syscall
L1:

	li $v0, 10
	syscall
