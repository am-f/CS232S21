#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation 
    struct node* next;
} node_t;

node_t * construct_3_strs() {

  node_t *x; //CS232
  node_t *y; //is
  node_t *z; //awesome

  x = (node_t *)malloc(sizeof(node_t));
  x->value = (char *)malloc(6);
  *(x->value) = 'C';
  *(x->value+1) = 'S';
  *(x->value+2) = '2';
  *(x->value+3) = '3';
  *(x->value+4) = '2';
  *(x->value+5) = '\0';

  y = (node_t *)malloc(sizeof(node_t));
  y->value = (char *)malloc(3);
  *(y->value) = 'i';
  *(y->value+1) = 's';
  *(y->value+2) = '\0';

  z = (node_t *)malloc(sizeof(node_t));
  z->value = (char *)malloc(8);
  *(z->value) = 'a';
  *(z->value+1) = 'w';
  *(z->value+2) = 'e';
  *(z->value+3) = 's';
  *(z->value+4) = 'o';
  *(z->value+5) = 'm';
  *(z->value+6) = 'e';
  *(z->value+7) = '\0';

  x->next = y;
  y->next = z;
  z->next = x;

  return x;
}

void dealloc(node_t * x) {
  free(x->next->next->value);
  free(x->next->next);
  free(x->next->value);
  free(x->next);
  free(x->value);
  free(x);
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
  node_t * x = construct_3_strs();
  return dump_all(x);
}

int dump_all(node_t * x) {
  printf("x -> %s", x->value);
  node_t * y = x->next;
  printf(" %s", y->value);
  node_t * z = y->next;
  printf(" %s\n", z->value);
  if(z->next != x) {
  	printf("failed");
    dealloc(x);
	   return -1;
  } else {
      dealloc(x);
      return 0;
  }
}

