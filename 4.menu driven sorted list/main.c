 /*  MENU DRIVEN SORTED LIST
*/
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{  int n,j,x,a,b,pos;
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
    { case 1:    printf("ENTER THE ELEMENT TO INSERTED \n");
                 scanf("%d",&a);
                for(i=0;i<n;i++)
                 {   if(ar[i]>a)
                      {    pos=i;
                      break;
                        }
                        pos=n;
                    }
                    for(i=n-1;i>=pos;i--)
                    ar[i+1]=ar[i];
                    ar[pos]=a;
				     n=n+1;
	             break;
	  case 2:      printf("ENTER THE POSITION OF THE ELEMENT TO BE DELETED\n");
	                scanf("%d",&b);
	                for(i=b-1;i<n-1;i++)
	                {  ar[i]=ar[i+1];
					}
					n=n-1;
	              break;
	  case 3:   printf("THE MINIMUM ELEMENT IS %d\n",ar[0]);
			   break;
	  case 4:  printf("THE MAXIMUM ELEMENT IS %d\n",ar[n-1]);
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
