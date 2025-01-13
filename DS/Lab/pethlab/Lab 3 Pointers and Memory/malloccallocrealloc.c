#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);

    // int* ptr = (int*)malloc(n * sizeof(int));
    int* ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated");
        exit(0);
    }
    else{
        for (int i = 0; i < n; i++) {
            printf("Enter an element in the array: ");
            scanf("%d", &ptr[i]);
        }

        printf("\n\n");

        for(int i = 0; i < n; i++){
            printf("VALUE %d", ptr[i]);
            printf("\t%d", *(ptr + i));
            printf("\tADDRESS %u\n", &ptr[i]);
        }
    }

    printf("\n\n");

    int m;
    printf("Enter number of elements:");
    scanf("%d",&m);

    ptr = realloc(ptr, (m * sizeof(int)));

    if (ptr == NULL) {
        printf("Memory not allocated");
        exit(0);
    }
    else{
        for (int i = n; i < m; i++) {
            printf("Enter an element in the array: ");
            scanf("%d", &ptr[i]);
        }
        printf("\n\n");
        for(int i = 0; i < m; i++){
            printf("VALUE %d", ptr[i]);
            printf("\t%d", *(ptr + i));
            printf("\tADDRESS %u\n", &ptr[i]);
        }
    }
}
