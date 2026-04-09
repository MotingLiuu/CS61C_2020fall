.globl argmax

.text
# =================================================================
# FUNCTION: Given a int array, return the index of the largest
#   element. If there are multiple, return the one
#   with the smallest index.
# Arguments:
#   a0 (int*) is the pointer to the start of the array
#   a1 (int)  is the # of elements in the array
# Returns:
#   a0 (int)  is the first index of the largest element
# Exceptions:
#   - If the length of the array is less than 1,
#     this function terminates the program with error code 36
# =================================================================
argmax:
    # Prologue
    bge x0 a1 malformed
    li t0 0
    lw t1 0(a0)
    li t2 0

loop_start:
    blt t0 a1 loop_continue
    j loop_end

loop_continue:
    lw t3 0(a0)
    addi t0 t0 1
    addi a0 a0 4
    bge t1 t3 loop_start
    mv t1 t3
    mv t2 t0
    addi t2 t2 -1
    j loop_start

loop_end:
    # Epilogue
    mv a0 t2
    jr ra

malformed:
    li a0 36
    j exit
