
		to sort linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int data;
struct node *link;
}
*newnode,*start,*visit;
void getdata();
void append(struct node **,int);
void displaylist();
int count(struct node *);
void bubble_sort(int);
int main()
{
int n;
clrscr();
getdata();
printf("Linked list before sorting:\n");
displaylist();
n=count(start);
bubble_sort(n);
printf("Linked list after bubble sorting:\n");
displaylist();
getch();
return 0;
}
void getdata()
{
int val;
char ch;
struct node *new;
new=NULL;
do
{
printf("Enter a value:");
scanf("%d",&val);
append(&new,val);
printf("Any more nodes (Y/N):");
fflush(stdin);
ch=getchar();
printf("\n");
}
while(ch=='y'||ch=='Y');
start=new;
}
void append(struct node **q,int num)
{
struct node *temp;
temp=*q;
if(*q==NULL)
{
*q=(struct node *)malloc(sizeof(struct node));
temp=*q;
}
else
{
while(temp->link!=NULL)
temp=temp->link;
temp->link=(struct node *)malloc(sizeof(struct node));
temp=temp->link;}
temp->data=num;
temp->link=NULL;
}
void displaylist()
{
visit=start;
while(visit!=NULL)
{
printf("%d",visit->data);
visit=visit->link;
}
printf("\n");
}
int count(struct node *q)
{
int c=0;
while(q!=NULL)
{
q=q->link;
c++;
}
return c;
}
void bubble_sort(int n)
{
int i,j,k,temp;
struct node *p,*q;
k=n;
for(i=0;i<n-1;i++,k--)
{
p=start;
q=p->link;
for(j=1;j<k;j++)
{
if(p->data>q->data)
{
temp=p->data;
p->data=q->data;
q->data=temp;
}
p=p->link;
q=q->link;
}
}
}
