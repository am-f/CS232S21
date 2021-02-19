#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
  /* Lines 12 and 15 are causing the memory violation here, because both have i <= 10.  The arrays are 10 ints long, but since i starts at 0, then it can only go up through 9, but it must be less than 10.  The memory at a[10] does not "belong" to the array, only a[0] through a[9].  Finally, the memory allocated for the array must be freed at the end of the program, to prevent a memory leak.
  */

  int i, *a;

  a = malloc(sizeof(int)*10);

  for(i=0;i <= 9; i++){
    a[i] = i;
  }
  for(i=0;i <= 9; i++){
    printf("%d\n", a[i]);
  }

  free(a);
}
