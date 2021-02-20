#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x, unsigned start, unsigned end) {
    
  unsigned * bitArray = (unsigned *)malloc((end - start + 1) * sizeof(unsigned));

  for(int i = 0; i < start; i++) {
    x = x >> 1;
  }

  int j = 0;
  for(int i = start; i <= end; i++ ) {
    if(x & 1) {
      bitArray[j] = 1;
    }
    else {
      bitArray[j] = 0;
    }
    x = x >> 1;
    j++;
  }

  return bitArray;

}



