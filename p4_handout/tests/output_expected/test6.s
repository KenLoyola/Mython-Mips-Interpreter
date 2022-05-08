
.text
.globl main
main:

.data
str0: .asciiz "Hello World!"

.text
	la $t0, str0

.data
global_s: .word 0

.text

	sw $t0, global_s

	lw $t0, global_s

	li $v0, 4
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
