#include <stdio.h>
#include <math.h>

int input_number();
int binary_to_decimal(int bin);
int decimal_to_binary(int deci);
int compute_length(int num);
void test_to_deci();
void test_to_bin();
int twos_comp(int bin);
void test_twos_comp();

int num[] = {1,1,0,1,0};

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

int twos_comp(int bin){
    int comp = 0;
    int reached_one = 0;
    for(int i = 0; bin != 0; i++){
        int digit = bin % 10;
        printf("\n DIGIT %d \n ", digit);
        bin /= 10;
        if (reached_one){
            if (digit)
                digit = 0;
            else
                digit = 1;
        }
        comp += digit * pow(10, i);
        num[i] = digit;
        if (digit){
            reached_one = 1;
        }
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
    int bin = 10110;
    int result = twos_comp(bin);
    printf("%d", result);
    printf("\n");
    for (int i =0; i <5; i++)
      printf("%d", num[i]);
    
}

void booth_algo(){
  int m[5] = {0, 1, 0, 0, 1};
  int q[5] = {0, 0, 1, 0, 1};
  
  int q0 = 0;
  
  int a[];
  
  for (int i = 0; i < 6; i++){
    if (q[i] == 1 &&  q0 == 0)
      
  }
  
  
}


















