/*   MERGE SORT USING ITERATION
     
*/
#include <stdio.h>
#include <stdlib.h>
int min(int x,int y)
{  return (x<y)?x:y;
}
void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int p=m-l+1;
	int q=r-m;
	int L[p],R[q];
	for(i=0;i<p;i++)
	L[i]=arr[l+i];
	
	for(j=0;j<q;j++)
	R[j]=arr[m+1+j];
	
	i=0;
	j=0;
	k=l;
	while(i<p&&j<q)
	{ if(L[i]<=R[j])
	    {
		  arr[k]=L[i];
          i++;   }
          else{    arr[k]=R[j];
                   j++;
		  }
		  k++;
	}
	while(i<p)
	{  arr[k]=L[i];
	   i++;
	   k++;
	}
	while(j<q)
	{  arr[k]=R[j];
	   j++;
	   k++;
	}
}
void mergeSort(int arr[],int n)
{  int i,m; 
   for(m=1;m<n;m=2*m)
   {  for(i=0;i<n;i+=2*m)
         {  int p,q,r;
            p=i;
            q=i+m-1;
            r=min(i+2*m-1,n-1);
         	merge(arr,p,q,r);
		 }
   }
}
	


  
int main(void) {
	int n,i;
	printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY \n");
	scanf("%d",&n);
	printf("ENTER THE ELEMENTS\n");
	int arr[n];
	for(i=0;i<n;i++)
	{  scanf("%d",&arr[i]);
	}
	mergeSort(arr,n);
	printf("THE SORTED ARRAY IS\n");
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	return 0;
}


