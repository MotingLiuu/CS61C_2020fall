.globl write_matrix

.text
# ==============================================================================
# FUNCTION: Writes a matrix of integers into a binary file
# FILE FORMAT:
#   The first 8 bytes of the file will be two 4 byte ints representing the
#   numbers of rows and columns respectively. Every 4 bytes thereafter is an
#   element of the matrix in row-major order.
# Arguments:
#   a0 (char*) is the pointer to string representing the filename
#   a1 (int*)  is the pointer to the start of the matrix in memory
#   a2 (int)   is the number of rows in the matrix
#   a3 (int)   is the number of columns in the matrix
# Returns:
#   None
# Exceptions:
#   - If you receive an fopen error or eof,
#     this function terminates the program with error code 27
#   - If you receive an fclose error or eof,
#     this function terminates the program with error code 28
#   - If you receive an fwrite error or eof,
#     this function terminates the program with error code 30
# ==============================================================================
write_matrix:

    # Prologue
    addi sp sp -28
    sw ra 0(sp)
    sw s1 4(sp)
    sw s2 8(sp)
    sw s3 12(sp)
    sw s4 16(sp)
    sw s5 20(sp)
    sw s6 24(sp)
    
    mv s1 a1
    mv s2 a2
    mv s3 a3
    
    # Open the file with write permission
        # Call fopen
    li a1 1
    jal fopen
    li t0 -1
    beq a0 t0 openfail
        # Save the file descriptor to s4
    mv s4 a0 
    
    # Write the number of rows and columns to the file
        # Save the row s2 and column s3 to memo
    addi sp sp -8
    sw s2 0(sp)
    sw s3 4(sp)
        # Call fwrite to write s2 s3 to file
    mv a0 s4
    addi a1 sp 0
    li a2 2
    li a3 4
    jal fwrite
    li a2 2
    bne a0 a2 writefail
        # Increase the stack pointer
    addi sp sp 8
    

    # Write the matrix to the file
        # Call fwrite
    mv a0 s4
    mv a1 s1
    mul a2 s2 s3
    li a3 4
    jal fwrite
    mul a2 s2 s3
    bne a0 a2 writefail
    
    # Close the file
    mv a0 s4
    jal fclose
    li t0 -1
    beq a0 t0 closefail


    # Epilogue

    lw ra 0(sp)
    lw s1 4(sp)
    lw s2 8(sp)
    lw s3 12(sp)
    lw s4 16(sp)
    lw s5 20(sp)
    lw s6 24(sp)
    addi sp sp 28

    jr ra

openfail:
    li a0 27
    j exit
closefail:
    li a0 28
    j exit
writefail:
    li a0 30
    j exit

