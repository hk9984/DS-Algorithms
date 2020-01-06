#include<stdio.h>
#include<string.h>
#define MAX 20

struct stack
{
	char stk[MAX];
	int top;
};

void push(struct stack *,char);
char pop(struct stack *);
void Initialize(struct stack *);
int is_palindrome(char[]);

void main()
{
	char str[20];
	int i,result=0;
	printf("Enter the string:");
	scanf("%s",str);
	result=is_palindrome(str);
	if(result==1)
		printf("String is palindrome\n");
	else
		printf("String is not palindrome\n");
}

int is_palindrome(char str[])
{
	int i=0;
	struct stack s;
	while(str[i]!='\0')
	{
		push(&s,str[i]);
		i++;
	}
	i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=pop(&s))
			return 0;
		i++;
	}
	return 1;
}

void Initialize(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s,char data)
{
	if(s->top>=MAX-1)
	{
		printf("Stack is full\n");
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
		printf("Stack underflow\n");
		return '\0';
	}
	else
	{
		temp=s->stk[s->top];
		s->top=s->top-1;
		return temp;
	}
	
}
