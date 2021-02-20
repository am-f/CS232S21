/*memleak_example.c*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
/* Explanation: The memory leak in this program was because the allocated memory that a pointed to (line 8) was never freed before a was reassigned (line 15), then because the new allocated memory that a pointed to was never freed at the end of the program.
*/
  int * a = malloc(sizeof(int *));

  *a = 10;  

  printf("%d\n", *a);
  free(a);

  a = malloc(sizeof(int *)*3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  printf("%d %d %d\n", a[0], a[1], a[2]);
  free(a);
}
