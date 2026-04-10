.globl dot

.text
# =======================================================
# FUNCTION: Dot product of 2 int arrays
# Arguments:
#   a0 (int*) is the pointer to the start of arr0
#   a1 (int*) is the pointer to the start of arr1
#   a2 (int)  is the number of elements to use
#   a3 (int)  is the stride of arr0
#   a4 (int)  is the stride of arr1
# Returns:
#   a0 (int)  is the dot product of arr0 and arr1
# Exceptions:
#   - If the number of elements to use is less than 1,
#     this function terminates the program with error code 36
#   - If the stride of either array is less than 1,
#     this function terminates the program with error code 37
# =======================================================
dot:
    # Prologue
    bge x0 a2 malnumelement
    bge x0 a3 malstride
    bge x0 a4 malstride
    li t0 0
    li t1 0
    li t5 4
    mul t6 a4 t5
    mul t5 a3 t5 

loop_start:
    blt t1 a2 loop_continue
    j loop_end

loop_continue:
    lw t2 0(a0)
    lw t3 0(a1)
    mul t4 t2 t3
    add t0 t0 t4
    addi t1 t1 1
    add a0 a0 t5
    add a1 a1 t6
    j loop_start

loop_end:
    # Epilogue
    mv a0 t0
    jr ra

malnumelement:
    li a0 36
    j exit
malstride:
    li a0 37
    j exit

