#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

int stack[MAX];
char post[MAX];
int top = -1;
void pushstack(int x);
void evaluate(char c);
int main()
{
  int i,l;
  printf("Insert a postfix expression: ");
  scanf("%s",post);
  l=strlen(post);
  for(i = 0;i < l;i++)
  {
    if(post[i] >= '0' && post[i] <= '9')
    {
      pushstack(i);
    }
    if(post[i] == '+' || post[i]=='-' || post[i]=='*' || post[i]=='/' || post[i]=='^')
    {
      evaluate(post[i]);
    }
  }
  printf("\nResult : %d",stack[top]);
}

void pushstack(int x)
{
  top++;
  stack[top]=(int)(post[x]-48);
}

void evaluate(char c)
{
  int a,b,ans;
  a=stack[top];
  stack[top]='\0';
  top--;
  b=stack[top];
  stack[top]='\0';
  top--;
  switch(c)
  {
    case '+': ans=b+a;
    break;
    case '-': ans=b-a;
    break;
    case '*': ans=b*a;
    break;
    case '/': ans=b/a;
    break;
    case '^': ans=b^a;
    break;
    default: ans=0;
  }
  top++;
  stack[top]=ans;
}

