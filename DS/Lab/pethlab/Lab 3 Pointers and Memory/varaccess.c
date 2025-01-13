#include <stdio.h>

int main() {
    int num2[] = {545,67,78,324};
    for(int i = 0; i < 4; i++){
        printf("VALUE %d", num2[i]);
        printf("\tADDRESS %u\n", &num2[i]);
    }
}
