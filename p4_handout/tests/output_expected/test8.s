
.text
.globl main
main:

	li $t0, 1

	li $t1, 1
	seq $t0, $t0, $t1
	beqz $t0, L0

.data
str0: .asciiz "yes"

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall
L0:

	li $t0, 1

	li $t1, 2
	seq $t0, $t0, $t1
	beqz $t0, L1

.data
str1: .asciiz "no"

.text
	la $t0, str1

	li $v0, 4
	move $a0, $t0
	syscall
L1:

	li $v0, 10
	syscall
