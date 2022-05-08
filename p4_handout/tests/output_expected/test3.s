
.text
.globl main
main:

.data
global_x: .word 0

.text
	li $v0,5
	syscall
	sw $v0,global_x

	li $t0, 1

	lw $t1, global_x

	li $t2, 2
	mul $t1, $t1, $t2
	sub $t0, $t0, $t1

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
