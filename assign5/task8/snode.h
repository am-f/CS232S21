#ifndef _snode_H_
#define _snode_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct snode {
  int size;
  void * data;
  struct snode *next;
};

struct snode * snode_create(void * data, int size); 

void snode_destroy(struct snode* s);

#endif //_snode_H_