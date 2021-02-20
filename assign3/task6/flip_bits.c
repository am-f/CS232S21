#include <stdio.h>
#include <stdlib.h>

// Note, the bits are counted from right to left. 
// Flip the bits of x within range [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
void flip_bits(unsigned * x, unsigned start, unsigned end) {

  unsigned int xflip = ~*x;
  unsigned int vMask = 4294967295;
  unsigned int shifts = (end - start) + 1;
  vMask = vMask << shifts;
  vMask = ~vMask;
  vMask = vMask << start;

  *x = ((vMask | *x) ^ vMask);
  xflip = ((~vMask | xflip) ^ ~vMask);
  *x = *x | xflip;

}
