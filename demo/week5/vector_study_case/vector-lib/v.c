#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
int main(int argc, char **argv) {
    vector_t *v; //vector pointer
	v = vector_new(); //new vector
	printf("%d", vector_get(v, 0)); //v, idx
	vector_set(v, 0, 98); //v, i, value
	printf("%d", vector_get(v,0)); //v, idx
    vector_delete(v); //delete vector
	return 0;
}

