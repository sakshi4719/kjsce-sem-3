#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int input_number();
int binary_to_decimal(int bin);
int * decimal_to_binary(int deci);
int compute_length(int num);
void booth_algo(int * m, int * q, int size);

int main(){
    
    int mDeci;
    printf("Enter Multiplicand: ");
    scanf("%d", &mDeci);
    
    // printf("df");
    int *pm = decimal_to_binary(mDeci);
    
    int deci_q = 0;
    printf("Enter Multiplier: ");
    scanf("%d", &deci_q);
    int *pq = decimal_to_binary(deci_q);
    
    // int m[] = {1, 0, 1, 1};
    // int q[] = {0, 1, 0, 0};
    
    // int *pm = &m;
    // int *pq = &q;
    booth_algo(pm, pq, 4);
    
    
    return 0;
}


int binary_to_decimal(int bin){
    int length = compute_length(bin);
    int deci = 0;
    for(int i = 0; i < length; i++){
        int digit = bin % 10;
        bin /= 10;
        if (digit == 1){
            deci += digit * pow(2, i);
        }
        
    }
    return deci;
}

int * decimal_to_binary(int deci){
    int bin[4]; 
    
    if(deci < 0){
        bin[0] = 1;
        deci = abs(deci);
        printf("DECIMAL %d\n", deci);
    }
    else
        bin[0] = 0;
    for(int i = 0; i < 4 ; i++){
        int digit = deci % 2;
        deci /= 2;
        // if (digit == 1){
        //     bin[4 - i] = digit;
        // }
        // else
        printf("\t%d\t%d\t%d\n", i, deci, digit);
        bin[4 - i] = digit;
        printf("%d\n", bin[i]);
    }
    if (bin[0] == 1){
        for (int i=1; i < 4; i++){
            if (bin[i] == 1)
                bin[i] = 0;
            else
                bin[i] = 1;
        }
    }
    
    printf("BINARY: ");
    for(int i =0; i< 5; i++)
        printf("%d", bin[i]);
    printf("\n");
        
    
    return bin;
}

int compute_length(int num){
    int length = floor(log10(num)) + 1;
    return length;
}

int input_number(){
    int num = 0;
    printf("Input a number: ");
    scanf("%d", &num);
    return num;
}

void booth_algo(int * m, int * q, int size){
    
    int q0 = 0;
    int * a = (int *)calloc(size, sizeof(int));
    
    printf("m: ");
    for (int i = 0; i < size; i++)
            printf("%d", m[i]);
    printf("\ta: ");
    for (int i = 0; i < size; i++)
        printf("%d", a[i]);
    printf("\tq: ");
    for (int i = 0; i < size; i++)
        printf("%d", q[i]);
    printf("\tq (-1): %d\n", q0);

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
        printf("\t%d", q0);
        printf("\n");
        
        if (q[size - 1] == 0 &&  q0 == 1){
            
            // ADD a and m
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
            printf("After A -> A + M: ");
            for (int i = 0; i < size; i++)
                printf("%d", a[i]);
            printf("\t");
            for (int i = 0; i < size; i++)
                printf("%d", q[i]);
            printf("\n");
            
            
        }
        else if (q[size - 1] == 1 && q0 == 0){

            // ADD a and mcomp
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
        }
            
        
        // RIGHT SHIFT
        q0 = q[size - 1];
        for (int j = size - 1; j > 0 ; j--){
            q[j] = q[j - 1];
        }
        q[0] = a[size - 1];
        for (int j = size - 1; j > 0; j--){
            a[j] = a[j - 1];
        }
        a[0] = a[1];
        
        // PRINTING CYCLE
        for (int i = 0; i < size; i++)
            printf("%d", a[i]);
        printf("\t");
        for (int i = 0; i < size; i++)
            printf("%d", q[i]);
        printf("\t%d\n", q0);
    }
}