sum_squares:
    beq x0 a0 zero_case
    mv t0 a0
    
    addi sp sp -12
    sw a1 0(sp)
    sw t0 4(sp)
    sw ra 8(sp)
    jal ra square
    
    lw a1 0(sp)
    lw t0 4(sp)
    lw ra 8(sp)
    addi sp sp 12

    add a1 a0 a1
    addi a0 t0 -1

    addi sp sp -4
    sw ra 0(sp)
    jal ra sum_squares
    lw 0(sp)
    addi sp sp 4
    jr ra

zero_case:
    mv a0 a1
    jr ra
