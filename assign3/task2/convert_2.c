#include<stdio.h>
#include<stdlib.h>

//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	char *binString= (char *)malloc(42 * sizeof(char));
  char rawBinArr[42];
  int workingBin = dec;
  for (int i = 31; i >= 0; i--) {
    if(workingBin & 1) {
      rawBinArr[i] = '1';
    }
    else {
      rawBinArr[i] = '0';
    }
    workingBin = workingBin >> 1;
  }
  binString[0] = '0';
  binString[1] = 'b';

  for(int j = 6; j < 42; j+=5) {
    binString[j] = ' ';
  }

  int i = 0;
  while(i < 32) {
    for(int j = 2; j < 42; j++) {
      if(binString[j] != ' ') {
        binString[j] = rawBinArr[i];
        i++;
      }
    }
  }

  return binString;
}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s\n", n, bin);
	//TODO: do we need to release the memory of bin?
  free(bin);
}
