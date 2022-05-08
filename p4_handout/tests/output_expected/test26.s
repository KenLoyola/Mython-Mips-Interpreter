	.text
decrement:
	.data
 decrement_RA: .word 0
 decrement_x:  .word 0
	.text
		# Prolog
	sw $ra,decrement_RA  # save return address
        sw $a0,decrement_x
		# End Prolog

	lw $t0,decrement_x
	li $t1,1
	sub $t0,$t0,$t1
	move $v0,$t0

		# Epilog
	lw $t0,decrement_RA
	jr $t0
		# End Epilog
	

        .text
increment:
        .data
 increment_RA: .word 0
 increment_x:  .word 0
        .text
                # Prolog
        sw $ra,increment_RA  # save return address
        sw $a0,increment_x
                # End Prolog

        lw $t0,increment_x
        li $t1,1  
        add $t0,$t0,$t1
        move $v0,$t0
                
                # Epilog   
        lw $t0,increment_RA
        jr $t0
                # End Epilog
        
        .text
compute:
        .data
 compute_RA: .word 0
 compute_registers: .space 48
 compute_x:  .word 0
 compute_y:  .word 0
        .text
                # Prolog
        sw $ra,compute_RA  # save return address
        sw $a0,compute_x
	sw $a1,compute_y
                # End Prolog

	.data
	.align 0
compute_sum: .word 0
	.text
	lw $t0,compute_y
	sw $t0,compute_sum			# line 11
L0:
	lw $t0,compute_x
	li $t1,0
	sgt $t0,$t0,$t1
	beqz $t0,L1
				# call line 12
	sw $a0,compute_registers
	sw $a1,compute_registers+4
	sw $a2,compute_registers+8
	sw $a3,compute_registers+12
	sw $t0,compute_registers+16
	sw $t1,compute_registers+20
	sw $t2,compute_registers+24
	sw $t3,compute_registers+28
	sw $t4,compute_registers+32
	sw $t5,compute_registers+36
	sw $t6,compute_registers+40
        sw $t7,compute_registers+44

	lw $t1,compute_sum
	move $a0,$t1
	jal increment

        lw $a0,compute_registers
        lw $a1,compute_registers+4
        lw $a2,compute_registers+8
        lw $a3,compute_registers+12
        lw $t0,compute_registers+16
        lw $t1,compute_registers+20
        lw $t2,compute_registers+24
        lw $t3,compute_registers+28
        lw $t4,compute_registers+32
        lw $t5,compute_registers+36
        lw $t6,compute_registers+40
        lw $t7,compute_registers+44

	move $t1,$v0
	sw $t1,compute_sum			

				# call line 13

        sw $a0,compute_registers
        sw $a1,compute_registers+4
        sw $a2,compute_registers+8
        sw $a3,compute_registers+12
        sw $t0,compute_registers+16
        sw $t1,compute_registers+20
        sw $t2,compute_registers+24
        sw $t3,compute_registers+28
        sw $t4,compute_registers+32
        sw $t5,compute_registers+36
        sw $t6,compute_registers+40
        sw $t7,compute_registers+44
        
	lw $t1,compute_x
	move $a0,$t1
	jal decrement

        lw $a0,compute_registers
        lw $a1,compute_registers+4
        lw $a2,compute_registers+8
        lw $a3,compute_registers+12
        lw $t0,compute_registers+16
        lw $t1,compute_registers+20
        lw $t2,compute_registers+24
        lw $t3,compute_registers+28
        lw $t4,compute_registers+32
        lw $t5,compute_registers+36
        lw $t6,compute_registers+40
        lw $t7,compute_registers+44
        
	move $t1,$v0
	sw $t1,compute_x

	b L0
L1:	lw $t0,compute_sum
	move $v0,$t0
	
                
                # Epilog   
        lw $t0,compute_RA
        jr $t0
                # End Epilog
        
	.globl main
	.data
	.align 2
main_registers: .space 48
	.text
main:

                # Procedure call: compute
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

		# Procedure call: compute
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

	li $t0,10
	move $a0,$t0
	li $t0,20
	move $a1,$t0
	jal compute

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
		# End Procedure call: compute
	move $a0,$t0

                # Procedure call: compute
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
        jal compute
        
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
                # End Procedure call: compute
	move $a1, $t0

        jal compute
        
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
                # End Procedure call: compute
	li $v0,1
	move $a0,$t0
	syscall

	li $v0,10
	syscall
