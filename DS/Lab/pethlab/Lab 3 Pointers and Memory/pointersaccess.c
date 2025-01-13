#include <stdio.h>

int main() {
    int num1[] = {23, 44, 55, 78};
    int *j = &num1[0];
    for(int i = 0 ; i < 4; i++){
        printf("VALUE %d", *j);
        printf("\tADDRESS %u\n", j);
        j++;
    }
}
