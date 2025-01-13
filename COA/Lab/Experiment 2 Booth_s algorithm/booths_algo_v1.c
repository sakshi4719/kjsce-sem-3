// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int input_number();
int binary_to_decimal(int bin);
int decimal_to_binary(int deci);
int compute_length(int num);
void test_to_deci();
void test_to_bin();
int * ones_comp(int bin, int length);
void test_twos_comp();

int main(){
    test_twos_comp();
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

int decimal_to_binary(int deci){
    int bin = 0;
    for(int i = 0; deci != 0; i++){
        int digit = deci % 2;
        deci /= 2;
        if (digit == 1){
            bin += digit * pow(10, i);
        }
    }
    return bin;
}

int * ones_comp(int bin, int length){
    static int comp[length];
    for(int i = 0; i < length; i++){
        int digit = bin % 10;
        printf("\n DIGIT %d \n ", digit);\
        bin /= 10;
        int digit_comp;
        if (digit){
            digit_comp = 0;
        }
        else{
            digit_comp = 1;
        }
        comp[i] = digit_comp * pow(10, i);
    }
    return comp;
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



void test_to_deci(){
    int bin = input_number();
    int deci;
    printf("binary num is %d\n", bin);
    
    printf("calling converter...\n");
    deci = binary_to_decimal(bin);
    
    printf("Decimal number is %d", deci);
}

void test_to_bin(){
    int deci = input_number();
    int bin;
    printf("decimal num is %d\n", deci);
    
    printf("calling converter...\n");
    bin = decimal_to_binary(deci);
    
    printf("binary number is %d", bin);
}

void test_twos_comp(){
    int bin = 1000;
    int length = compute_length(bin);
    int *presult;
    //memset(result, 0, length*length*sizeof(int) );
    int *presult = ones_comp(bin, length);
    for(int i =0 ; i < length; i++){
        printf("%d", *presult[i]);
    }
    
}

















