
/* 
	1. Implement and test a power function (for positive integer exponents only). A call to your function should compute baseexp and might look like:
		
	result = power(base, exp);

*/

#include <stdio.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = result * base;
    }
    return result;
}


int main(void) {
    int exp = 3;
    int base = 4;
    int result;
    result = power(base, exp);
    printf("%d\n", result);
    return 0;
}