#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v) {

  unsigned vCopy[end-start+1];
  for(int i = 0; i <= (end-start); i++) {
    vCopy[i] = v[i];
  }
  printf("%d\n", vCopy[0]);
  int leadingZero = 1;
  /*
  if(vCopy[0] == 0) { 
    leadingZero = 0;
    vCopy[0] = 1; 
    }
  */
  printf("%d\n", vCopy[0]);

  
int vTest = 0;
int finger = end;
//int index = 0;
//for(int index = 0; index < end - start + 1; index++) {
unsigned int bitMask = 4294967295;
unsigned int shifts = (end-start) + 1;
unsigned int vMask = bitMask;
vMask = vMask << (shifts);
//printf("vMask d: %u\n", vMask);
//printf("vMask x: %08x\n", vMask);
vMask = ~vMask;
//printf("vMask d: %u\n", vMask);
//printf("vMask x: %08x\n", vMask);
vMask = vMask << start;
//printf("vMask d: %u\n", vMask);
//printf("vMask x: %08x\n", vMask);
for(int index = end-start; index >= 0; index--) {
  for(int j = 0; j < finger; j++) {
    vCopy[index] = vCopy[index] << 1;

  }
  finger--;
  vTest = vTest + vCopy[index];
  //index++;
}
/*
for(int i = 0; i < start; i++) {
  vTest = vTest << 1;
}
*/
/* current
printf("*x d: %u\n", *x);
printf("*x x: %08x\n", *x);
printf("vTest d: %u\n", vTest);
printf("vTest x: %08x\n", vTest);
*/
*x = ((vMask | *x) ^ vMask) | vTest;
/*
*x = (vMask ^ *x) | vTest;
printf("*x u: %u\n", *x);
printf("*x u: %08x\n", *x);
*/
/* current
printf("*x d: %u\n", *x);
printf("*x x: %08x\n", *x);
*/


int bp = 0;
int test = (*x ^ vTest) + (*x & vTest);

//printf("%d\n", test);
//*x = (*x ^ vTest) + (*x & vTest);
/*
if(leadingZero == 0) {
  *x = *x - vCopy[0];
}
*/
printf("%d\n", *x);



bp = 1;

/*
  for(int i = start; i <= end; i++ ) {
    if(v[i] == 0) {
      x[i + start] = 0;
    }
    else {
      x[i + start] = 1;
    }
    
  }

    */
    // YOUR CODE HERE
    // No return value
    // v points to an array of at least (end-start+1) unsigned integers.
    // if v[i] == 0, then set (i+start)-th bit of x zero, otherwise, set (i+start)-th bit of x one.
}
/*

int main() {
  //unsigned test = 0b1001110;
  unsigned expectedArr[] = {1,0,1,0};
  unsigned test = 0;

  set_bits(&test,2,5,expectedArr);
  return 0;
}
*/