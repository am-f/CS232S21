#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "snode.h"

struct snode * snode_create(char *s) 
{
  struct snode * newNode = (struct snode *)malloc(sizeof(struct snode));
  newNode->str = (char *)malloc(strlen(s) + 1);
  strcpy(newNode->str, s);
  newNode->next = NULL;

  return newNode;
}
void snode_destroy(struct snode * s) 
{
  free(s->str);
  free(s);
}
 
