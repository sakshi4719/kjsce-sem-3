#include<stdio.h>
#include <stdlib.h>

int main()
{
    int a[20], n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements in sorted ascending order: \n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &x);

    int start = 0;
    int end = n - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == x)
            i = mid;

        if (a[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }

    if(i < n)
        printf("Element found at index %d", (i+1));
    else
        printf("Element not found");

    return 0;
}
