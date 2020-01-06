#include<stdio.h>
#define MAX 5

struct stack
{
	int stk[MAX];
	int top;
};

void push(struct stack *,int);
int pop(struct stack *);
void display(struct stack *);
void Initialize(struct stack *);
void main()
{
	struct stack s;
	int a,data;
	Initialize(&s);
	printf("enter choice \n1 for push \n2 for pop \n3 for display\n9 for exit\n");
	while(1)
	{
		printf("enter choice:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("enter data to push in stack:");
				scanf("%d",&data);
				push(&s,data);
				continue;
			case 2:
				data=pop(&s);
				if(data==-1)
					continue;
				else
				printf("Pop data is %d\n",data);
				continue;
			case 3:
				display(&s);
				continue;
			case 9:
				break;
		}break;
	}
}

void Initialize(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,int data)
{
	if(s->top>=MAX-1)
	{
		printf("stack is full\n");
	}
	else
	{
		s->top=(s->top)+1;
		s->stk[s->top]=data;
	}
}

int pop(struct stack *s)
{
	int temp;
	if(s->top==-1)
	{
		printf("stack underflow\n");
		return -1;
	}
	else
	{
		temp=s->stk[s->top];
		s->top=s->top-1;
		return temp;
	}
	
}

void display(struct stack *s)
{
	int i=0;
	printf("Elements in stack\n");
	for(i=0;i<=(s->top);i++)
	{
		printf("%d\n",s->stk[i]);
	}
}
