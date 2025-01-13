#include <stdio.h>

void input(int index);
void add();
void subtract();
void multiple();
void equality();


int nums[2][2];
int result[2];

int main() {
    int option;
    int stop = 0;
    
    for(int i=0; i < 2 ; i++){    
        printf("Input the values of number %d:\n", (i + 1));
        input(i);
    }
    
    while( !stop ){
        printf("\n\nSelect an option to execute the associated operation:\n");
        printf("[1] Add\n[2] Subtract\n3] Multiple\n[4] Compare\n[5] Exit Program.\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiple();
                break;
            case 4:
                equality();
                break;
            case 5:
                printf("Exiting Program.\n");
                stop = 1;
                break;
            default:
                printf("Enter a valid option.\n\n");
        }
        if (option == 1 || option == 2 || option == 3){
            printf("The resultant complex number is: (%d) + (%di)\n", result[0], result[1]);
        }
    }
    
    

    return 0;
}

void input(int index){
    int real;
    int imag;
    
    printf("Enter the real part of the complex number: ");
    scanf("%d", &real);
    
    printf("Enter the imaginary part of the complex number: ");
    scanf("%d", &imag);
    
    nums[index][0] = real;
    nums[index][1] = imag;
}

void add(){
    result[0] = nums[0][0] + nums[1][0];
    result[1] = nums[0][1] + nums[1][1];
    
}

void subtract(){
    result[0] = nums[0][0] - nums[1][0];
    result[1] = nums[0][1] - nums[1][1];
}

void multiple(){
    result[0] = (nums[0][0] * nums[1][0]) - (nums[1][1] * nums[1][1]);
    result[1] = (nums[0][0] * nums[1][1]) + (nums[0][1] * nums[1][0]);
}

void equality(){
    if ((nums[0][0] == nums[1][0]) && (nums[0][1] == nums[1][1])){
        printf("The complex numbers are equal.");
    } 
    else {
        printf("The complex numbers are unequal.");
    }
}


































    