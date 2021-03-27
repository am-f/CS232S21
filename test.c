#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void clear1(int array[], int size) {
  for(int i = 0; i < size; i++) {
    array[i] = 0;
  }
}

void clear2(int *array, int size) {
  for(int *p = &array[0]; p < &array[size]; p++) {
    *p = 0;
  }
}

void clear3(int *array, int size) {
  int *arrayend = array + size;
  while(array < arrayend) *array++ = 0;
}

void swap(char ** arr1, char ** arr2) {
	char * temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
  }

void print(int array[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
void printstr(char * arr) {
  printf("%s\n", arr);
}

void printAll(int array1[], int array2[], int array3[], char array4[], char array5[], int size) {
  print(array1, size);
  print(array2, size);
  print(array3, size);
  printstr(array4);
  printstr(array5);
  printf("\n");
}

*/
/*
gcc -std=c11 -Wall -g test.c && ./a.out
*/
int main(void) {
  int a = 2147483647;
  int b = 2147483647;
  printf("%d", (int)(a + b));
  
  /*
  int array1[] = {1, 2, 3, 4};
  int array2[] = {1, 2, 3, 4};
  int array3[] = {1, 2, 3, 4};
  char array4[] = "abcd";
  char array5[] = "efgh";
  char * a4 = array4;
  char * a5 = array5;
  
  int size = 4;
  int * psize = &size;
  int * memtest = (int *) malloc(sizeof(int) * 8);
  printAll(array1, array2, array3, array4, array5, size);
  swap(a4, a5);
  //clear1(array1, size);
  //clear2(array2, size);
  //clear3(array3, size);
  printAll(array1, array2, array3, array4, array5, size);
  */
/*
  int i = 0;
  char ch = 'm';
  char s[4] = "akn";
  double f = 0.2;
  if((i = (i >= 0 ? i : (-i))) && 2*3 == 6) {
    i = 1;
  }
  else if(s[1] > ch) { i = 2; }
  else if(f == 0.2f) { i = 3; }
  else { i = 4; }

  printf("i=%d\n", i);
  */



  return 0;
  

/*
  int i=0;
  int * p_i = &i;
  int j = 2;
  printf("*(p_i+2)=%d, j=%d\n", *(p_i + 1), j);
  printf("i=%d, *i=%d\n", i, *p_i);
  *p_i = 3;
  printf("i=%d, *i=%d\n", i, *p_i);
  return 0;
  */
  
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