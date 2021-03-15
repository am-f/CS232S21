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

struct snode * slist_add_back(struct slist *l, char *str) {
  struct snode * temp = snode_create(str);
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

struct snode * slist_add_front(struct slist *l, char *str) {
  struct snode * temp = snode_create(str);
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

struct snode* slist_find(struct slist *l, char *str) {
  struct snode * finger = l->front;
  while(strcmp(finger->str, str) != 0) {
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
    printf("%s\n", node->str);
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

void slist_delete(struct slist *l, char *str) {
  struct snode * finger = l->front;
  struct snode * pre = l->front;
  int comp = strcmp(finger->str, str);
  if(comp == 1) {
    l->front = finger->next;
    snode_destroy(finger);
  }
  else {
    finger = finger->next;
    comp = strcmp(finger->str, str);
    while(comp != 1 && finger != NULL) {
      pre = pre->next;
      finger = finger->next;
      comp = strcmp(finger->str, str);
    }
    if(finger == l->back) {
      l->back = pre;
    }
    pre->next = finger->next;
    snode_destroy(finger);
  }

}