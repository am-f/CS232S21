#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {
  int len = 0;
  int i;
  char buf[MAX_BUF];
  int chars = 0;
  int words = 0;
  int lines = 0;
  int whitespaces = 0;
  int uppercase = 0;
  int lowercase = 0;
  int digits = 0;

  while(fgets((buf + len), MAX_BUF, stdin) != NULL) {
    len = strlen(buf);
  }

  for(i = 0; i < strlen(buf); i++) {
    chars++;
    if(buf[i] == ' ' || buf[i] == '\t') {
      whitespaces++;
    }
    else if(buf[i] == '\n') {
      lines++;
    }
    else {
      if(buf[i] >= 65 && buf[i] <= 90) {
        uppercase++;
      }
      else if(buf[i] >= 97 && buf[i] <= 122) {
        lowercase++;
      }
      else if(buf[i] >= 48 && buf[i] <= 57) {
        digits++;
      }
      if(buf[i+1] != EOF && (buf[i+1] == ' ' || buf[i+1] == '\t' || buf[i+1] == '\n')) {
        words++;
      }
    }
  }
  
  printf("%d %d %d %d %d %d %d\n", chars, words, lines, whitespaces, uppercase, lowercase, digits);
}