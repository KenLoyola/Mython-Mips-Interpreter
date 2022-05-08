
.text
.globl main
main:

	li $t0, 440

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
