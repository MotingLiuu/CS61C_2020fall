.globl classify

.text
# =====================================
# COMMAND LINE ARGUMENTS
# =====================================
# Args:
#   a0 (int)        argc
#   a1 (char**)     argv
#   a1[1] (char*)   pointer to the filepath string of m0
#   a1[2] (char*)   pointer to the filepath string of m1
#   a1[3] (char*)   pointer to the filepath string of input matrix
#   a1[4] (char*)   pointer to the filepath string of output file
#   a2 (int)        silent mode, if this is 1, you should not print
#                   anything. Otherwise, you should print the
#                   classification and a newline.
# Returns:
#   a0 (int)        Classification
# Exceptions:
#   - If there are an incorrect number of command line args,
#     this function terminates the program with exit code 31
#   - If malloc fails, this function terminates the program with exit code 26
#
# Usage:
#   main.s <M0_PATH> <M1_PATH> <INPUT_PATH> <OUTPUT_PATH>
classify:
    # Prologue
    addi sp sp -32
    sw ra 0(sp)
    sw s1 4(sp)
    sw s2 8(sp)
    sw s3 12(sp)
    sw s4 16(sp)
    sw s5 20(sp)
    sw s6 24(sp)
    sw s7 28(sp)
    
    lw s1 4(a1) # pointer to the filepath string of the first matrix file mo
    lw s2 8(a1) #                                                         m1
    lw s3 12(a1) #                                                      input
    lw s4 16(a1) #                                                      output
    mv s5 a0
    mv s6 a2

    li t0 5
    bne s5 t0 argcfail
    
    
    # Read pretrained m0 and save the num of rows and columns into stack, and save matrix into memo
        # Call read_matrix
    addi sp sp -24
    mv a0 s1
    addi a1 sp 0
    addi a2 sp 4
    jal read_matrix
    mv s1 a0 # Save the address of m0 to s1
    
    
    # Read pretrained m1
        # Call read_matrix
    mv a0 s2
    addi a1 sp 8
    addi a2 sp 12
    jal read_matrix
    mv s2 a0 # Save the address of m1 to s2
    
    # Read input
        # Call read_matrix
    mv a0 s3
    addi a1 sp 16
    addi a2 sp 20
    jal read_matrix
    mv s3 a0 # Save the address of input matrix to s3
    # m0 row, column, m1 row, column, input row, column
    
    # Compute h = matmul(m0, input)
        # use malloc to allocate memo to output matrix
    lw a1 0(sp)
    lw a5 20(sp)
            # compute the size of memo to allocate
    mul t0 a1 a5
    li t1 4
    mul a0 t0 t1
    jal malloc
    beq a0 x0 mallocfail
    mv s5 a0 # Save the address of memo allocated to s5

            # call matmul to compute result matrix and save it to address s5
    mv a0 s1
    lw a1 0(sp)
    lw a2 4(sp)
    mv a3 s3
    lw a4 16(sp)
    lw a5 20(sp)
    mv a6 s5
    jal matmul

    # Compute h = relu(h)
    mv a0 s5
        # Compute the # of elements in the array
    lw t0 0(sp)
    lw t1 20(sp)
    mul a1 t0 t1
        # call relu
    jal relu

    # Compute o = matmul(m1, h)
    lw t0 8(sp)
    lw t1 20(sp)
    mul t0 t0 t1
    li t1 4
    mul a0 t0 t1
    jal malloc
    beq a0 x0 mallocfail
    mv s7 a0 # Save the address of memo allocated to s7, the output matrix
    
        # call matmul
    mv a0 s2
    lw a1 8(sp)
    lw a2 12(sp)
    mv a3 s5
    lw a4 0(sp)
    lw a5 20(sp)
    mv a6 s7
    jal matmul
    # Write output matrix o
    mv a0 s4
    mv a1 s7
    lw a2 8(sp)
    lw a3 20(sp)
    jal write_matrix
    # Compute and return argmax(o)
    mv a0 s7
    lw t0 8(sp)
    lw t1 20(sp)
    mul a1 t0 t1
    jal argmax
    mv s1 a0
    # If enabled, print argmax(o) and newline
    li t0 1
    beq t0 s6 slient
    jal print_int
    li a0 '\n'
    jal print_char
    mv a0 s1

slient:
    addi sp sp 24
    # Epilogue
    lw ra 0(sp)
    lw s1 4(sp)
    lw s2 8(sp)
    lw s3 12(sp)
    lw s4 16(sp)
    lw s5 20(sp)
    lw s6 24(sp)
    lw s7 28(sp)
    addi sp sp 32

    jr ra

mallocfail:
    li a0 26
    j exit
argcfail:
    li a0 31
    j exit
