#include <stdio.h>

int main(int argc, char *argv[]) {

  char str[1000];
  int ch, n = 0;

   while ((ch = getchar()) != EOF /*&& n < 1000*/) {
     if(ch == '\n') {
       break;
     }
     else if(ch > 96 && ch < 123) {
        str[n] = ch - 32;
     }
      else {
        str[n] = ch;
      }

      ++n;
   }

   for (int i = 0; i < n; ++i) {
      putchar(str[i]);
   }
   printf("\n");

    return 0;
}

