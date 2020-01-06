#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10

struct stack
{
	char stk[MAX];
	int top;
};

void push(struct stack *,char);
char pop(struct stack *);
void Initialize(struct stack *);
void balance(struct stack *,char []);
void main()
{
	struct stack s;
	int result;
	char data[MAX];
	Initialize(&s);
	printf("enter string:");
	scanf("%s",data);
	balance(&s,data);
	printf("Paranthesis are Balanced\n");
}

void balance(struct stack *s,char data[])
{
	int n,i;
	char ch;
	n=strlen(data);
	for(i=0;i<n;i++)
	{
		if(data[i]=='('||data[i]=='{'||data[i]=='[')
		{
			push(s,data[i]);
		}
		else if(data[i]==')'||data[i]=='}'||data[i]==']')
		{	
			ch=pop(s);
			switch(data[i])
			{
			case ')':
				if(ch=='(')
					break;
				else
				{
					printf("Paranthesis not Balanced\n");
					exit(1);
				}
			case '}':
				if(ch=='{')
					break;
				else
				{
					printf("Paranthesis not Balanced\n");
					exit(1);
				}
			case ']':
				if(ch=='[')
					break;
				else
				{
					printf("Paranthesis not Balanced\n");
					exit(1);
				}
			default:
				printf("Paranthesis not Balanced\n");
				exit(1);
			}		
		}
	}
	if(pop(s)!='\0')
	{
		printf("Paranthesis not Balanced\n");
		exit(1);
	}
}

void Initialize(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,char data)
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

char pop(struct stack *s)
{
	char temp;
	if(s->top==-1)
	{
		//printf("stack underflow\n");
		return '\0';
	}
	else
	{
		temp=s->stk[s->top];
		s->top=s->top-1;
		return temp;
	}
	
}
