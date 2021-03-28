#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * node1 = (node_t *)malloc(sizeof(node_t));
    node_t * node2 = (node_t *)malloc(sizeof(node_t));
    node_t * node3 = (node_t *)malloc(sizeof(node_t));
    
    node_t * head = node1;

    strcpy(node1->str, "hello");
    node1->length = strlen("hello");
    node1->next = node2;

    strcpy(node2->str, "there");
    node2->length = strlen("there");
    node2->next = node3;

    strcpy(node3->str, "prof");
    node3->length = strlen("prof");
    node3->next = NULL;
    
   return head;
}

void teardown(node_t * head) {
  free(head->next);
  free(head);
}

void add(node_t ** head, char * str, int length){
  node_t * temp = *head;
  *head = (node_t *)malloc(sizeof(node_t));
  strcpy((*head)->str, str);
  (*head)->length = length;
  (*head)->next = temp;
}

void delete_node_at(node_t ** head, int idx) {
  node_t * node = *head;
  node_t * before = *head;
  if(idx == 0) {
    *head = (*head)->next;
    free(node);
  }
  else {
    for(int i = 0; i < idx - 1; i++) {
      before = before->next;
    }
    node = before->next;
    before->next = node->next;
    free(node);
  }
} 

void delete_node_key(node_t **head, char * key) {
  node_t * node = *head;
  node_t * before = *head;
  int comp = strcmp(node->str, key);
  if(comp == 0) {
    *head = (*head)->next;
    free(node);
  }
  else {
    while(comp != 0) {
      comp = strcmp(before->next->str, key);
      if(comp == 0) {
        break;
      }
      before = before->next;
    }
    node = before->next;
    before->next = node->next;
    free(node);
  }
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}
