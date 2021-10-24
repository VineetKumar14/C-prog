/*  SPARSE MATRIX MULTIPLICATION
    VINEET KUMAR
    2K19/CO/428
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
struct sparse
{  int nRows,nCols,nA;
   int row[maxsize];
   int col[maxsize];
   int value[maxsize];
};
void printMatrix(struct sparse S)
{  int k;
   k=0;
   int i,j;
   for(i=0;i<S.nRows;i++)
   { for(j=0;j<S.nCols;j++)
        {  if(k<S.nA&&i==S.row[k]&&j==S.col[k])
             {   printf("%8d",S.value[k]);
                 k++;
			 }
			 else printf("%8d",0);
		}
		printf("\n");
   }
}
void readMatrix(struct sparse *S)
{  int i,j,k,m,r,c;
   S->nA=0;
   printf("Enter the number of rows:");
   scanf("%d",&r);
   printf("Enter the number of columns:");
   scanf("%d",&c);
   S->nRows=r;
   S->nCols=c;
   k=0; 
   printf("Enter the matrix elements row wise:\n");
   for(i=0;i<r;i++)
   { for(j=0;j<c;j++)
       {  scanf("%d",&m);
	      if(m!=0)
           { S->row[k]=i;
             S->col[k]=j;
             S->value[k]=m;
             ++S->nA;
             k++;
		   }
	   }
   }
}
struct sparse Transpose(struct sparse A)
{  struct sparse B;
   B.nA=A.nA;
   B.nCols=A.nRows;
   B.nRows=A.nCols;
   int C[A.nCols],T[A.nCols];
   int i;
   for(i=0;i<A.nCols;i++)
   C[i]=0;
   for(i=0;i<A.nA;i++)
    C[A.col[i]]++;
    T[0]=0;
   for(i=1;i<A.nA;i++)
    T[i]=T[i-1]+C[i-1];
    for(i=0;i<A.nA;i++)
     { int a=T[A.col[i]]++;
       B.row[a]=A.col[i];
       B.col[a]=A.row[i];
       B.value[a]=A.value[i];
	 }

	 return (B);
}
struct sparse multiplyMatrix(struct sparse A,struct sparse B)
{  struct sparse C;
   int i,j,k,p,q,sum,a,b;
   k=0;
   C.nRows=A.nRows;
   C.nCols=B.nRows;
   for(i=0;i<A.nA; )
   { a=A.row[i];
         for(j=0;j<B.nA; )
          {  b=B.row[j];
             int p,q,sum;
             p=i;
             q=j;
             sum=0;
             while(p<A.nA&&A.row[p]==a&&q<B.nA&&B.row[q]==b)
              { if(A.col[p]<B.col[q])
                 p++;
                else if(A.col[p]>B.col[q])
                 q++;
                 else { sum+=A.value[p]*B.value[q];
                        p++;
                        q++;
				      }
			  }
			  if(sum!=0)
			  { C.row[k]=A.row[i];
			    C.col[k]=B.row[j];
			    C.value[k]=sum;
			    k++;
			  }
			  while(j<B.nA&&B.row[j]==b)
			  j++;
		  }
		  while(i<A.nA&&A.row[i]==a)
		  i++;
   }
   C.nA=k;
   return (C);
}
int main(void) 
{   struct sparse A,B,C;
    printf("Reading matrix A\n");
    readMatrix(&A);
    printf("Reading matrix B\n");
    readMatrix(&B);
    if(A.nCols!=B.nRows)
    {  printf("The above matrices cannot be multiplied.\n");
       return 0;
	}
	C=multiplyMatrix(A,Transpose(B));
    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);
    printf("Matrix C:\n");
    printMatrix(C);
    return 0;
}
