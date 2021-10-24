/*  Program to check the balance of paranthesis
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
struct stack{
	char a[maxsize];
	int top;
};
int pop(struct stack *S)
{  
	S->top=S->top-1;
}
void push(struct stack *S,int x)
{  
	  S->top=S->top+1;
	  S->a[S->top]=x;
      
}

int isbalanced(char arr[])
{   int i;
    struct stack S;
    S.top=-1;
   for(i=0;arr[i]!='\0';i++)
   {   if(arr[i]=='(')
         push(&S,arr[i]);
       else if(arr[i]==')')
          {    if(S.top==-1)
                  return (0);
		       pop(&S);
		  } 
   }
   if(S.top==-1)
   return 1;
   else return 0;
}
int main(void) {
    int flag;
	char arr[100]=")((()()))";
	flag=isbalanced(arr);
	if(flag==1)
	printf("The expression is balanced\n");
	else printf("The expression is not balanced\n");
	return 0;
}
