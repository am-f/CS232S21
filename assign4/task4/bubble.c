/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

void swap(char ** str1, char ** str2) {
    char * temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int mystrcmp(char * str1, char * str2) {
  int str1len = strlen(str1);
  int str2len = strlen(str2);
  int len1mlen2 = str1len - str2len;
  int defaultOutcome;
  int shortestlen;
  int outcome = 0;
  if(len1mlen2 < 0) { 
    defaultOutcome = -1; 
    shortestlen = str1len;
  }
  else if( len1mlen2 > 0) { 
    defaultOutcome = 1; 
    shortestlen = str2len;
  }
  else {
    defaultOutcome = 0;
    shortestlen = str1len;
  }

  for(int i = 0; i < shortestlen; i++) {
    if(str1[i] < str2[i]) {
      outcome = -1;
      break;
    }
    else if(str1[i] > str2[i]) { 
      outcome = 1;
      break;
    }
  }

  if(outcome == 0 && defaultOutcome == 0) {
    outcome = 0;
  }
  else if(outcome == 0 && defaultOutcome == -1) {
    outcome = -1;
  }
  else if(outcome == 0 && defaultOutcome == 1) {
    outcome = 1;
  } 
  return outcome;
}

void bubbleSort(char ** strings) {
  for(int i = 0; i < NUM; i++) {
    for(int j = 0; j < NUM -1 - i; j++) {
      int comp = mystrcmp(strings[j], strings[j+1]);
      if(comp <= 0) {
        //do nothing, they're in the correct order
      }
      else {
        swap((strings+j), (strings+j+1));
      }
    }
  }
}



int main()
{
  char * Strings[NUM];

  //printf("Please enter %d strings, one per line:\n", NUM);
  
  for(int i = 0; i < NUM; i++) {
    char bufferString[LEN];
    fgets(bufferString, LEN, stdin);
    char * stringPointer = (char *)malloc(strlen(bufferString)+1);
    int j = 0;
    for(j = 0; j < strlen(bufferString)-1; j++) {
      *(stringPointer+j) = *(bufferString+j);
    }
    stringPointer[j] = '\0';
    Strings[i] = stringPointer;
  }

/*
  puts("\nHere are the strings in the order you entered:");
  for(int i = 0; i < NUM; i++) {
    puts(*(Strings+i));
  }
*/

  bubbleSort(Strings);
  
  //puts("\nIn alphabetical order, the strings are:");    

  for(int i = 0; i < NUM; i++) {
    puts(*(Strings+i));
  }


  for(int i = 0; i < NUM; i++) {
    free(*(Strings+i));
  }

}
