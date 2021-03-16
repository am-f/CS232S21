#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head;
    node_t * node1 = (node_t *)malloc(sizeof(node_t));
    node_t * node2 = (node_t *)malloc(sizeof(node_t));
    node_t * node3 = (node_t *)malloc(sizeof(node_t));
    head = node1;

    char str1[] = "hello";
    int i = 0;
    while(str1[i] != '\0') {
      *(node1->str+i) = str1[i];
      i++;
    }
    *(node1->str+i) = '\0';
    node1->length = 5;
    node1->next = node2;

    char str2[] = "there";
    int j = 0;
    while(str2[j] != '\0') {
      *(node2->str+j) = str2[j];
      j++;
    }
    *(node2->str+j) = '\0';
    node2->length = 5;
    node2->next = node3;

    char str3[] = "prof";
    int k = 0;
    while(str1[k] != '\0') {
      *(node3->str+k) = str3[k];
      k++;
    }
    *(node3->str+k) = '\0';
    node3->length = 4;
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
