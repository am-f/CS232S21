#include <stdio.h>
#include <stdlib.h>
/*

void print_array(int a[], int s) {
  int i;
  for(i = 0; i<s; i++) {
    printf("%d:%d, ", i, a[i]);
  }
  int p = 1;
  printf("\n");
}

int mystery(int a[], int s, int y) {
  int i, val;
  val =0;
  for(i=0; i<s; i++) {
    if(a[i]>y) {
      val++;
      a[i]=a[i]-y;
    }
  }
  return val;
}

*/
int *foo(int *a, int *b, int s);
int main() {
  /*
  int i, myarray[10], num;
  for(i=0; i<10; i++) {
    myarray[i]=i;
  }
  printf("Before:\n");
  print_array(myarray, 10);
  num=mystery(myarray, 7, 3);
  printf("After: num = %d\n", num);
  print_array(myarray, 10);
  */
  /*
  int *a, b[5], c, *d;
  for(c=0; c<5; c++) {
    b[c]=1+c;
  }
  d=b;
  a=&c;
  c=d[3];
  */

  int *arr = NULL, x=6, y=7, i;
  arr=foo(&x, &y, 5);
  printf("x = %d y=%d\n", x, y);
  if(arr != NULL) {
    for(i=0; i<5; i++) {
      printf("arr[%d] = %d\n", i, arr[i]);
    }
  }
  free(arr);

  return 0;
}

int *foo(int *a, int *b, int s) {
  int *tmp, i;
  tmp=malloc(sizeof(int)*s);
  if(tmp != NULL) {
    for(i=0; i<s; i++) {
      tmp[i]=i + *b;
    }
    *a=tmp[2];
    *b=8;
  }
    int done=0;
  return tmp;
}