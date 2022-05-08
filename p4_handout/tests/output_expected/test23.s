print_one:

.data
print_one_return_addr: .word, 0
.align 2
print_one_registers: .space 48
.text
	sw $ra, print_one_return_addr

	li $t0, 1

.data
print_one_num: .word 0

.text

	sw $t0, print_one_num

	lw $t0, print_one_num

	li $v0, 1
	move $a0, $t0
	syscall

print_one_exit:
	lw $ra, print_one_return_addr
	jr $ra
print_two:

.data
print_two_return_addr: .word, 0
.align 2
print_two_registers: .space 48
.text
	sw $ra, print_two_return_addr

	li $t0, 2

.data
print_two_num: .word 0

.text

	sw $t0, print_two_num

	lw $t0, print_two_num

	li $v0, 1
	move $a0, $t0
	syscall

print_two_exit:
	lw $ra, print_two_return_addr
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
	jal print_one
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
	jal print_two
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
