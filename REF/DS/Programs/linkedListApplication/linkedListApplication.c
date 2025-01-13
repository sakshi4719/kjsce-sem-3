#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
} poly1, poly2;

void createNode(struct Node** headPtr, int coeff, int expo);
int listSize(struct Node* node);
struct Node* swap(struct Node* ptr1, struct Node* ptr2);
void sortList(struct Node** head, int count);
void printList(struct Node* node);
void addPoly(struct Node* poly1, struct Node* poly2, struct Node* poly);

int main()
{
    struct Node* poly1Start = NULL;
    struct Node* poly2Start = NULL;
    struct Node* resultPoly = NULL;
    int choice = 0;
    printf("MENU\n1. Add term\n2. Display polynomial\n3. Done\n");
    printf("Create polynomial 1\n");
    while(choice != 3)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                {
                    int coeff, expo;
                    printf("Enter coefficient: ");
                    scanf("%d", &coeff);
                    printf("Enter exponent: ");
                    scanf("%d", &expo);
                    createNode(&poly1Start, coeff, expo);
                    break;
                }
            case 2:
                {
                    int size = listSize(poly1Start);
                    sortList(&poly1Start, size);
                    printList(poly1Start);
                    break;
                }
            case 3:
                break;
        }
    }
    printf("Create polynomial 2\n");
    choice = 0;
    while(choice != 3)
    {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                {
                    int coeff, expo;
                    printf("Enter coefficient: ");
                    scanf("%d", &coeff);
                    printf("Enter exponent: ");
                    scanf("%d", &expo);
                    createNode(&poly2Start, coeff, expo);
                    break;
                }
            case 2:
                {
                    int size = listSize(poly2Start);
                    sortList(&poly2Start, size);
                    printList(poly2Start);
                    break;
                }
            case 3:
                break;
        }
    }

    addPoly(poly1Start, poly2Start, resultPoly);
    printList(resultPoly);

    return 0;
}

void createNode(struct Node** headPtr, int coeff, int expo)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> coeff = coeff;
	newNode -> expo = expo;
	newNode -> next = (*headPtr);
	(*headPtr) = newNode;
}

int listSize(struct Node* node)
{
    int count = 0;
    while (node != NULL)
	{
        count += 1;
		node = node -> next;
	}
	return count;
}

struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1 -> next = tmp;
    return ptr2;
}

void sortList(struct Node** head, int count)
{
    struct Node** h;
    int i, j, swapped;
    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            struct Node* p1 = *h;
            struct Node* p2 = p1 -> next;
            if (p1 -> expo > p2 -> expo)
            {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h) -> next;
        }
        if (swapped == 0)
            break;
    }
}

void printList(struct Node* node)
{
    printf("[ ");
	while (node != NULL)
	{
		printf("(%d,%d) ", node -> coeff, node -> expo);
		node = node -> next;
	}
	printf("]\n");
}

void addPoly(struct Node* poly1, struct Node* poly2, struct Node* poly)
{
    while (poly1->next && poly2->next) {
        if (poly1->expo > poly2->expo) {
            poly->expo = poly1->expo;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }

        else if (poly1->expo < poly2->expo) {
            poly->expo = poly2->expo;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            poly->expo = poly1->expo;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        poly->next = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
    while (poly1->next || poly2->next) {
        if (poly1->next) {
            poly->expo = poly1->expo;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if (poly2->next) {
            poly->expo = poly2->expo;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = (struct Node*)malloc(sizeof(struct Node));
        poly = poly->next;
        poly->next = NULL;
    }
}

//struct Node* addPoly(struct Node* poly1, struct Node* poly2)
//{
//    struct Node* resultPoly = NULL;
//    while(poly1 != NULL)
//	{
//	    int exponent = poly1 -> expo;
//	    while(poly2 != NULL)
//        {
//            if(poly2 -> expo == exponent)
//            {
//                createNode(&resultPoly, poly1 -> coeff + poly2 -> coeff, exponent);
//                break;
//            }
//            else
//            {
//                createNode(&resultPoly, poly1 -> coeff, poly1 -> expo);
//            }
//        }
//		poly1 = poly1 -> next;
//	}
//    return resultPoly;
//};
