/* MENU DRIVEN PROGRAM TO IMPLEMENT QUEUE
*/
#include <stdio.h>
#include <stdlib.h>
#define maxsize 5
struct queue{
  int a[maxsize];
  int front,rear;
};
void insert(struct queue *Q,int x)
{ if((Q->rear+1)%maxsize==Q->front)
     {   printf("Queue is full\n");
          return;
	 }
	 Q->a[Q->rear]=x;
	 Q->rear=(Q->rear+1)%maxsize;
}

int Delete(struct queue *Q)
{  int y;
    if(Q->front==Q->rear)
      {  printf("Queue is empty\n");
         return (-1);
	  }
	y=Q->a[Q->front];
	Q->front=(Q->front+1)%maxsize;
	return y;
}

void display(struct queue Q)
{  int i=Q.front;
   printf("Queue contents are\n");
   while(i!=Q.rear)
   {   printf("%d  ",Q.a[i]);
      i=(i+1)%maxsize;
   }
}

int main(void) {
	struct queue Q;
	int choice,x;
    Q.front=Q.rear;
	while(1)
	{  printf("\n**** MENU ****\n");
	   printf("1)INSERT\n");
	   printf("2)DELETE\n");
	   printf("3)DISPLAY\n");
	   printf("4)EXIT\n");
	   printf("Enter the choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {  case 1:  printf("enter the element to be inserted\n");
	               scanf("%d",&x);
	               insert(&Q,x);
	               display(Q);
	   	            break;
	   	  case 2:  x=Delete(&Q);
	   	           printf("Deleted element is :%d\n",x);
	   	           display(Q);
	   	           display(Q);
	   	  	        break;
	   	  case 3:  display(Q);
	   	  	        break;

	   }
	   if(choice==4)
	   break;
	}
	return 0;
}
