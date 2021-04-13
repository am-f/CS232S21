#include<stdio.h>
int main(void) {
  unsigned char a = 10;
  unsigned char b = 9;
  unsigned char c = a|b;
  printf("a|b=%d\n", c);
  return 0;
}

/*
a: 0b00001010
b: 0b00001001
*/