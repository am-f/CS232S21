#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x, unsigned start, unsigned end) {
    
  unsigned * bitArray = (unsigned *)malloc((end - start + 1) * sizeof(unsigned));
    
  unsigned workingVal = x;

  for(int i = 0; i < start; i++) {
    workingVal = workingVal >> 1;
  }

  int j = 0;
  for(int i = start; i <= end; i++ ) {
    if(workingVal & 1) {
      bitArray[j] = 1;
    }
    else {
      bitArray[j] = 0;
    }
    workingVal = workingVal >> 1;
    j++;
  }

  return bitArray;
    // YOUR CODE HERE
    // Returning NULL is a placeholder
    // get_bits dynamically allocates an array a and set a[i] = 1 when (i+start)-th bit
    // of x is 1, otherwise set a[i] = 0;
    // At last, get_bits returns the address of the array.
}


