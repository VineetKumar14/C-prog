/*  SPARSE MATRIX ADDITION
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
struct sparseMatrix
{  int nRows,nCols,nA;
   int row[maxsize];
   int col[maxsize];
   int value[maxsize];
};
void printsparse(struct sparseMatrix A)
{  int k;
   k=0;
   int i,j;
   for(i=0;i<A.nRows;i++)
   { for(j=0;j<A.nCols;j++)
        {  if(k<A.nA&&i==A.row[k]&&j==A.col[k])
             {   printf("%8d",A.value[k]);
                 k++;
			 }
			 else printf("%8d",0);
		}
		printf("\n");
   }
}
void readmatrix(struct sparseMatrix *A)
{  int i,j,k,m,r,c;
   A->nA=0;
   printf("Enter the number of rows:");
   scanf("%d",&r);
   printf("Enter the number of columns:");
   scanf("%d",&c);
   A->nRows=r;
   A->nCols=c;
   k=0; 
   printf("Enter the matrix elements row wise:\n");
   for(i=0;i<r;i++)
   { for(j=0;j<c;j++)
       {  scanf("%d",&m);
	      if(m!=0)
           { A->row[k]=i;
             A->col[k]=j;
             A->value[k]=m;
             ++A->nA;
             k++;
		   }
	   }
   }
}
struct sparseMatrix addmatrix(struct sparseMatrix A,struct sparseMatrix B)
{  struct sparseMatrix C;
   int i,j,k;
   i=0;
   j=0;
   k=0;
   while(i<A.nA&&j<B.nA)
   {   if(A.row[i]==B.row[j]&&A.col[i]==B.col[j])
        {  C.row[k]=A.row[i];
           C.col[k]=A.col[i];
           C.value[k]=A.value[i]+B.value[j];
           i++;
           j++;
           k++;
		}
		else if(A.row[i]<B.row[j]||(A.row[i]==B.row[j]&&A.col[i]<B.col[j]))
		 {  C.row[k]=A.row[i];
		    C.col[k]=A.col[i];
		    C.value[k]=A.value[i];
		    i++;
		    k++;
		 }
		 else 
		 {  C.row[k]=B.row[j];
		    C.col[k]=B.col[j];
		    C.value[k]=B.value[j];
		    j++;
		    k++;
		 }
   }
   while(i<A.nA)
   {    C.row[k]=A.row[i];
	    C.col[k]=A.col[i];
	    C.value[k]=A.value[i];
		i++;
		k++;
   }
   while(j<B.nA)
   {    C.row[k]=B.row[j];
		C.col[k]=B.col[j];
		C.value[k]=B.value[j];
		j++;
		k++;
   }
   C.nCols=A.nCols;
   C.nRows=A.nCols;
   C.nA=k;
   return (C);
}
int main(void) 
{   struct sparseMatrix A,B,C;
    printf("Reading matrix A\n");
    readmatrix(&A);
    printf("Reading matrix B\n");
    readmatrix(&B);
    C=addmatrix(A,B);
    printf("Matrix A:\n");
    printsparse(A);
    printf("Matrix B:\n");
    printsparse(B);
    printf("Matrix C:\n");
    printsparse(C);
	return 0;
}
