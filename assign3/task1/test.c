#include <stdio.h>

int main(int argc, char ** argv) {
    int a = atoi(argv[1]); //atoi converts string to int
    unsigned int uA = (unsigned int)a;
    //unsigned int uA = atoi(argv[1]);
    int b = atoi(argv[2]);
    unsigned int uB = (unsigned int)b;
    printf("%u\n", a);
    printf("%u\n", uA);
    printf("%d\n", a);
    printf("%d\n", uA);
    printf("%u\n", a >> 1);
    printf("%u\n", uA >> 1);
    printf("%d\n", a >> 1);
    printf("%d\n", uA >>1);
    //printf("%u\n", uB >> 1);
    
    return 0;
}