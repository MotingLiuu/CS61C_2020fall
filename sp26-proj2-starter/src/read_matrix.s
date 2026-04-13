.globl read_matrix

.text
# ==============================================================================
# FUNCTION: Allocates memory and reads in a binary file as a matrix of integers
#
# FILE FORMAT:
#   The first 8 bytes are two 4 byte ints representing the # of rows and columns
#   in the matrix. Every 4 bytes afterwards is an element of the matrix in
#   row-major order.
# Arguments:
#   a0 (char*) is the pointer to string representing the filename
#   a1 (int*)  is a pointer to an integer, we will set it to the number of rows
#   a2 (int*)  is a pointer to an integer, we will set it to the number of columns
# Returns:
#   a0 (int*)  is the pointer to the matrix in memory
# Exceptions:
#   - If malloc returns an error,
#     this function terminates the program with error code 26
#   - If you receive an fopen error or eof,
#     this function terminates the program with error code 27
#   - If you receive an fclose error or eof,
#     this function terminates the program with error code 28
#   - If you receive an fread error or eof,
#     this function terminates the program with error code 29
# ==============================================================================
read_matrix:

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
    
    # open the matrix file for reading
        # save the address to edit after reading of the matrix
    mv s1 a1
    mv s2 a2
        # call fopen
            # prepare the arguments of fopen
    li a1 0
    jal fopen
            # If a0 is equal to -1, jump to fail
    li t0 -1
    beq a0 t0 openfail
            # save the file descriptor to s6
    mv s6 a0

    
    # Call fread and save the first 8 bytes to address a1 and a2
        # Call fread 
            # prepare the arguments of fread
    mv a0 s6
    li a2 4
    mv a1 s1 
    jal fread
    li a2 4
    bne a0 a2 readfail
    
    mv a0 s6
    mv a1 s2
    li a2 4
    jal fread
    li a2 4
    bne a0 a2 readfail
    
    # NO BUG IN ABOVE CODE
    
    # Allocates heap memory
        # call malloc
            # prepare the arguments
    lw t0 0(s1)
    lw t1 0(s2)

    # NO BUG IN ABOVE CODE
        # compute and save the number bytes to s4
    ebreak
    mul s4 t0 t1 # NO BUG s4 = 9 in test read_1
    li t0 4  
    mul s4 s4 t0 # NO BUG s4 = 36 in test read_1
    mv a0 s4 
    jal malloc
    beq a0 x0 mallocfail
            # save the address of matrix in memory to s3
    mv s3 a0

    # NO BUG IN ABOVE CODE
    
   # Read and save the remaining bytes to memory
        # prepare the arguments of fread
    mv a0 s6
    mv a1 s3
    mv a2 s4
    jal fread
    bne a0 s4 readfail

    # NO BUG IN ABOVE CODE
    
    # close the opened file
    mv a0 s6
    jal fclose
    bne a0 x0 closefail
    
    # move the address in s3 to a0
    mv a0 s3


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

openfail:
    li a0 27
    j exit
readfail:
    li a0 29
    j exit
mallocfail:
    li a0 26
    j exit
closefail:
    li a0 28
    j exit