#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t * construct_3() {

  node_t *x;
  node_t *y;
  node_t *z;

  x = (node_t *)malloc(sizeof(node_t));
  x->value = 1;
  y = (node_t *)malloc(sizeof(node_t));
  y->value = 2;
  z = (node_t *)malloc(sizeof(node_t));
  z->value = 3;

  x->next = y;
  y->next = z;
  z->next = x;

  return x;
}

void dealloc(node_t * x) {
  free(x->next->next);
  free(x->next);
  free(x);
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {

    node_t * x = construct_3();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %d\n", x->value);
    node_t * y = x->next;
    printf("%d -> %d\n", x->value, y->value);
    node_t * z = y->next;
    printf("%d -> %d\n", y->value, z->value);
    if(z->next != x) {
    	printf("failed");
      dealloc(x);
	  return -1;
    } else {
        printf("%d -> %d\n", z->value, x->value);
        dealloc(x);
        return 0;
    }
}

