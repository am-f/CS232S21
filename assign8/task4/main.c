#include <stdio.h>
#include <string.h>
char password[8] = "secret";

int main() {
    char input[8];
    int a;

    printf("please enter your password\n");
    scanf("%s", input);

 
    for (a=0; a < 8; a++) { //if uppercase make lowercase
        if(input[a] > 64 && input[a] < 91) {
            input[a] = input[a]+32;
        }
    }

    if(strcmp(input, password)==0) {
        return 0;
    } else {
        return -1;
    }

}

