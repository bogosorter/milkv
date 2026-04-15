.section .text
.globl fibonacci

# Iterative Fibonacci implementation

fibonacci:
    # These registers hold the current and next Fibonacci numbers
    li t0, 1
    li t1, 1

loop:
    # The argument register holds the number of iterations to perform
    beq a0, zero, done

    # Perform an iteration
    add t2, t0, t1  # next = t0 + t1
    mv  t0, t1      # t0 = t1
    mv  t1, t2      # t1 = next

    # Decrement the number of iterations to perform
    addi a0, a0, -1
    j loop

done:
    mv a0, t0       # return value
    ret
