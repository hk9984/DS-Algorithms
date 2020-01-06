#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* add_end(struct node *,int);
struct node* rev_list(struct node *);
void display(struct node*);


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
	printf("Original Link\n");
	display(head);
	head=rev_list(head);
	printf("Reverse Link\n");
	display(head);
	
	
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

struct node* rev_list(struct node *head)
{
	struct node *prev,*current,*nnext;
	prev=NULL;
	current=head;
	if(head==NULL)
	{
		printf("No elements in the list\n");
		return NULL;
	}
	else
	{
		nnext=current->next;
		while(nnext!=NULL)
		{
			current->next=prev;
			prev=current;
			current=nnext;
			nnext=nnext->next;
		}
		current->next=prev;
		return current;
			
	}
}
