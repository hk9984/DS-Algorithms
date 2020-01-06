#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* add_end(struct node *,int);
void display(struct node*);
void swap(struct node*,int);

void main()
{
	int n,x,pos,i;
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
	printf("Original Link List\n");
	display(head);
	printf("enter postion you want to swap : ");
	scanf("%d",&pos);
	swap(head,pos);
	printf("Link List after swapping\n");
	display(head);
	
}

void swap(struct node *head,int pos)
{
	struct node *prev,*cur,*next;
	int ct=0;
	if(head==NULL)
	{
		printf("No node present\n");
		exit(1);
	}
	prev=NULL;
	cur=head;
	next=cur->next;
	while(cur->next!=NULL)
	{
		ct++;
		if(ct==pos)
		{
			cur->next=next->next;
			next->next=cur;
			prev->next=next;
			break;
		}
		prev=cur;
		cur=cur->next;
		next=cur->next;		
	}
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
