#include <stdio.h>
#include <stdlib.h>

int midpoint_original(int x, int y) {
  return (x + y)/2;
}

int midpoint_A(int x, int y) {
  return x + ((y - x) / 2);
}

int midpoint_B(int x, int y) {
  //unsigned int uX = (unsigned int)x;
  //unsigned int uY = (unsigned int) y;
  //unsigned int uAdd = uX + uY;
  //int add = uX + uY;
  //int returnVal = add >> 1;
  //return ((int)((unsigned int)x + (unsigned int)y)) >> 1;
  return ((unsigned int)x + (unsigned int)y) >> 1;

}

int midpoint_C(int x, int y) {
  int a = x;
  int b = y;
  int and = x & y;
  int xor = x ^ y;
  int xorshift = xor >> 1;
  int midpoint = (and + xorshift);
  int br = 0;
  return and + xorshift;
  //return (x & y) + ((x ^ y) >> 1);
}
int midpoint_Or(int x, int y) {
  int and = x & y;
  int xor = x ^ y;
  int xorshift = xor >> 1;
  return (and | xorshift);
  //return (x & y) | ((x ^ y) >> 1);
}

int main(int argc, char ** argv) {
    int a = atoi(argv[1]); //atoi converts string to int
    int b = atoi(argv[2]);
    //printf("midpoint_original = %d\n", midpoint_original(a, b));
    printf("\nfail A:\n");
    midpoint_C(2147483647, -2147483648);
    midpoint_C(1, -2147483648);
    midpoint_C(-2147483648, 2147483647);
    midpoint_C(-2147483648, 1);
    midpoint_C(-2147483648, 0);
    midpoint_C(2147483647, -2147483647);
    midpoint_C(-2147483647, 2147483647);
    





    printf("%d", midpoint_C(a, b));
    //printf("input x: %d\n", a);
    //printf("input y: %d\n", b);
    //printf("midpoint_A = %d\n", midpoint_A(a, b)); 
    //printf("midpoint_B = %d\n", midpoint_B(a, b)); 

    //printf("midpoint_C = %d\n", midpoint_C(a, b));
    //printf("midpoint_Or = %d\n", midpoint_Or(a, b));
    return 0;
}
