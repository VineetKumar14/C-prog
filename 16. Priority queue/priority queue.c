/* Implement Priority Queue using MaxHeap: InsertQ(), DeleteQ(), DisplayHeap() are the functions to be implemented.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100

void swap(int*, int*);
void display(int[],int);
void insert(int[],int,int,int);
int heapify(int[],int,int);

int main()
{
    int lb,choice,num,n,a[MAX],data,s;
    choice = 0;
    n=0; 
    lb=0; 
    while(choice != 4)
    {
        printf(".....MAIN MENU.....\n");
        printf("\n1.Insert.\n");
        printf("2.Delete.\n");
        printf("3.Display.\n");
        printf("4.Quit.\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter data to be inserted : ");
            scanf("%d",&data);
            insert(a,n,data,lb);
            n++;
            break;
        case 2:
            s=heapify(a,n+1,lb);
            if(s!=0)
            printf("The deleted value is : %d",s);
            if(n>0)
                n--;
            break;
        case 3:
            printf("\n");
            display(a,n);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
        printf("\n\n");
    }
return 0;
}
void insert(int a[],int heapsize,int data,int lb)
{
    int i,p;
    int parent(int);
    if(heapsize==MAX)
    {
        printf("Queue Is Full!!n");
        return;
    }
    i=lb+heapsize;
    a[i]=data;
    while(i>lb&&a[p=parent(i)]<a[i])
    {
        swap(&a[p],&a[i]);
        i=p;
    }
}


int heapify(int a[],int heapsize,int lb)
{
    int data,i,l,r,max_child,t;
    int left(int);
    int right(int);
    if(heapsize==1)
    {
        printf("Queue Is Empty!!\n");
        return 0;
    }
    t=a[lb];
    swap(&a[lb],&a[heapsize-1]);
    i=lb;
    heapsize--;
    while(1)
    {
        if((l=left(i))>=heapsize)
            break;
        if((r=right(i))>=heapsize)
            max_child=l;
        else
            max_child=(a[l]>a[r])?l:r;
        if(a[i]>=a[max_child])
            break;
        swap(&a[i],&a[max_child]);
        i=max_child;
    }
return t;
}


int parent(int i)
{
    float p;
    p=((float)i/2.0)-1.0;
    return ceil(p);
}


int left(int i)
{
    return 2*i+1;
}


int right(int i)
{
    return 2*i+2;
}


void display(int a[],int n)
{
    int i;
    if(n==0)
    {
        printf("Queue Is Empty!!\n");
        return;
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}


void swap(int*p,int*q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
