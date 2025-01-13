#include <stdio.h>

int top = -1;
int number_stack[10];

void push(int max){
    if (top == max - 1){
        printf("Stack cannot be pushed as stack is overflowing.\n");
    }
    else{
        
        int value;
        printf("Input value to be pushed: ");
        scanf("%d", &value);
        number_stack[top + 1] = value;
    }
    top++;
}

void pop(){
    if (top == -1){
        printf("Stack cannot be popped as stack is underflowing.\n");
    }
    else{
        number_stack[top] = '\0';
        top--;
    }
    
}

void display(){
    printf("Displaying all elements:\n");
    
    for( int i = 0; number_stack[i] != '\0'; i++){
        printf("%d\t", number_stack[i]);
    }
    
    printf("\n");
}


int main()
{
    int max = 10;
    while(1){
        int option = 0;
        
        printf("\n#############################\n");
        printf("Input a number for the corresponding option you would like to execute on the stack:\n");
        printf("[1] Push\n[2] Pop\n[3] Display\n[4] Exit\n");
        
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                push(max);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting out of the program.");
                return 0;
            default:
                printf("Enter a Valid Option.");
        }
    }

    return 0;
}