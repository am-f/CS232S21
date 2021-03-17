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
  free(head->next->next);
  free(head->next);
  free(head);
}

void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
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
