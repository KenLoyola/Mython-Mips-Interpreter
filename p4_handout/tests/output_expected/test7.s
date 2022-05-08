
.text
.globl main
main:

	li $t0, 1

	li $t1, 2
	seq $t0, $t0, $t1

	li $v0, 1
	move $a0, $t0
	syscall

	li $t0, 1

	li $t1, 2
	sne $t0, $t0, $t1

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
