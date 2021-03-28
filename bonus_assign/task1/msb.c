#include <stdio.h>
#include <stdlib.h>

int msb(int x);
void print_binary(int n);

//Please do not modify main().
//All your changes must be made within msb()
int main(int argc, char **argv) {
	if (argc<2) {
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
		return 1;
	}
	int x=atoi(argv[1]);
	printf("X= "); 
	print_binary(x); 
	printf("\n");
	printf("The most significant bit of %d is at position %d\n",x,msb(x));
	return 0;
}

int msb(int x) {
	if (x==0) return -1;                  
	int w, ep, hw;
	w=32;
	ep=0;
  hw = w;
	while(hw > 1) {
    hw = hw/2;
    unsigned int maskBase = 0xffffffff;
    unsigned int mask = maskBase>>(w-hw);
    mask = mask<<(hw+ep);
		printf("M= "); print_binary(mask); printf(" hw=%d ep=%d\n",hw,ep);
    unsigned int xHalf = x & mask;
    if(xHalf > 0) {
      ep = ep + hw;
    }
	}
	return ep;
}

//Do not modify print_binary
void print_binary(int n) {
	int i;
	for(i=31;i>=0;i--) {
		printf("%c",(n&1<<i)?'1':'0');
		if (0==i%4) printf(" ");
	}
}
