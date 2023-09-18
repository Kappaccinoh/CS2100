# messages.asm
  .data 
str: .asciiz "the answer = "
val1: .word 0
  .text


main: 
    li   $v0, 5
    syscall
    sw $v0, val1

    li   $v0, 4    # system call code for print_string
    la   $a0, str  # address of string to print
    syscall        # print the string

    li   $v0, 1    # system call code for print_int
    lw   $a0, val1
    syscall        # print the integer
    
    li   $v0, 10   # system call code for exit
    syscall        # terminate program
