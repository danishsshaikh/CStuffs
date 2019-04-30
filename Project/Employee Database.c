
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node
{
 int idNo,yearOfJoining,phone;
 char name[10],email[20];
 struct node *next;
};
 struct node *first=NULL,*last=NULL,*k;
 
 void create(int);
 void display();



void create(int n)
{
  int i;
  first=(struct node *)malloc(sizeof(struct node));
  printf("\n enter the name of the employee");
  scanf("%s",first->name);
  printf("\n enter the id no of employee");
  scanf("%d",&first->idNo);
  printf("\nenter the phone of employee");
  scanf("%d",&first->phone);
  printf("\nenter the year of joining of the employee");
  scanf("%d",&first->yearOfJoining);
  printf("\n enter the gmail of employee");
  scanf("%s",first->email);
  first->next=NULL;
  last=first;
  for(i=1;i<n;i++)
  {
    k=(struct node*)malloc(sizeof(struct node));
    printf("\n enter the  name of employee");
    scanf("%s",k->name);
    printf("\n enter the id no of employee");
    scanf("%d",&k->idNo);
    printf("\n enter the phone of the employee");
    scanf("%d",&k->phone);
    printf("\nenter the year of joining of the employee");
    scanf("%d",&k->yearOfJoining);
    printf("\nenter the gmail of employee");
    scanf("%s",k->email);
    k->next=NULL;
    last->next=k;
    last=k;
   }
}


void display()
{
  struct node *t;
  t=first;
  while(t!=NULL)
  {
   printf("\n*********************Student Database*******************");
        printf("\nName\tidNo\tphone\tYear Of Joining\tEmail ID");
        printf("\n------------------------------------------------------------------------");
        printf("\n%s\t%d\t%s\t%d\t\t%s\t", t->name, t->idNo, t->phone, t->yearOfJoining, t->email);
    t=t->next;
   }
 } 


  void main()
  {
    int chc,n;
    printf("\n..................OFFICE DATABASE SYSTEM.........");
    printf("\nmenu");
    printf("\n1.insert the list");
    printf("\n2.display");
    printf("\n3.exit");
    do
    {
      printf("\nenter the choice");
      scanf("%d",&chc);
      switch(chc)
      {
        case 1:
        printf("\nenter the no of employee you want in list");
        scanf("%d",&n);
        create(n);
        break;

   
        case 2:  display();
        break;
  
  
        case 3:printf("\nexit");
        break;
  
        default:printf("\ninvalid operation");
        break;
      }
    }while(chc!=3);
   }
   



  
   