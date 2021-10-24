/*   INFIX TO POSTFIX CONVERSION USING STACKS
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 50
struct stack
{  char a[maxsize];
   int top;
};
char stacktop(struct stack s)
{   return s.a[s.top];
}
char pop(struct stack *s)
{   char p;
	p=s->a[s->top];
	s->top=s->top-1;
	return (p);
}
void push(struct stack *s,int x)
{   
	  s->top=s->top+1;
	  s->a[s->top]=x;
      
}
int isempty(struct stack s)
{  if(s.top==-1)
    return (1);
    return (0);
}
int isoperand(char c)
{   if(c>='a'&&c<='z')
     return (1);
     return (0);
}
int isp(char c)
{  if(c=='*'||c=='/')
      return (2);
   if(c=='+'||c=='-')
      return (1);
   if(c=='(')
      return (0);
}
int icp(char c)
 {  if(c=='*'||c=='/')
      return (2);
   if(c=='+'||c=='-')
      return (1);
   if(c=='(')
      return (3);
 }
void infixtopostfix(char infix[])
{   struct stack s;
    char postfix[maxsize]; 
	int i,j;
	s.top=-1;
    char x;
    i=0;
	j=0;
	while(infix[i]!='\0')
	{ if(isoperand(infix[i]))
	     { postfix[j++]=infix[i];
		 }
	  else if(infix[i]==')')
	     { while((x=pop(&s))!='(')
	           {  postfix[j++]=x;
			   }
		 }
	  else
	     {  if(isempty(s))
	              push(&s,infix[i]);
	       else
	            {   while(!isempty(s)&&isp(stacktop(s))>=icp(infix[i]))
	                  {   x=pop(&s);
	                      postfix[j++]=x;
					  }
					  push(&s,infix[i]);
				}
	           
		 }
	  i++;	 
	}
	while(!isempty(s))
	{   postfix[j++]=pop(&s);
	}
	 postfix[j]='\0';
	for(i=0;postfix[i]!='\0';i++)
	  printf("%c",postfix[i]);
}
int main(void)
{   
    char infix[maxsize]="";
    infixtopostfix(infix);
    return 0;
}
