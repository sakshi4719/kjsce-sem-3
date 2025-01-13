#include <stdlib.h>
#include <stdio.h>

double makerational(int x, int y);
double add(double x, double y);
double multiply(double x,double y);
void equal(double x, double y);

int main()
{
   int a,b,c,d;
   double r1,r2,sum,mult;
   printf("Enter the numerator for the first number: ");
   scanf("%d",&a);
   printf("Enter the denominator for the first number: ");
   scanf("%d",&b);
   r1 = makerational(a,b);
   printf("Enter the numerator of the second number: ");
   scanf("%d",&c);
   printf("Enter the denominator of the second number: ");
   scanf("%d",&d);
   r2 = makerational(c,d);
   int choice;
   while(1)
   {
       printf("1: Add\n2: Multiply\n3: Check equality\n4: Exit\n");
       printf("Enter choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
           sum = add(r1,r2);
           printf("%lf\n",sum);
           break;
       case 2:
           mult = multiply(r1,r2);
           printf("%lf\n",mult);
           break;
       case 3:
           equal(r1,r2);
           break;
       case 4:
           exit(0);
       default:
           printf("Enter a valid choice.");
           break;
       }
   }
   return 0;
}

double makerational(int x, int y)
{
   double rational;
   rational = (double)x/y;
   return rational;
}

double add(double x, double y)
{
   return x + y;
}

double multiply(double x,double y)
{
   return x*y;
}

void equal(double x, double y)
{
   if (x == y)
   {
      printf("True\n");
   }
   else
   {
      printf("False\n");
   }
}
