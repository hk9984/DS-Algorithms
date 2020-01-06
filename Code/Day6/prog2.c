#include<stdio.h>
#include<string.h>
#define MAX 10

struct stack
{
	int stk[MAX];
	int top;
};

void push(struct stack *,int);
int pop(struct stack *);
void Initialize(struct stack *);
int postfix(struct stack *,char []);
void main()
{
	struct stack s;
	int result;
	char data[MAX];
	Initialize(&s);
	printf("enter postfix:");
	scanf("%s",data);
	printf("%s",data);
	result=postfix(&s,data);
	printf("Result is %d\n",result);
}

int postfix(struct stack *s,char data[])
{
	int op1,op2,result,n,i;
	n=strlen(data);
	for(i=0;i<n;i++)
	{
		if(data[i]=='*'||data[i]=='/'||data[i]=='%'||data[i]=='+'||data[i]=='-')
		{
			op2=pop(s);
			op1=pop(s);
			switch(data[i])
			{
			case '*':
				result=op1*op2;
				push(s,result);
				break;
			case '/':
				result=op1/op2;
				push(s,result);
				break;
			case '%':
				result=op1%op2;
				push(s,result);
				break;
			case '-':
				result=op1-op2;
				push(s,result);
				break;
			case '+':
				result=op1+op2;
				push(s,result);
				break;			
			}	
		}
		else
			push(s,(data[i]-'0'));
	}
	return pop(s);
	
	
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
