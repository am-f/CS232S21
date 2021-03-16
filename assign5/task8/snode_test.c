#include <stdio.h>
#include "snode.h"

// global variables (data segment)

struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  
  n1 = snode_create("hello", sizeof("hello"));
  n2 = snode_create("there", sizeof("there"));
  n3 = snode_create("prof", sizeof("prof"));


  // manually "link" the nodes together.
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  // p points to node n1 initially
  p = n1;


  while (p != NULL) {
  
  
    printf("str: %s - length: %d\n", (char *)p->data, p->size - 1);

    p = p->next;
  }

  snode_destroy(n1);

  return 0;
}
