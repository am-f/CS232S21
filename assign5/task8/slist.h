#ifndef _slist_H_
#define _slist_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snode.h"

struct slist;

struct slist* slist_create();

struct snode* slist_add_back(struct slist *l, void * data, int size);

struct snode* slist_add_front(struct slist *l, void * data, int size);

struct snode* slist_find(struct slist *l, void * data, int size);

void slist_destroy(struct slist *l);

void slist_traverse(struct slist *l);

uint32_t slist_length(struct slist *l);

void slist_delete(struct slist *l, void * data, int size);

void deadbeef();

#endif // _slist_H_
