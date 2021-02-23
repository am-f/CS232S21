#include <stdio.h>

int main(void) {
  int i=0;
  int * p_i = &i;
  int j = 2;
  printf("*(p_i+2)=%d, j=%d\n", *(p_i + 1), j);

  printf("i=%d, *i=%d\n", i, *p_i);



  *p_i = 3;
  printf("i=%d, *i=%d\n", i, *p_i);




  return 0;

}
/*
11    printf("i=%d, *i=%d", i, *p_i);
(gdb) p i
$1 = 3
(gdb) i p_1
Undefined info command: "p_1".  Try "help info".
(gdb) i p_i
Undefined info command: "p_i".  Try "help info".
(gdb) p p_i
$2 = (int *) 0x7ffeaa83f98c
(gdb) p &i
$3 = (int *) 0x7ffeaa83f98c
(gdb) p (char *) &i
$4 = 0x7ffea
*/