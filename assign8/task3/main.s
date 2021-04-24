main:
  pushl %ebp //push ebp to stack
  movl %esp,%ebp //copy esp into ebp
  subl $12,%esp //make esp zzzz-12
  movl $13,-4(%ebp) //put a=13 into stack
  movl $5,-8(%ebp) //put b=5 into stack
  movl $0,-12(%ebp) //put c=0 into stack
  cmpl $6,-4(%ebp)
  jle .L2
  movl $15,-8(%ebp)
.L2:
.L3:
  cmpl $14,-12(%ebp)
  jg .L4
  movl -12(%ebp),%eax
  addl %eax,-4(%ebp)
  incl -12(%ebp)
  jmp .L3
.L4:
  leave
  ret
