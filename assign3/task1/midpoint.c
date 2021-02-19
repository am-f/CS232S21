#include <stdio.h>
#include <stdlib.h>

int midpoint_original(int x, int y) {
    return (x + y)/2;
}

int midpoint_B(int x, int y) {
  unsigned int uX = (unsigned int)x;
  unsigned int uY = (unsigned int) y;
  unsigned int uAdd = uX + uY;
  int add = uX + uY;
  int returnVal = add >> 1;
    //return ((int)((unsigned int)x + (unsigned int)y)) >> 1;
    return (unsigned int)x + (unsigned int)y >> 1;
    //return (x + y) >> 1;
}

int midpoint_C(int x, int y) {
  int and = x & y;
  int xor = x ^ y;
  int xorshift = xor >> 1;
    return (x & y) + ((x ^ y) >> 1);
}

int main(int argc, char ** argv) {
    int a = atoi(argv[1]); //atoi converts string to int
    int b = atoi(argv[2]);
    printf("midpoint_original = %d\n", midpoint_original(a, b));

    //printf("midpoint_B = %d\n", midpoint_B(a, b));    
    printf("midpoint_C = %d\n", midpoint_C(a, b));
    return 0;
}
