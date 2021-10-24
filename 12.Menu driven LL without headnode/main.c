/*   Menu driven simple linked list without head node. insert(start, end, after), delete, search,count operations.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{ int value;
  struct node *next;
};

void display(struct node *s)
{ struct node *p;
  p=s;
  if(s==NULL)
    return;
  while(p!=NULL)
   {   printf("%4d",p->value);
       p=p->next;
   }
   printf("\n");
}

int countnodes(struct node *s)
{ struct node *p;
  int count;
  count=0;
  p=s;
  if(s==NULL)
   { return (count);
   }
   while(p!=NULL)
   { ++count;
     p=p->next;
   }
   return (count);
}

struct node *insert(struct node *s,int x)
{ struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  p->value=x;
  p->next=s;
  s=p;
}

struct node *insertatend(struct node *s,int x)
{  struct node *p,*q;
   p=(struct node*)malloc(sizeof(struct node));
   p->value=x;
   p->next=NULL;
   if(s==NULL)
   { s=p;
   }
   else
       { q=s;
         while(q->next!=NULL)
          q=q->next;
          q->next=p;
       }
    return (s);
}
struct node *insertafter(struct node *s,int x,int y)
 { struct node *p,*q;
   q=(struct node*)malloc(sizeof(struct node));
   q->value=x;
   if(s==NULL)
   { s=q;
     q->next=NULL;
   }
   else
    { p=s;
      while(p->value!=y)
      { if(p->next!=NULL)
	        p=p->next;
		else break; 
	  }
	  q->next=p->next;
	  p->next=q;
    }
    return (s);
 }
 
struct node *deletenode(struct node *s,int x)
{  struct node *p,*q;
   if(s==NULL)
    return;
    q=s;
    p=NULL;
    while(q!=NULL&&q->value!=x)
     { p=q;
       q=q->next;
	 }
	 if(q==NULL)
	   return (s);
	 if(p==NULL)
	   s=q->next;
	 else
	   p->next=q->next;
	return (s);
}
 
int search(struct node *s,int x)
{ struct node *p;
  p=s;
  if(s==NULL)
  return (0);
  while(p!=NULL&&p->value!=x)
    p=p->next;
  if(p!=NULL)
   return (1);
   return (0);
}

int main(void)
{ int choice,x,y;
  struct node *s;
  s=NULL;
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
	          s=insert(s,x);
  	          break;
  	  case 2: printf("Enter element to be inserted at end:");
  	          scanf("%d",&x);
  	          printf("\n");
	          s=insertatend(s,x);
  	          break;
  	  case 3: printf("Enter element to be inserted:");
  	          scanf("%d",&x);
  	          printf("Enter element after which the above element is to be inserted:");
  	          scanf("%d",&y);
  	          printf("\n");
  	          s=insertafter(s,x,y);
	          break;
  	  case 4: printf("Enter element to be deleted from list:");
  	          scanf("%d",&x);
  	          printf("\n");
	          s=deletenode(s,x);
  	          break;
  	  case 5: printf("Enter the element to be searched\n");
  	          scanf("%d",&x);
  	          y=search(s,x);
  	          if(y==1)
  	            printf("The element %d is present in the List\n",x);
  	          else printf("The element %d is not found in the List\n",x);
  	          break;
  	  case 6: printf("The Linked List is:\n");
		      display(s);
  	          break;
  	  case 7: printf("The number of elements are :%d\n",countnodes(s));
  	          break;
  	  case 8: exit(0);
  	          break;
  	  	default: printf("INVALID CHOICE\n");
	  }
  }while(choice!=8);
  return 0;
}
