#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v);

/*
 * Tests that two arrays of size <size> are equal. Equal meaning that all the
 * elements in the arrays are equal.
 */
int array_equals(unsigned *arr1,
		unsigned *arr2,
		unsigned size) {

   int i;
   for (i = 0; i < size; i++) {
       if (arr1[i] != arr2[i]) {
           return 0;
       }
   }

   return 1;
}

/*
 * Prints an unsigned array as a bit string. This assumes that each integer
 * is only 0 or 1.
 */
void print_unsigned_array(	unsigned *arr1,
		        			unsigned size) {

    printf("0b");
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("%u", arr1[i]);
    }
}

void test_set_bits(	unsigned x,
                  	unsigned s,
		  			unsigned e,
                  	unsigned * v,
                  	unsigned expected) {
    unsigned o = x;
    set_bits(&x, s, e, v);
    if(x!=expected) {
        printf("set_bits(0x%08x,%u,%u,",o,s,e);
		print_unsigned_array(v, e - s + 1);
		printf("): 0x%08x, expected 0x%08x\n",x,expected);
		assert(0);
    } else {
        printf("set_bits(0x%08x,%u,%u,%u): 0x%08x, correct\n",o,s,e,*v,x);
    }
}

int main(int argc,
         const char * argv[]) {
	unsigned expectedArr[] = {1,0,1,0};
    printf("\nTesting set_bits()\n\n");
    
   test_set_bits(0b1001110,2,2,&expectedArr[1],0b1001010); //works 1
    test_set_bits(0b1101101,0,0,&expectedArr[1],0b1101100); //works 2

//works: 1, 2, 3, 4, 7, 8, 9, 10, 11
//doesn't work: 5, 6, 12, 13, 14
    test_set_bits(0b1001110,2,2,expectedArr,0b1001110); //works 3
    test_set_bits(0b1101101,0,0,expectedArr,0b1101101); //works 4
   
    test_set_bits(0b1001110,9,9,&expectedArr[1],0b1001110); //NO 5
    test_set_bits(0b1101101,4,4,&expectedArr[1],0b1101101); //NO 6
    test_set_bits(0b1001110,9,9,expectedArr,0b1001001110); //works 7
    test_set_bits(0b1101101,7,7,expectedArr,0b11101101); //works 8
    
    test_set_bits(0b111111,0,3,expectedArr,0b110101); //works 9
    test_set_bits(0b111111,2,5,expectedArr,0b010111); //works!! 10
    test_set_bits(0b111111,1,4,expectedArr,0b101011); //works 11

  
    test_set_bits(0,0,3,expectedArr,0b0101); //NO 12
    test_set_bits(0,2,5,expectedArr,0b010100); //NO 13
    test_set_bits(0,1,4,expectedArr,0b01010); //NO 14
    
    printf("\n");
    return 0;
}
