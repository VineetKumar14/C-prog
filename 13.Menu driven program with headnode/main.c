/*  Menu driven simple linked list without head node. insert(start, end, after), delete, search,count operations.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{ int value;
  struct node *next;
};

struct headnode
{ struct node *start;
  struct node *end;
};

void display(struct headnode h)
{ struct node *p;
  p=h.start;
  if(p==NULL)
    return;
  while(p!=NULL)
   {   printf("%4d",p->value);
       p=p->next;
   }
   printf("\n");
}

int countnodes(struct headnode h)
{ struct node *p;
  int count;
  count=0;
  p=h.start;
  if(p==NULL)
   { return (count);
   }
   while(p!=NULL)
   { ++count;
     p=p->next;
   }
   return (count);
}

void insert(struct headnode *h,int x)
{ struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  p->value=x;
  if(h->start==NULL)
   {  h->start=p;
      h->end=p;
   }
  p->next=h->start;
  h->start=p;
}

void insertatend(struct headnode *h,int x)
{  struct node *p;
   p=(struct node*)malloc(sizeof(struct node));
   p->value=x;
   p->next=NULL; 
   if(h->start==NULL)
     { h->start=p;
       h->end=p;
	 }
   else{  h->end->next=p;
          h->end=p;
       } 
}
void insertafter(struct headnode *h,int x,int y)
 { struct node *p,*q;
   q=(struct node*)malloc(sizeof(struct node));
   q->value=x;
   if(h->start==NULL)
   { h->start=q;
     h->end=q;
     q->next=NULL;
   }
   else
    { p=h->start;
      while(p->value!=y)
      { if(p->next!=NULL)
	        p=p->next;
		else break; 
	  }
	  q->next=p->next;
	  p->next=q;
	  if(h->end==p)
	   h->end=q;
    }
 }
 
void deletenode(struct headnode *h,int x)
{  struct node *p,*q;
   if(h->start==NULL)
    return;
    q=h->start;
    p=NULL;
    while(q!=NULL&&q->value!=x)
     { p=q;
       q=q->next;
	 }
	 if(q==NULL)
	   return;
	 if(p==NULL)
	   h->start=q->next;
	 else
	   p->next=q->next;
	if(q==h->end)
	 h->end=p;
	if(h->start)
	 h->end=NULL;
}
 
int search(struct headnode h,int x)
{ struct node *p;
  p=h.start;
  if(p==NULL)
  return (0);
  while(p!=NULL&&p->value!=x)
    p=p->next;
  if(p!=NULL)
   return (1);
   return (0);
}

int main(void)
{ int choice,x,y;
  struct headnode h;
  h.start=NULL;
  h.end=NULL;
  do{
    printf("****MENU****\n");
  	printf("1-INSERT AT START\n");
  	printf("2-INSERT AT END\n");
  	printf("3-INSERT AFTER\n");
  	printf("4-DELETE\n");
  	printf("5-SEARCH\n");
  	printf("6-DISPLAY\n");
  	printf("7-COUNT NODES\n");
  	printf("8-EXIT\n");
  	printf("Enter your choice:");
  	scanf("%d",&choice);
  	switch(choice)
  	{ case 1: printf("Enter element to be inserted at beginning:");
  	          scanf("%d",&x);
  	          printf("\n");
	          insert(&h,x);
  	          break;
  	  case 2: printf("Enter element to be inserted at end:");
  	          scanf("%d",&x);
  	          printf("\n");
	          insertatend(&h,x);
  	          break;
  	  case 3: printf("Enter element to be inserted:");
  	          scanf("%d",&x);
  	          printf("Enter element after which the above element is to be inserted:");
  	          scanf("%d",&y);
  	          printf("\n");
  	          insertafter(&h,x,y);
	          break;
  	  case 4: printf("Enter element to be deleted from list:");
  	          scanf("%d",&x);
  	          printf("\n");
	          deletenode(&h,x);
  	          break;
  	  case 5: printf("Enter the element to be searched\n");
  	          scanf("%d",&x);
  	          y=search(h,x);
  	          if(y==1)
  	            printf("The element %d is present in the List\n",x);
  	          else printf("The element %d is not found in the List\n",x);
  	          break;
  	  case 6: printf("The Linked List is:\n");
		      display(h);
  	          break;
  	  case 7: printf("The number of elements are :%d\n",countnodes(h));
  	          break;
  	  case 8: exit(0);
  	          break;
  	  	default: printf("INVALID CHOICE\n");
	  }
  }while(choice!=8);
  return 0;
}
