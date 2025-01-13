#include <stdio.h>
#include <stdlib.h>

void restoring_division(int * m, int * q, int size);

int main()
{
    int m[] = {0, 0, 1, 0, 0};
    int q[] = {0, 1, 0, 0, 1};
    
    int *pm = m;
    int *pq = q;
    restoring_division(pm, pq, 5);
    
    
    return 0;
}

void restoring_division(int * m, int * q, int size){
    int * a = (int *)calloc(size, sizeof(int));
    
    printf("m:");
    for (int i = 0; i < size; i++)
            printf("%d", m[i]);
    printf("\ta: ");
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\tq: ");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);

    // TWOS COMP    
    int * mcomp = (int *)calloc(size, sizeof(int));
    int found_one = 0;
    for(int j = 1; j <= size; j++) {
        int place = size - j;
        int digit = m[place];
        if (found_one == 1) {
            if(digit == 1)
                mcomp[place] = 0;
            else
                mcomp[place] = 1;
            continue;
        }
        mcomp[place] = m[place];
        if (m[place] == 1)
            found_one = 1;
    }
    
    printf("\nM 2's COMP:\t");
    for (int i = 0; i < size; i++)
        printf("%d", mcomp[i]);
    printf("\n");
    
    for (int i = 0; i < size; i++){
        printf("\n------------- CYCLE %d -----------\n", i + 1);
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\t");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);
        printf("\n");
        
        
        // LEFT SHIFT
        for (int j = 1; j < size; j++){
            a[j - 1] = a[j];
        }
        a[size - 1] = q[0];
        for (int j = 1; j < size; j++){
            q[j - 1] = q[j];
        }
        
        printf("After Left Shift: ");
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\t");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);
        printf("\n");
        
        // A -> A + (-M)
        int c = 0;
        for (int j = 1; j <= size; j++){
            int p = size - j;
            int sum = mcomp[size - j] + a[size - j] + c;
            if(sum == 3){
                a[size - j] = 1;
                c = 1;
            }
            else if (sum == 2){
                a[size - j] = 0;
                c = 1;
            }
            else if (sum == 1){
                a[size - j] = 1;
                c = 0;
            }
            else {
                a[size - j] = 0;
                c = 0;
            }
        }
        printf("After A -> A + (-M): ");
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\t");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);
        printf("\n");
        
        if (a[0] == 1){
            q[size - 1] = 0;
        
            // A -> A + M
            int c = 0;
            for (int j = 1; j <= size; j++){
                int p = size - j;
                int sum = m[size - j] + a[size - j] + c;
                if(sum == 3){
                    a[size - j] = 1;
                    c = 1;
                }
                else if (sum == 2){
                    a[size - j] = 0;
                    c = 1;
                }
                else if (sum == 1){
                    a[size - j] = 1;
                    c = 0;
                }
                else {
                    a[size - j] = 0;
                    c = 0;
                }
            }
            
        }
        else{
            q[size - 1] = 1;
        }

        // PRINTING CYCLE
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\t");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);

    }
    
    
    
}

