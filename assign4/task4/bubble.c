/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdlib.h>


#define NUM 30   /* number of strings */
#define LEN 1200  /* max length of each string */

void swap(char * str1, char * str2) {
    int strlen1 = strlen(str1);
    int strlen2 = strlen(str2);
    int len1mlen2 = strlen1 - strlen2;
    int longestLen;
    char * temp;
    if(len1mlen2 >= 0) { 
      longestLen = strlen1;
      //shortestLen = strlen2;
      temp = (char *)malloc(strlen1);
    }
    else {
      longestLen = strlen2;
      //shortestLen = strlen1;
      temp = (char *)malloc(strlen2);
    }

    for(int i = 0; i < longestLen; i++) {
      *(temp + i) = *(str1 + i);
      *(str1 + i) = *(str2 + i);
      *(str2 + i) = *(temp + i);

    }
  
    free(temp);
}

int mystrcmp(char * str1, char * str2) {
  int str1len = strlen(str1);
  int str2len = strlen(str2);
  int len1mlen2 = str1len - str2len;
  int defaultOutcome;
  int shortestlen;
  //char * aString;
  //char * zString;
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
      //printf("br -1\n");
      break;
    }
    else if(str1[i] > str2[i]) { 
      outcome = 1;
      //printf("br 1\n");
      break;
    }
  }

  if(outcome == 0 && defaultOutcome == 0) {
    outcome = 0;
    //printf("o=0\n");
  }
  else if(outcome == 0 && defaultOutcome == -1) {
    outcome = -1;
    //printf("sl, o=-1\n");
  }
  else if(outcome == 0 && defaultOutcome == 1) {
    //printf("sl, o=1\n");
    outcome = 1;
  } 

  return outcome;

}

void bubbleSort(char ** strings) {
  //int swapped = 0;
  for(int i = 0; i < NUM; i++) {
    //swapped = 0;
    for(int j = 0; j < NUM -1 - i; j++) {
      int comp = mystrcmp(strings[j], strings[j+1]);
      if(comp <= 0) {
        //swapped = 0;
      }
      else {
        swap(strings[j], strings[j+1]);
        //swapped = 1;
      }
    }
    //if(swapped == 0) { break; }
  }
}



int main()
{
  char * Strings[NUM];
  //char bufferString[LEN];
  //char bufferString[LEN];
  //char * stringPointer;
  //stringPointer = Strings[0];


  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length. However, each 
	 string stored in array Strings must not waste space. That is, only the buffer
	 used by fgets() to temporary store the string read from input stream needs to 
	 be LEN bytes long.  
	 Note that the newline and NULL characters will be included in LEN.
  */
  printf("Please enter %d strings, one per line:\n", NUM);
  
  for(int i = 0; i < NUM; i++) {
    char bufferString[LEN];
    //fgets(*(Strings+i), LEN, stdin);
    fgets(bufferString, LEN, stdin);
    char * stringPointer = (char *)malloc(strlen(bufferString)+1);
    //stringPointer = (char *)malloc(strlen(bufferString));
    int j = 0;
    for(j = 0; j < strlen(bufferString)-1; j++) {
      stringPointer[j] = bufferString[j];
    }
    stringPointer[j] = '\0';
    //printf("strlen: %lu\n", strlen(stringPointer));
    Strings[i] = stringPointer;

  }

  /* Write a for loop here to print all the strings. */
  puts("\nHere are the strings in the order you entered:");
  for(int i = 0; i < NUM; i++) {
    puts(*(Strings+i));
    //printf("%s\n", *(Strings+i));
    //printf("sizeof: %d\n", sizeof(*(Strings+i)));
  }
  bubbleSort(Strings);
  
  
/*
  void testSwap() {
    char str1[] = {"abcd"};
    //char * pstr1 = str1;
    char str2[] = "xyz";
    //char * pstr2 = str2;
    printf("1: %s\n2: %s\n", str1, str2);
    swap(str1, str2);
    printf("1: %s\n2: %s\n", str1, str2);
  }
  testSwap();
  */
/*
  void testCmp() {
    char str1[] = "abc";
    char str2[] = "xyz";
    char str3[] = "abc";
    int comp = mystrcmp(str1, str3);
    printf("%d\n", comp);
  }
  testCmp();
  */
  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) Implement a swap function to swap two strings by swapping pointers
	    without copying any chars.You are not allowed to use any C library 
	    functions in swap.
      (iii) You are allowed to use strlen() to calculate string lengths.
  */
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");     
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  for(int i = 0; i < NUM; i++) {
    //printf("%s\n", *(Strings+i));
    puts(*(Strings+i));
    //printf("sizeof: %d\n", sizeof(*(Strings+i)));
  }
  printf("\n");
  for(int i = 0; i < NUM; i++) {
    free(*(Strings+i));
  }


}
