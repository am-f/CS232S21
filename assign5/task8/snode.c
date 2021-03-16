#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "snode.h"

struct snode * snode_create(void *s, int size) {
  struct snode * newNode = (struct snode *)malloc(sizeof(struct snode));
  newNode->data = malloc(size);
  for(int i = 0; i < size; ) {
    *(((uint8_t *)newNode->data)+i) = *(((uint8_t * s+i));
    i++;
  }
  newNode->next = NULL;
  newNode->size = size;

  return newNode;
}

void snode_destroy(struct snode * s) {
  free(s->data);
  free(s);
}
 