#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode {
  //TODO: change str to dynamic allcoation
  char * str;
  struct snode *next;
};


struct snode * snode_create(char *s) 
{
  struct snode * newNode = (struct snode *)malloc(sizeof(struct snode));
  newNode->str = malloc(strlen(s) + 1);
  strcpy(newNode->str, s);
  newNode->next = NULL;

  return newNode;
  
  
}
void snode_destroy(struct snode * s) 
{
  free(s->str);
  free(s);

 
};
 
