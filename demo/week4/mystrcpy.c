#include <stdio.h>
#include <string.h>
#include <stdlib.h> //this is so we don't have to declare malloc function before using it, since it's included. instdlib.h

char * mystrcpy (char source[]) {
  //sizeof(char *) is always going to be 4 bytes on a 32 bit system
  int len_of_source = strlen(source);
  char * dest = (char *)malloc(sizeof(char)*(len_of_source+1));//add 1 for terminal character, you should always copy \0 over
  for(int i = 0; i<len_of_source+1; i++) {
    dest[i]=source[i];
  }
  return dest;
}

int main() {
  char a[] = "Hello World";
  //imp a string copy func
  char * copyofa = mystrcpy(a);
  printf("%s\n", copyofa);
  free(copyofa);
}