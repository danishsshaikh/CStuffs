Write a program in C to evaluate given Postfix Expression.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define MAX 50
struct postfix
{
int stack[MAX];
int top,nn;
char *s;
};
void initpostfix(struct postfix *);
void setexpr(struct postfix *,char *);
void push(struct postfix *,int);
int pop(struct postfix *);
void calculate(struct postfix *);
void show(struct postfix);

void main()
{
struct postfix q;
char expr[MAX];
clrscr();
initpostfix(&q);
printf("ENTER POSTFIX EXPRESSION TO BE EVALUATED:\n");
gets(expr);
setexpr(&q,expr);
calculate(&q);
show(q);
getch();
}

void initpostfix(struct postfix *p)
{
p->top=-1;
}

void setexpr(struct postfix*p,char *str)
{
p->s=str;
}

void push(struct postfix*p,int item)
{
if(p->top==MAX-1)
{printf("STACK IS FULL\n"); }
else
{
p->top++;
p->stack[p->top]=item;
}
}
int pop(struct postfix *p)
{
int data;
if(p->top==-1)
{
printf("STACK IS EMPTY\n");
}
data=p->stack[p->top];
p->top--;
return (data);
}

void calculate (struct postfix *p)
{
int n1,n2,n3;
while(*(p->s))
{
if(*(p->s)==' '||*(p->s)=='\t')
{
p->s++;
continue;
}
if(isdigit(*(p->s)))
{
p->nn=*(p->s)-'0';
push(p,p->nn);
}
else
{
n1=pop(p);
n2=pop(p);
switch(*(p->s))
{
case'+':
n3=n2+n1;
break;

case'-':
n3=n2-n1;
break;

case'/':
n3=n2/n1;
break;

case'*':
n3=n2*n1;
break;

case'%':
n3=n2%n1;
break;

case'$':
n3=(int)pow(n2,n1);
break;

default:
printf("UNKNOWN OPERATOR\n");
exit(1);
}
push(p,n3);
}
p->s++;
}
}

void show(struct postfix p)
{
p.nn=pop(&p);
printf("RESULT IS:%d",p.nn);
}
