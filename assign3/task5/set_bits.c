#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v) {

  unsigned vCopy[sizeof(v)];
  for(int i = 0; i < sizeof(v); i++) {
    vCopy[i] = v[i];
  }
  
  
/*
  unsigned xCopy = *x;
  unsigned *vCopy = v;
  unsigned *vFinal = *v;
  for(int i= 0; i < start; i++) {
    xCopy = xCopy >> 1;
  }
  unsigned revVArray = *v;

  unsigned test;
  for(int i= 0; i < start; i++) {
    test = vCopy[0] << 1;
  }
  */
/*
  for(int i = 0; i <= end - start; i++) {
      if(v[i] == 1 && (xCopy & 1)) {
        //
      }
      if(v[i] == 1 && !(xCopy & 1)) {
        xCopy = xCopy + 1;
      }
  }
  */

int vTest = 0;
int finger = end;
//int index = 0;
//for(int index = 0; index < end - start + 1; index++) {
for(int index = end-start; index >= 0; index--) {
  for(int j = 0; j < finger; j++) {
    vCopy[index] = vCopy[index] << 1;
  }
  finger--;
  vTest = vTest + vCopy[index];
  //index++;
}
int bp = 0;
int test = (*x ^ vTest) + (*x & vTest);
*x = (*x ^ vTest) + (*x & vTest);

/*
for(int i = 0; i < start; i++) {
  vTest = vTest << 1;
}
bp = 1;
*/
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