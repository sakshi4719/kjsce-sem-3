#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int size)
{
    int i;
    for (i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        while(key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int main()
{
    int size, element, i;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];
    for(i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &element);
        array[i] = element;
    }

    insertionSort(array, size);
    printf("Sorted array (using insertion sort) in ascending order:\n");
    printArray(array, size);
    return 0;
}
