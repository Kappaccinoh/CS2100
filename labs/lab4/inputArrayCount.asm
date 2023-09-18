# arrayCount.asm
  .data 
arrayA: .word 0, 0, 0, 0, 0, 0, 0, 0   # arrayA has 5 values
count:  .word 999             # dummy value
userInput: .word 0
  .text
main:
    # code to setup the variable mappings
    # la $t0, arrayA
    # la $t8, count

    # code for reading in the user value X
    move $t0, $0
    move $t1, $0
    addi $t1, $t1, 32
INPUTLOOP:
    beq $t0, $t1, INPUTLOOPEND
    li   $v0, 5
    syscall # read user input
    sw $v0, arrayA($t0)
    addi $t0, $t0, 4
    j INPUTLOOP
INPUTLOOPEND:


    # code for reading in the user value X
    li   $v0, 5
    syscall # read user input
    sw $v0, userInput
    # code for counting multiples of X in arrayA
    lw $t8, userInput
    addi $t5, $t8, -1 # $t5 is your mask

    move $t6, $0
    move $t0, $0
    move $t1, $0
    addi $t1, $t1, 32

LOOP: beq $t0, $t1, END
      lw $t3, arrayA($t0)
      and $t4, $t3, $t5
      bne $t4, $0, SKIP
      addi $t6, $t6, 1
SKIP: addi $t0, $t0, 4
      j LOOP
END:

    # store value for count into memory
    sw $t6, count

    # code for printing result
    li   $v0, 1    # system call code for print_int
    lw   $a0, count
    syscall        # print the integer

    # code for terminating program
    li  $v0, 10
    syscall
