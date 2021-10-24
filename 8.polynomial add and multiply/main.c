/*   POLYNOMIAL ADDITION AND MULTIPLICATION
*/
#include <stdio.h>
#include <stdlib.h>

struct polynode{
	float coef;
	int exp;
};
void multip(struct polynode p1[],struct polynode p2[],struct polynode p4[],int s1,int s2,int* s4)
{  int i,j,k;
   *s4=0;
   
   for(i=0;i<s1;i++)
    {  for(j=0;j<s2;j++)
          {  int a,b,flag;
            flag=0;
            a=p1[i].coef*p2[j].coef;
            b=p1[i].exp+p2[j].exp;
            for(k=0;k<*s4;k++)
            {   if(p4[k].exp==b)
                  {  p4[k].coef+=a;
                        flag=1;
                        break;
			      }
			}
			if(flag==0)
			{  p4[*s4].exp=b;
			   p4[*s4].coef=a;
			   *s4+=1;
			}
			
		  }
	}
}
void addpoly(struct polynode p1[],struct polynode p2[],struct polynode p3[],int s1,int s2,int* s3)
{   int i,j,k;
    i=0;
    j=0;
    k=0;
    while(i<s1&&j<s2)
    { if(p1[i].exp==p2[j].exp)
         {  float c;
            c=p1[i].coef+p2[j].coef;
            if(c!=0)
            { p3[k].coef=c;
              p3[k].exp=p1[i].exp;
              k++;
			}
			i++;
			j++;
		 }
		else if(p1[i].exp>p2[i].exp)
		{ p3[k].exp=p1[i].exp;
		  p3[k].coef=p1[i].coef;
		  i++;
		  k++;
		}
		else{   p3[k].coef=p2[j].coef;
		        p3[k].exp=p2[j].exp;
				j++;
				k++;  
		    }
	}
	while(i<s1)
	{     p3[k].exp=p1[i].exp;
		  p3[k].coef=p1[i].coef;
		  i++;
		  k++;
	}
	while(j<s2)
	{           p3[k].coef=p2[j].coef;
		        p3[k].exp=p2[j].exp;
				j++;
				k++;
	}
	*s3=k;
}
void printpoly(struct polynode p3[],int s3)
{   int i;
    for(i=0;i<s3-1;i++)
    {  printf("%fx^%d+",p3[i].coef,p3[i].exp);
	}
	printf("%fx^%d\n",p3[s3-1].coef,p3[s3-1].exp);
}

int main(void) 
{   int s1,s2,s3,s4,i;
    printf("POLYNOMIAL 1:\n");
    printf("Enter the number of terms:");
    scanf("%d",&s1);
    struct polynode p1[s1];
    printf("\nEnter the coefficients with their respective exponents:\n");
    for(i=0;i<s1;i++)
    {  printf("Coefficient:");
       scanf("%f",&p1[i].coef);
       printf("   exponent:");
       scanf("%d",&p1[i].exp);
       printf("\n");
	}
	 printf("POLYNOMIAL 2:\n");
    printf("Enter the number of terms:");
    scanf("%d",&s2);
    struct polynode p2[s2];
    printf("\nEnter the coefficients with their respective exponents:\n");
    for(i=0;i<s2;i++)
    {  printf("Coefficient:");
       scanf("%f",&p2[i].coef);
       printf("   exponent:");
       scanf("%d",&p2[i].exp);
       printf("\n");
	}
	struct polynode p3[s1+s2],p4[s1+s2];
	addpoly(p1,p2,p3,s1,s2,&s3);
    printf("The addition of polynomials is:  ");
	printpoly(p3,s3);
	multip(p1,p2,p4,s1,s2,&s4);
	printf("\nThe product of polynomials is:  ");
	printpoly(p4,s4);
    return 0;
}
