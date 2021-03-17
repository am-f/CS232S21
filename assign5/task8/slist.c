#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "slist.h"
#include "snode.h"

struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};

struct slist *slist_create() {
  struct slist * newList = (struct slist *)malloc(sizeof(struct slist));
  newList->front = NULL;
  newList->back = NULL;
  return newList;
}

struct snode * slist_add_back(struct slist *l, void * data, int size) {
  struct snode * temp = snode_create(data, size);
  if(l->front == NULL) {
    l->front = temp;
    l->back = temp;
  }
  else {
    l->back->next = temp;
    l->back = temp;
  }
  return l->back;
}

struct snode * slist_add_front(struct slist *l, void * data, int size) {
  struct snode * temp = snode_create(data, size);
  if(l->front == NULL) {
    l->front = temp;
    l->back = temp;
  }
  else {
    temp->next = l->front;
    l->front = temp;
  }
  return l->front;
}

int voidComp(struct snode * finger, void * data, int dataSize) { //returns 1 if *(finger->data) has same content as *data; returns 0 if not
  if(finger->size != dataSize) {
    return 0;
  }
  else {
    uint8_t * fingertemp = (uint8_t *)finger->data;
    uint8_t * datatemp = (uint8_t *)data;
    for(int i = 0; i < finger->size; i++) {
      if(*(fingertemp + i) != *(datatemp + i)) {
        return 0;
      }
    }
    return 1;
  }
}

struct snode* slist_find(struct slist *l, void * data, int dataSize) {
  struct snode * finger = l->front;
  int comp = voidComp(finger, data, dataSize);
  while(comp != 1) {
    finger = finger->next; 
    if(finger == NULL) {
      return NULL;
    }
    comp = voidComp(finger, data, dataSize);
  }
  return finger;
}

void slist_destroy(struct slist *l) {
  struct snode * del = l->front;
  struct snode * hold = l->front->next;
  while(del != l->back) {
    snode_destroy(del);
    del = hold;
    hold = hold->next;
  }
  snode_destroy(del);
  free(l);
}

void slist_traverse(struct slist *l) {
  struct snode * node = l->front;
  while(node != NULL) {
    printf("%s\n", (char *)node->data);
    node = node->next;
  }
}

uint32_t slist_length(struct slist *l) {
  uint32_t length = 0;
  struct snode * node = l->front;
  while (node != NULL) {
    length++;
    node = node->next;
  }
  return length;
}

void slist_delete(struct slist *l, void * data, int dataSize) {
  struct snode * finger = l->front;
  struct snode * pre = l->front;
  int comp = voidComp(finger, data, dataSize);
  if(comp == 1) {
    l->front = finger->next;
    snode_destroy(finger);
  }
  else {
    finger = finger->next;
    comp = voidComp(finger, data, dataSize);
    while(comp != 1 && finger->next != NULL) {
      pre = pre->next;
      finger = finger->next;
      comp = voidComp(finger, data, dataSize);
    }
    if(finger == l->back) {
      l->back = pre;
    }
    pre->next = finger->next;
    snode_destroy(finger);
  }
}

void deadbeef() {
  printf("\n ..................\n |     /)  (\\     |\n |.-._((,~~.))_.-,|\n | `-.  X  X  ,-\' |\n |   / ,o--o. \\   |\n |  ( ( .--. ) )  |\n |   ) `----\' (   |\n |  /   i am   \\  |\n | /  deadbeef  \\ |\n |/..............\\|\n\n");
  //adapted from: http://www.asciiworld.com/-Cows-.html
  printf("enjoy your weekend! :)\n\n");
  return;
}