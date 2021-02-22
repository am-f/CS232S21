#include<stdio.h>
#include<stdlib.h>

//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	char *binString= (char *)malloc(42 * sizeof(char));
  binString[0] = '0';
  binString[1] = 'b';

  for(int i = 2; i < 42; i++) {
    binString[i] = 'x';
  }

  for(int j = 6; j < 42; j+=5) {
    binString[j] = ' ';
  }
  
  int div = dec;
  for(int k = 2; k < 42; k++) {
    /*
    if(binString[i] == ' ') {
      continue;
    }
    */
    char test = (char)(div % 2);
    binString[k] = (char)(div % 2);
    if (binString[k] != '0') {
      div = div - (div / 2);

    }
    
    /*
    if(div % 2 != 0) {
      binString[i] = 1;
    }
    else {
      binString[i] = 0;
    }
    div = div % 2;
    */
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
}
