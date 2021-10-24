/* MENU DRIVEN PROGRAM TO IMPLEMENT STACK OPEREATION 
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
struct stack{
  int a[maxsize];
  int top;
};
void display(struct stack S)
{  int i;
   printf("Stack contents are:\n");
   for(i=S.top;i>=0;i--)
   printf("%d \n",S.a[i]);
}
int pop(struct stack *S)
{  int p;
   if(S->top==-1)
    {  printf("The stack is empty\n");
       return(-1);
	}
	p=S->a[S->top];
	S->top=S->top-1;
	return (p);
}
void push(struct stack *S,int x)
{   if(S->top==maxsize-1)
      {   printf("The stack is full\n");
          return;
	  }
	  S->top=S->top+1;
	  S->a[S->top]=x;
      
}


int main(void) {
	struct stack S;
	int choice,x;
	S.top=-1;
	while(1)
	{  printf("**** MENU ****\n");
	   printf("1)PUSH\n");
	   printf("2)POP\n");
	   printf("3)DISPLAY\n");
	   printf("4)EXIT\n");
	   printf("Enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {  case 1:  printf("Enter the element \n");
	               scanf("%d",&x);
	               push(&S,x);
	               display(S);
	   	            break;
	   	  case 2:  x=pop(&S);
	   	            if(x!=-1)
	   	           printf("The popped element is %d\n",x);
	   	           display(S);
	   	  	        break;
	   	  case 3:  display(S);
	   	  	        break;

	   }
	   if(choice==4)
	   break;
	}
	return 0;
}
