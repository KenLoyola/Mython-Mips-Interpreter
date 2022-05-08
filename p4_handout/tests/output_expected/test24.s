	.text
max:
	.data
 max_RA: .word 0
 max_x:  .word 0
 max_y:  .word 0
 max_z:  .word 0
	.text
		# Prolog
	sw $ra,max_RA  # save return address
        sw $a0,max_x
	sw $a1,max_y
	sw $a2,max_z
		# End Prolog

	lw $t0,max_x
	lw $t1,max_y
	sgt $t0,$t0,$t1
	beqz $t0,L0
	lw $t0,max_x
	lw $t1,max_z
	sgt $t0,$t0,$t1
	beqz $t0,L2
	
	.data
	.align 2
max_m: .word 0
	.text
	lw $t0,max_x
	sw $t0,max_m			# line 4
	b L3
L2:
	lw $t0,max_z
	sw $t0,max_m			# line 6
L3:
	b L1
L0:
	lw $t0,max_y
	lw $t1,max_z
	sgt $t0,$t0,$t1
	beqz $t0,L4
	lw $t0,max_y
	sw $t0,max_m			# line 10
	b L5
L4:
	lw $t0,max_z
	sw $t0,max_m			# line 12
L5:
L1:
	lw $t0,max_m
	li $v0,1
	move $a0,$t0
	syscall

		# Epilog
	lw $t0,max_RA
	jr $t0
		# End Epilog

	.globl main
	.data
	.align 2
main_registers: .space 48
	.text
main:

		# Procedure call: max
	sw $a0,main_registers  #saving resigers 
	sw $a1,main_registers+4
	sw $a2,main_registers+8
	sw $a3,main_registers+12
        sw $t0,main_registers+16
        sw $t1,main_registers+20
        sw $t2,main_registers+24
        sw $t3,main_registers+28
        sw $t4,main_registers+32
        sw $t5,main_registers+36
        sw $t6,main_registers+40
        sw $t7,main_registers+44

	li $t0,1
	move $a0,$t0
	li $t0,2
	move $a1,$t0
	li $t0,3
	move $a2,$t0
	jal max

	lw $a0,main_registers
	lw $a1,main_registers+4
	lw $a2,main_registers+8
	lw $a3,main_registers+12
        lw $t0,main_registers+16
        lw $t1,main_registers+20
        lw $t2,main_registers+24
        lw $t3,main_registers+28
        lw $t4,main_registers+32
        lw $t5,main_registers+36
        lw $t6,main_registers+40
        lw $t7,main_registers+44
        move $t0, $v0        
		# End Procedure call: max

                # Procedure call: max
        sw $a0,main_registers  #saving resigers 
        sw $a1,main_registers+4
        sw $a2,main_registers+8
        sw $a3,main_registers+12
        sw $t0,main_registers+16
        sw $t1,main_registers+20
        sw $t2,main_registers+24
        sw $t3,main_registers+28
        sw $t4,main_registers+32
        sw $t5,main_registers+36
        sw $t6,main_registers+40
        sw $t7,main_registers+44
        
        li $t0,3
        move $a0,$t0
        li $t0,2
        move $a1,$t0
        li $t0,1
        move $a2,$t0
        jal max
        
        lw $a0,main_registers   
        lw $a1,main_registers+4 
        lw $a2,main_registers+8 
        lw $a3,main_registers+12
        lw $t0,main_registers+16
        lw $t1,main_registers+20
        lw $t2,main_registers+24
        lw $t3,main_registers+28
        lw $t4,main_registers+32
        lw $t5,main_registers+36
        lw $t6,main_registers+40
        lw $t7,main_registers+44
        move $t0, $v0
                # End Procedure call: max


                # Procedure call: max
        sw $a0,main_registers  #saving resigers 
        sw $a1,main_registers+4
        sw $a2,main_registers+8
        sw $a3,main_registers+12
        sw $t0,main_registers+16
        sw $t1,main_registers+20
        sw $t2,main_registers+24
        sw $t3,main_registers+28
        sw $t4,main_registers+32
        sw $t5,main_registers+36
        sw $t6,main_registers+40
        sw $t7,main_registers+44
        
        li $t0,1
        move $a0,$t0
        li $t0,3
        move $a1,$t0
        li $t0,2
        move $a2,$t0
        jal max
        
        lw $a0,main_registers   
        lw $a1,main_registers+4 
        lw $a2,main_registers+8 
        lw $a3,main_registers+12
        lw $t0,main_registers+16
        lw $t1,main_registers+20
        lw $t2,main_registers+24
        lw $t3,main_registers+28
        lw $t4,main_registers+32
        lw $t5,main_registers+36
        lw $t6,main_registers+40
        lw $t7,main_registers+44
        move $t0, $v0
                # End Procedure call: max


	li $v0,10
	syscall
