#include <stdio.h>
#include <stdlib.h>

// Set the bits of x within range of [start, end], in which both are inclusive
// Assume 0 <= start & end <= 31
void set_bits(unsigned * x, unsigned start, unsigned end, unsigned *v) {

  unsigned vCopy[end - start + 1];
  for(int i = 0; i <= (end - start); i++) {
    vCopy[i] = v[i];
  }

  unsigned int vBin = 0;
  int finger = end;

  unsigned int vMask = 4294967295;
  unsigned int shifts = (end - start) + 1;
  vMask = vMask << shifts;
  vMask = ~vMask;
  vMask = vMask << start;
  
  for(int index = (end - start); index >= 0; index--) {
    for(int j = 0; j < finger; j++) {
      vCopy[index] = vCopy[index] << 1;
    }
    finger--;
    vBin = vBin + vCopy[index];
  }

  *x = ((vMask | *x) ^ vMask) | vBin;

}
