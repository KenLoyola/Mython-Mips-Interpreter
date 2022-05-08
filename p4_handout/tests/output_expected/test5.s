
.text
.globl main
main:

.data
str0: .asciiz "May the force be with you."

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
