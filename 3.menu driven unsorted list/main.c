/*   MENU DRIVEN PROGRAM FOR UNSORTED LIST
*/
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{  int n,x,a,b,min,max;
   printf("ENTER THE NUMBER OF ELEMENTS IN THE ARRAY\n");
   scanf("%d",&n); 
   int ar[20];
   printf("ENTER THE ARRAY ELEMENTS \n");
   int i;
   for(i=0;i<n;i++)
    scanf("%d",&ar[i]);
   do{
    printf("\n********MENU********\n");
    printf("1 - INSERT \n");
    printf("2 - DELETE \n");
    printf("3 - FIND MIN\n");
    printf("4 - FIND MAX\n");
    printf("5 - DISPLAY LIST\n");
    printf("6 - EXIT\n");
    scanf("%d",&x);
    switch(x)
    { case 1:    
	             printf("ENTER THE ELEMENT TO BE INSERTED\n");
	             scanf("%d",&a);
	             ar[n]=a; 
			   	 n=n+1;
	             break;
	  case 2:     
	              printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED\n");
	              scanf("%d",&b);
	              ar[b-1]=ar[n-1];
	              n=n-1;
	              break;
	  case 3:    min=ar[0];
	           for(i=0;i<n;i++)
	           {   if(ar[i]<min)
	               min=ar[i];
			   }
			   printf("THE MINIMUM ELEMENT IS %d \n",min);
			   break;
	  case 4:  max=ar[0];
	            for(i=0;i<n;i++)
	            {  if(ar[i]>max)
	                max=ar[i];
				}
				printf("THE MAXIMUM ELEMENT IS %d \n",max);
				break;
	  case 5: for(i=0;i<n;i++)
	          printf("%d ",ar[i]);
	          break;
	  case 6 : exit(0);
	          break;
	 default: printf("INVALID CHOICE\n");
    }
    
	       	} while(x!=6);
	return 0;
}
