
.text
.globl main
main:

	li $t0, 0

.data
global_x: .word 0

.text

	sw $t0, global_x

	lw $t0, global_x

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
