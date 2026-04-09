.globl relu

.text
# ==============================================================================
# FUNCTION: Performs an inplace element-wise ReLU on an array of ints
# Arguments:
#   a0 (int*) is the pointer to the array
#   a1 (int)  is the # of elements in the array
# Returns:
#   None
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
# ==============================================================================
relu:
    # Prologue
    bge x0 a1 malformed
    li t0 4
    mul t0 t0 a1
    add t0 t0 a0

loop_start:
    blt x0 a1 loop_continue
    j loop_end

loop_continue:
    addi t0 t0 -4
    addi a1 a1 -1
    lw t1 0(t0)
    bge t1 x0 loop_start
    sw x0 0(t0)
    j loop_start

loop_end:
    # Epilogue
    jr ra

malformed:
    li a0 36
    j exit
