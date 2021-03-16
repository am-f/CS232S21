#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "snode.h"

struct snode * snode_create(void *s, int size) 
{

  struct snode * newNode = (struct snode *)malloc(sizeof(struct snode));
  newNode->data = malloc(size);
  //if(sizeof(*s) == 1) {
    for(int i = 0; i < size; ) {
      *(((char *)newNode->data)+i) = *(((char *)s+i));
      i++;
    }
  //}
  /*
  else if(size == 4) {
    printf("%d\n", sizeof(*s));
    printf("%d\n", size);
    for(int i = 0; i < sizeof(*s)); ) {
      *(((int *)newNode->data)+i) = *(((int *)s+i));
      i++;
    }
  }
  */


  //newNode->data = temp;
  newNode->next = NULL;
  newNode->size = size;

  return newNode;
}

void snode_destroy(struct snode * s) 
{
  //char * temp = s->data;

  //void ** temp = &(s->data);
  free(s->data);
  //free(s->data);
  free(s);
};
 