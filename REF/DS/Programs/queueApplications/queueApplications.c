#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
int priority;
struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
int main(){
  int ch;
  do{
    printf("\nPress 1: Insertion\nPress 2: Deletion\nPress 3: Display\nPress 4: Exit\n");
    scanf("%d",&ch);
    switch(ch){
      case 1:
      start = insert(start);
      break;

      case 2:
      start = delete(start);
      break;

      case 3:
      display(start);
      break;
    }
  }while(ch!=4);
}

struct node *insert(struct node *start){
  int val,pri;
  struct node *ptr, *p;
  ptr = (struct node *)malloc(sizeof(struct node));
  printf("Enter the value: ");
  scanf("%d",&val);
  printf("Enter the priority: ");
  scanf("%d",&pri);
  ptr->data = val;
  ptr->priority = pri;
  if(start == NULL || pri < start->priority){
    ptr->next = start;
    start =ptr;
  }
  else{
    p = start;
    while(p->next != NULL && p->next->priority <= pri){
      p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
  }
  return start;
}

struct node *delete(struct node *start){
struct node *ptr;
if(start == NULL){
  printf("\nUNDERFLOW");
}
else{
  ptr = start;
  printf("\nDeleted item is: %d",ptr->data);
  start = start->next;
  free(ptr);
}
return start;
}

void display(struct node *start){
  struct node *ptr;
  ptr = start;
  if(start == NULL){
    printf("\nQueue is Empty.");
  }
  else{
    printf("\nPriority Queue is: ");
    while(ptr != NULL){
      printf("\t%d[Priority=%d]",ptr->data,ptr->priority);
      ptr = ptr->next;
    }
  }
}
