
.text
.globl main
main:

	li $t0, 2

	li $t1, 20

	li $t2, 40
	add $t1, $t1, $t2
	mul $t0, $t0, $t1

	li $t1, 4

	li $t2, 1
	sub $t1, $t1, $t2
	div $t0, $t0, $t1

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
