typedef struct vector vector_t; //called "forward declaration"
//basically saying: you can use this, but don't ask me how it works

//func prototypes
vector_t * vector_new();
void vector_delete(vector_t * p);
void vector_set(vector_t * p_v, int loc, int val);
int vector_get(vector_t *p_v, int loc);
