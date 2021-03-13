#include "vector.h"
#include "frame.h"
typedef struct vector {
   int size;
   frame_t ** data; //point to an array
} vector_t;


vector_t * vector_new(){
	vector_t * ret = (vector_t*) malloc(sizeof(vector_t));
	if(ret == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}
	ret->size = 1;
	ret->data = (frame_t **) malloc(sizeof(frame_t*));
	if(ret->data == NULL) {
	//malloc has failed. out of memory
		perror("failed alloc");
		return NULL;
	}

	//ret->data[0]=0; from original
	return ret;

}
void vector_delete(vector_t * v){
 for(int i = v->size; i >= 0; i++) {
   free(v->data[size]);
 }
 free(v->data);
 free(v);
}

void vector_set(vector_t* v,  int loc,  frame_t* val){
	if(loc<v->size && loc>=0) {
   	    v->data[loc] = val;
   	} 
     /* old
     else {
 	    v->data = (frame **) realloc(v->data, sizeof(frame*)*(loc+1));
	    for(int i= v->size; i<loc+1; i++)
		  v->data[i] = 0;
 	    v->data[loc] = val;
	    v->size = loc+1; 
      */
	}	

}

int vector_get(vector_t *v, int loc){
   if(loc<v->size && loc>=0) {
   	return  v->data[loc];
   } else {
  	perror("blahblah");
       return 0;	
   }
}


