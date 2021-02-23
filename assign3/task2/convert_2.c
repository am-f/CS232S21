#include<stdio.h>
#include<stdlib.h>

//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
<<<<<<< HEAD

	char *binString= (char *)malloc(42);
  char binArr[32];

  for (int i = 31; i >= 0; i--) {
    if(dec & 1) {
      binArr[i] = '1';
    }
    else {
      binArr[i] = '0';
    }
    dec = dec >> 1;
  }

  binString[0] = '0';
  binString[1] = 'b';
  binString[41] = '\0';
=======
	char *binString= (char *)malloc(42 * sizeof(char));
  binString[0] = '0';
  binString[1] = 'b';

  for(int i = 2; i < 42; i++) {
    binString[i] = 'x';
  }
>>>>>>> 5aeca1f94339b3123980ed92a07412684309cec5

  for(int j = 6; j < 42; j+=5) {
    binString[j] = ' ';
  }
<<<<<<< HEAD

  for(int i = 0; i < 32; ) {
    for(int j = 2; j < 41; j++) {
      if(binString[j] != ' ') {
        binString[j] = binArr[i];
        i++;
      }
    }
=======
  
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
>>>>>>> 5aeca1f94339b3123980ed92a07412684309cec5
  }

  return binString;

<<<<<<< HEAD

=======
>>>>>>> 5aeca1f94339b3123980ed92a07412684309cec5
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
