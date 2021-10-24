/*  Implementation of Insert, delete, search, Inorder, preorder, postorder, height,countNodes functions for Binary Search Tree.
*/ 
#include <stdio.h>
#include <stdlib.h>
struct treenode
{ int key;
  struct treenode *left;
  struct treenode *right;
};

struct treenode *insert(struct treenode *root,int x)
{  struct treenode *p,*q;
   q=(struct treenode *)malloc(sizeof(struct treenode));
   q->key=x;
   q->left=NULL;
   q->right=NULL;
   
   if(root==NULL)
   return q;
   
   p=root;
   while(1)
   { if(x<p->key)
     {  if(p->left==NULL)
         break;
         p=p->left;
	 }
	 else
	  {   if(p->right==NULL)
	      break;
	      p=p->right;
	  }
    }
    if(x<p->key)
      p->left=q;
    else p->right=q;
    return root;
}
struct treenode *largest(struct treenode *root)
{ struct treenode *p;
  p=root;
  while(p->right)
   p=p->right;
   return (p);
}
struct treenode *deletetnode(struct treenode *root,int x)
{ struct treenode *p;
  if(root==NULL)
   return (root);
  if(x<root->key)
    root->left=deletetnode(root->left,x);
  else if(x>root->key)
    root->right=deletetnode(root->right,x);
  else
    {  if(root->left==NULL)
        { p=root->right;
          free(root);
          return (p);
		}
		if(root->right==NULL)
		{ p=root->left;
		  free(root);
		  return (p);
		}
		p=largest(root->left);
		root->key=p->key;
		root->left=deletetnode(root->left,p->key);
	}
	return (root);
}
void inorder(struct treenode *root)
{ if(root==NULL)
     return ;
    inorder(root->left);
    printf("%4d",root->key);
    inorder(root->right);
}
void preorder(struct treenode *root)
{ if(root==NULL)
     return ;
    printf("%4d",root->key);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct treenode *root)
{ if(root==NULL)
     return ;
    postorder(root->left);
    postorder(root->right);
	printf("%4d",root->key);
}
int search(struct treenode *root,int x)
{   if(root==NULL)
       return (0);
    if(root->key==x)
     { return (1);
	 }
	 if(search(root->left,x)==0)
	    return (search(root->right,x));
	 return (1);
}
int height(struct treenode *root)
{ if(root==NULL)
     return (0);
     int h1,h2;
     h1=height(root->left);
     h2=height(root->right);
     if(h1>h2)
     return (1+h1);
     return (1+h2);
} 
int count(struct treenode *root)
{  if(root==NULL)
     return (0);
    return (1+count(root->left)+count(root->right));
}
int main(void) 
{  int choice,x;
   struct treenode *root;
   root=NULL;
   do{
    printf("****MENU****\n");
  	printf("1-INSERT \n");
  	printf("2-DELETE\n");
  	printf("3-SEARCH\n");
  	printf("4-INORDER\n");
  	printf("5-PREORDER\n");
  	printf("6-POSTORDER\n");
  	printf("7-HEIGHT\n");
  	printf("8-COUNT NODES\n");
  	printf("9-EXIT\n");
  	printf("Enter your choice:");
  	scanf("%d",&choice);
  	switch(choice)
  	{ case 1: printf("Enter element to be inserted:");
  	          scanf("%d",&x);
  	          printf("\n");
	          root=insert(root,x);
  	          break;
  	  case 2: printf("Enter element to be deleted:");
  	          scanf("%d",&x);
  	          printf("\n");
	          root=deletetnode(root,x);
  	          break;
  	  case 3: printf("Enter element to be seached:");
  	          scanf("%d",&x);
  	          printf("\n");
  	          if(search(root,x))
  	           printf("element %d is present in BST\n",x);
  	           else printf("element %d is not present in BST\n",x);
  	          printf("\n");
	          break;
  	  case 4: printf("Inorder traversal of BST is:\n");
  	          inorder(root);
  	          printf("\n");
  	          break;
  	  case 5: printf("Preorder traversal of BST is:\n");
  	          preorder(root);
  	          printf("\n");
  	          break;
  	  case 6: printf("Postorder traversal of BST is:\n");
  	          postorder(root);
  	          printf("\n");
  	          break;
  	  case 7: printf("The height of the BST is : %d \n",height(root));
  	          printf("\n");
  	          break;
  	  case 8: printf("The number of nodes in the BST are %d \n",count(root));
  	  	      printf("\n");
			  break;
  	  case 9: exit(0);
  	          break;
  	  	default: printf("INVALID CHOICE\n");
	  }
  }while(choice!=9);
	return 0;
}
