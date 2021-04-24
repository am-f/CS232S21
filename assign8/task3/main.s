main:
  pushl %ebp //push ebp to stack
  movl %esp,%ebp //copy esp into ebp
  subl $12,%esp //make esp zzzz-12
  movl $13,-4(%ebp) //put a=13 into stack
  movl $5,-8(%ebp) //put b=5 into stack
  movl $0,-12(%ebp) //put c=0 into stack
  cmpl $6,-4(%ebp) //compare a=13 and 6
  jle .L2 // a <= 6 is false, so continue to if
  movl $15,-8(%ebp) //inside if a > 6, put b=15 into stack
.L2:
.L3:
  cmpl $14,-12(%ebp) //compare c=0 and 14, do 0-14
  jg .L4 //-14 < 0 so don't jump
  movl -12(%ebp),%eax //put c=0 into reg %eax
  addl %eax,-4(%ebp) //add %eax+13 and put it in a
  incl -12(%ebp) //increment c
  jmp .L3 //back to beginning of loop
.L4:
  leave
  ret
