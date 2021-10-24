/*  maintain a sorted linked list, implement insert, delete, search, count 
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{ int value;
  struct node *next;
};
struct node *insert(struct node *s,int x)
{ struct node *p,*q;
  q=(struct node *)malloc(sizeof(struct node));
  q->value=x;
  if(s==NULL)
  { s=q;
    q->next=NULL;
  }
  else if(x<=s->value)
   { q->next=s;
     s=q;
   }
   else
   { p=s;
     while(p->next!=NULL&&p->next->value<x)
     p=p->next;
     
     q->next=p->next;
   	 p->next=q;
   }
   return (s);
}

struct node *deletenode(struct node *s,int x)
{ struct node *p,*q;
  if(s==NULL)
   return;
   p=NULL;
   q=s;
   while(q!=NULL&&q->value!=x)
   { p=q;
     q=q->next;
   }
   if(q==NULL)
     return (s);
   if(p==NULL)
   {  s=q->next;
   }
   else
   { p->next=q->next;
   }
   return(s);
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

void display(struct node *s)
{ struct node *p;
  if(s==NULL)
   return;
   p=s;
   while(p!=NULL)
    { printf("%4d",p->value); 
      p=p->next;
	}
	printf("\n");
}

int countnodes(struct node *s)
{ struct node *p;
  int count;
  count=0;
  if(s==NULL)
  return (0);
  p=s;
  while(p!=NULL) 
  { p=p->next;
    count++;
  }
  return (count);
}
int main(void)
{  int choice,x;
   struct node *s;
   s=NULL;
  do{
    printf("****MENU****\n");
  	printf("1-INSERT\n");
    printf("2-DELETE\n");
  	printf("3-SEARCH\n");
  	printf("4-DISPLAY\n");
  	printf("5-COUNT NODES\n");
  	printf("6-EXIT\n");
  	printf("Enter your choice:");
  	scanf("%d",&choice);
  	switch(choice)
  	{ case 1: printf("Enter the element to be inserted:");
  	          scanf("%d",&x);
  	          printf("\n");
	          s=insert(s,x);
  	          break;
  	  case 2: printf("Enter the element to be deleted:");
  	          scanf("%d",&x);
  	          printf("\n");
  	          s=deletenode(s,x);
  	          break;
  	  case 3: printf("Enter the element to be searched:");
  	          scanf("%d",&x);
  	          printf("\n");
  	          if(search(s,x))
  	           printf("The element is present in the list\n");
  	          else printf("The element is not present in the list\n");
  	          break;
  	  case 4: printf("The Sorted Linked List is:\n");
		      display(s);
  	          break;
  	  case 5: printf("The number of elements in the list are: %d\n",countnodes(s));
  	          break;
	  case 6: exit(0);
  	          break;
  	  	default: printf("INVALID CHOICE\n");
	  }
  }while(choice!=6);
   return 0;
}
