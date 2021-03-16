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

struct snode* slist_find(struct slist *l, void * data) {
  struct snode * finger = l->front;
  while(finger->data != data) {
    finger = finger->next; 
    if(finger == NULL) {
      return NULL;
    }
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

int voidComp(struct snode * finger, void * data, int dataSize) {
  if(finger->size != dataSize) {
    return 0;
  }
  else {
  unsigned char * fingertemp = (unsigned char *)finger->data;
  unsigned char * datatemp = (unsigned char *)data;
  for(int i = 0; i < finger->size; i++) {
    if(*(fingertemp + i) != *(datatemp + i)) {
      return 0;
    }
  }
  return 1;
  }
}

void slist_delete(struct slist *l, void * data, int dataSize) {
  struct snode * finger = l->front;
  struct snode * pre = l->front;
  int comp = voidComp(finger, data, dataSize);
  if(comp == 1) {
  //if(finger->data == data) {
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