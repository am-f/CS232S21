#include <stdio.h>
#include <stdlib.h>
#include "vector.h" //include basically just copies whatevers in that file and pastes it here
typedef struct vector {
  int size;
  int * data; //point to a dynamic array of int data
} vector_t;

//Current memory diagram:
//stack           | heap
//retval----------+--->[size: ]
//                |    [data:--]-----
//                |                 |
//                |   ---------------
//                |   |
//                |   --> [0]
//vector_set(v, 0, 9);//good to go, no need to expand;
//vector_set(v, 2, 2);//this is out of bounds of current array! we need to expand (but obv we still want memory to be adjacent) so we need to create new, larger array, and copy over! (just like java arraylist)

vector_t * vector_new() {
  //todo
  vector_t * retval = (vector_t *)malloc(sizeof(vector_t));
  if(retval == NULL) {
    //game over, out of memory
    perror("failed allocation");//stderr (standard error), like stdin and stdout
    return NULL;
  }

  retval->size = 1; 
  retval->data = (int *)malloc(sizeof(int) * 1);
  if(retval->data == NULL) {
    perror("failed to allocate data, OOM");
    return NULL;
  }
  retval->data[0] = 0;
  return retval;

}

void vector_delete(vector_t * p) {
  free(p->data);
  free(p);
}
//Current memory diagram:
//stack           | heap
//retval----------+--->[size:3 ]
//                |    [data:--]-----
//                |                 |
//                |   ---------------
//                |   |
//                |   --> [0|0|2]
//                |   temp-> [0] //free this
void vector_set(vector_t * p_v, int loc, int val) {
  //todo
  if(loc < p_v->size && loc>= 0) {
    //enough size
    p_v->data[loc] = val;
  }
  else {
    //expand
    //we will create a bigger dyn array, copy the stuff from p_v->data over
    //swap the new array in, and release the old array
  /* our implementation of realloc */
  /*
    p_v->data = (int *)malloc(sizeof(int) * (loc+1)); //need to do + 1 because loc=5 is actually 6th item of array
    //arraylist impl, size is always doubled
    int * temp_pointer = p_v->data;
    for(int i=0; i<p_v->size; i++) {
      p_v->data[i] = temp_pointer[i];
    }
    free(temp_pointer);
    */
  /* end of our realloc */
  p_v->data = (int *)realloc(p_v->data, sizeof(int)*(loc+1));
    for(int i =p_v->size; i<loc+1; i++) {
      p_v->data[i] = 0;
    }
    //expansion is over
    p_v->data[loc] = val;
    p_v->size = loc + 1;
  }
}

int vector_get(vector_t *p_v, int loc) {
  if(loc<p_v->size && loc>= 0) {
    return p_v->data[loc];
  }
  else {
    perror("refuse to serve you");
    return 0;
  }
}
