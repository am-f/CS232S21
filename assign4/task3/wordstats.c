#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len = 0;
  int i;
  char buf[MAX_BUF];
  int end = 0;

  while(end == 0) {
    fgets((buf + len), MAX_BUF, stdin);
    if(buf[len] == '\n') {
      end = 1;
    }
  }

  for(i = 0; i < strlen(buf); i++) {
    if(buf[i] > 96 && buf[i] < 123) {
      buf[i] = buf[i] - 32;
     }
    letter_frequency[(int)buf[i] - 65]++;
  }
  
  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c: %d\n", 65+i, letter_frequency[i]);
  }
}
