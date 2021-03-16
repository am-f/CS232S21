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
  free(head->next);
  free(head);
}

void add(node_t ** head, char * str, int length){
  node_t * temp = *head;
  *head = (node_t *)malloc(sizeof(node_t));
  int i = 0;
  while(*(str + i) != '\0') {
    (*head)->str[i] = *(str + i);
    i++;
  }
  (*head)->str[i] = '\0';
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
int equalStrings(node_t * node, char * delKey) {
  int i = 1;
  while(i < node->length) {
    if(node->str[i] != *(delKey + i)) {
      return 0;
    }
    i++;
  }
  return 1;
}

void delete_node_key(node_t **head, char * key) {
  node_t * node = *head;
  node_t * before = *head;
  int comp = equalStrings(node, key);
  if(comp == 1) {
    *head = (*head)->next;
    free(node);
  }
  else {
    while(comp == 0) {
      comp = equalStrings(before->next, key);
      if(comp == 1) {
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
