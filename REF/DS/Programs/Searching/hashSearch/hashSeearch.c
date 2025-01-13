#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 7

int size = 0;

void insert(int hashTable[], int data)
{
    int index = data % CAPACITY;
    if(hashTable[index] == 0)
    {
        hashTable[index] = data;
        size++;
    }
    else
    {
        printf("Collison occured!\n");
    }
}

void findElement(int hashTable[], int value)
{
    int index = value % CAPACITY;
    if(hashTable[index] != value)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nFound at index %d\n", index);
    }
}

int main()
{
    int element, i, x;
    int hashTable[CAPACITY] = {};

    while(size < CAPACITY)
    {
        printf("Enter element: ");
        scanf("%d", &element);
        insert(hashTable, element);
    }

    printf("\nDisplaying hash table:\n");
    for(i = 0; i < CAPACITY; i++)
    {
        printf("%d\t", hashTable[i]);
    }

    printf("\n\nFind element: ");
    scanf("%d", &x);
    findElement(hashTable, x);
    return 0;
}
