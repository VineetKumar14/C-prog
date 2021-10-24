#include <stdio.h>
#include <stdlib.h>
#define maxsize 200
struct stack{
  int a[maxsize];
  int top;
};
void pop(struct stack *S)
{ 
  S->top=S->top-1;
}
void push(struct stack *S,int x)
{   
	  S->top=S->top+1;
	  S->a[S->top]=x;
      
}
int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename;
    char s[150];
    struct stack S;
    S.top=-1;
     int l,b,er;
     er=0;
     l=0;
 b=0;
  if (argc<2)
   {
        printf("Missing Filename\n");
        return(1);
   }
   else
  {
        filename = argv[1];
        printf("Filename : %s\n",filename);
        
   }

  
   fp = fopen(filename,"r");

   
   if ( fp )
      {
        while (fgets(s,199,fp)!=NULL)
           {  
               int i;
               ++l;
               b=0;
               for(i=0;i<199;i++)
               { if(s[i]==' ')
                 ++b;
                 else if(s[i]=='\t')
                        b=b+8;
                 else break;
						     
			   }
			    
				if(b>S.a[S.top]||S.top==-1)
	            push(&S,b);
			    else if(b<=S.a[S.top])
				     { 
				       while(b!=S.a[S.top]&&S.top>=0)
				       {  pop(&S);
					   }
					   if(S.top==-1)
					   {  er=l;
					      if(s[i]=='}')
					       er=0;
					      break;
					   }
					   
					   if(b==S.a[S.top])
					   {  pop(&S);
					   }
					   
				     }         
			}			
       
				
		   
               if(er!=0)
                   printf("Error at line %d,not properly indented",er);
               else
                   printf("OK  The file is properly indented\n");

       }
   else
       {
         printf("Failed to open the file\n");
        }

return(0);
}
