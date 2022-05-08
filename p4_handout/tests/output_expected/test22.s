foo:

.data
foo_return_addr: .word, 0
.align 2
foo_registers: .space 48
.text
	sw $ra, foo_return_addr

.data
str0: .asciiz "foo\n"

.text
	la $t0, str0

	li $v0, 4
	move $a0, $t0
	syscall

foo_exit:
	lw $ra, foo_return_addr
	jr $ra
bar:

.data
bar_return_addr: .word, 0
.align 2
bar_registers: .space 48
.text
	sw $ra, bar_return_addr
	sw $t0, bar_registers
	sw $t1, bar_registers+4
	sw $t2, bar_registers+8
	sw $t3, bar_registers+12
	sw $t4, bar_registers+16
	sw $t5, bar_registers+20
	sw $t6, bar_registers+24
	sw $t7, bar_registers+28
	sw $a0, bar_registers+32
	sw $a1, bar_registers+36
	sw $a2, bar_registers+40
	sw $a3, bar_registers+44
	jal foo
	lw $t0, bar_registers
	lw $t1, bar_registers+4
	lw $t2, bar_registers+8
	lw $t3, bar_registers+12
	lw $t4, bar_registers+16
	lw $t5, bar_registers+20
	lw $t6, bar_registers+24
	lw $t7, bar_registers+28
	lw $a0, bar_registers+32
	lw $a1, bar_registers+36
	lw $a2, bar_registers+40
	lw $a3, bar_registers+44
	move $t0, $v0

.data
str1: .asciiz "bar\n"

.text
	la $t0, str1

	li $v0, 4
	move $a0, $t0
	syscall

bar_exit:
	lw $ra, bar_return_addr
	jr $ra

.text
.globl main
main:

.data
.align 2
global_registers: .space 48
.text
	sw $t0, global_registers
	sw $t1, global_registers+4
	sw $t2, global_registers+8
	sw $t3, global_registers+12
	sw $t4, global_registers+16
	sw $t5, global_registers+20
	sw $t6, global_registers+24
	sw $t7, global_registers+28
	sw $a0, global_registers+32
	sw $a1, global_registers+36
	sw $a2, global_registers+40
	sw $a3, global_registers+44
	jal bar
	lw $t0, global_registers
	lw $t1, global_registers+4
	lw $t2, global_registers+8
	lw $t3, global_registers+12
	lw $t4, global_registers+16
	lw $t5, global_registers+20
	lw $t6, global_registers+24
	lw $t7, global_registers+28
	lw $a0, global_registers+32
	lw $a1, global_registers+36
	lw $a2, global_registers+40
	lw $a3, global_registers+44
	move $t0, $v0

	li $v0, 10
	syscall
