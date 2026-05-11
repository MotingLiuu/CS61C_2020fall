.globl matmul

.text
# =======================================================
# FUNCTION: Matrix Multiplication of 2 integer matrices
#   d = matmul(m0, m1)
# Arguments:
#   a0 (int*)  is the pointer to the start of m0
#   a1 (int)   is the # of rows (height) of m0
#   a2 (int)   is the # of columns (width) of m0
#   a3 (int*)  is the pointer to the start of m1
#   a4 (int)   is the # of rows (height) of m1
#   a5 (int)   is the # of columns (width) of m1
#   a6 (int*)  is the pointer to the the start of d
# Returns:
#   None (void), sets d = matmul(m0, m1)
# Exceptions:
#   Make sure to check in top to bottom order!
#   - If the dimensions of m0 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m1 do not make sense,
#     this function terminates the program with exit code 38
#   - If the dimensions of m0 and m1 don't match,
#     this function terminates the program with exit code 38
# =======================================================
matmul:

    # Error checks
    bge x0 a1 malformed
    bge x0 a2 malformed
    bge x0 a4 malformed
    bge x0 a5 malformed

    bne a2 a4 malformed
    # Prologue
    addi sp sp -44
    sw ra 0(sp)
    sw s1 4(sp)
    sw s2 8(sp)
    sw s3 12(sp)
    sw s4 16(sp)
    sw s5 20(sp)
    sw s6 24(sp)
    sw s7 28(sp)
    sw s8 32(sp)
    sw s9 36(sp)
    sw s10 40(sp)
    
    mv s1 a0
    mv s2 a1
    mv s3 a2
    mv s4 a3
    mv s5 a4
    mv s6 a5
    mv s7 a6
    li s9 0

outer_loop_start:

    mv s10 s4
    li s8 0
    bge s9 s2 outer_loop_end
    j inner_loop_start

inner_loop_start:
    bge s8 s6 inner_loop_end
    mv a0 s1
    mv a1 s10
    mv a2 s3
    li a3 1
    mv a4 s6
    jal dot  # jump to dot and save position to ra
    sw a0 0(s7)
    addi s7 s7 4
    addi s10 s10 4
    addi s8 s8 1
    j inner_loop_start

inner_loop_end:
    li t0 4
    mul t0 t0 s3
    add s1 s1 t0
    addi s9 s9 1
    j outer_loop_start

outer_loop_end:
    # Epilogue
    lw ra 0(sp)
    lw s1 4(sp)
    lw s2 8(sp)
    lw s3 12(sp)
    lw s4 16(sp)
    lw s5 20(sp)
    lw s6 24(sp)
    lw s7 28(sp)
    lw s8 32(sp)
    lw s9 36(sp)
    lw s10 40(sp)

    addi sp sp 44

    jr ra

malformed:
    li a0 38