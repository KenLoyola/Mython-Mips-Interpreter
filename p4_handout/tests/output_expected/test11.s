
.text
.globl main
main:

.data
str0: .asciiz "please enter a positive int <=12: "

.text
	la $t0, str0

.data
global_prompt: .word 0

.text

	sw $t0, global_prompt

	lw $t0, global_prompt

	li $v0, 4
	move $a0, $t0
	syscall

.data
global_n: .word 0

.text
	li $v0,5
	syscall
	sw $v0,global_n

	li $t0, 1

.data
global_i: .word 0

.text

	sw $t0, global_i

	li $t0, 1

.data
global_ans: .word 0

.text

	sw $t0, global_ans

	lw $t0, global_i

	lw $t1, global_n
	sle $t0, $t0, $t1

.data
global_b: .word 0

.text

	sw $t0, global_b
L0:

	lw $t0, global_b
	beqz $t0, L1

	lw $t0, global_ans

	lw $t1, global_i
	mul $t0, $t0, $t1

	sw $t0, global_ans

	lw $t0, global_i

	li $t1, 1
	add $t0, $t0, $t1

	sw $t0, global_i

	lw $t0, global_i

	lw $t1, global_n
	sle $t0, $t0, $t1

	sw $t0, global_b
j L0
L1:

	lw $t0, global_ans

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 10
	syscall
