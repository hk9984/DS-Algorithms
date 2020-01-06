#include<stdio.h>
#define MAX 10

struct stack
{
	char stk[MAX];
	int top;
};

void Initialize(struct stack*);
void toPost(char[],char[]);
void push(struct stack *,char);
char pop(struct stack *);

void main()
{
	char infix[MAX],postfix[MAX];
	printf("Enter infix expression:");
	scanf("%s",infix);
	toPost(infix,postfix);
	printf("Postfix operation: %s\n",postfix);
}

void toPost(char infix[],char postfix[])
{
	int i=0,j=0;
	char ch='\0';
	struct stack s;
	Initialize(&s);
	while(infix[i]!='\0')
	{
		if(infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-')
		{
			ch=pop(&s);
			if(ch=='\0')
				push(&s,infix[i++]);
			else if(ch=='/'||ch=='*')
			{
				push(&s,infix[i++]);
				postfix[j++]=ch;
			}
			else if(ch=='+'||ch=='-')
			{	
				push(&s,ch);
				push(&s,infix[i++]);
			}
		}
		else
			postfix[j++]=infix[i++];
	}
	while(ch=pop(&s))
	{
		postfix[j++]=ch;
	}
	postfix[j]='\0';
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
		return '\0';
	else
	{
		temp=s->stk[s->top];
		s->top=s->top-1;
		return temp;
	}
	
}
