#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* add_end(struct node *,int);
struct node* add_beg(struct node *,int);
void display(struct node *);
void display_rev(struct node*);


void main()
{
	int n,x,i,pos,dat;
	struct node *head;
	head=NULL;
	printf("enter no of data you want to enter: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data : ");
		scanf("%d",&x);
		head=add_end(head,x);
	}
	display(head);
	printf("rev link\n");
	display_rev(head);
}

struct node* add_end(struct node *head,int x)			//Adding new nodes at end of link list
{
	struct node *trev,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{      
		temp->data=x;
		temp->next=NULL;
		return temp;
	}
	trev=head;
	while(trev->next!=NULL)
		trev=trev->next;
	trev->next=temp;
	temp->data=x;
	temp->next=NULL;
	return head;
}

struct node* add_beg(struct node *head,int x)			//Adding new nodes at end of link list
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(head==NULL)
	{      
		return temp;
	}
	temp->next=head;
	return temp;
}
	
void display(struct node *head)
{
	if(head==NULL)
	{
		printf("no node present\n");
		exit(1);
	}
	else
	{
		while(head->next!=NULL)
		{
			printf("data: %d\n",head->data);
			head=head->next;
		}
		printf("data: %d\n",head->data);
	}
}

void display_rev(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp->next!=NULL)
	{
		display_rev(temp->next);
	}
	printf("data = %d\n",temp->data);
}	






