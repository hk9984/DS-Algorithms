#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* add_end(struct node *,int);
struct node* intersect(struct node*,struct node*);
void display(struct node*);


void main()
{
	int n,x,i,pos,dat;
	struct node *head1,*head2,*head3;
	head1=NULL;
	head2=NULL;
	head3=NULL;
	printf("enter no of data you want to enter in 1st Link: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data : ");
		scanf("%d",&x);
		head1=add_end(head1,x);
	}
	printf("elements in link 1 \n");
	display(head1);
	printf("enter no of data you want to enter in 2nd Link: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter data : ");
		scanf("%d",&x);
		head2=add_end(head2,x);
	}
	printf("elements in link 2 \n");
	display(head2);
	head3=intersect(head1,head2);
	printf("L1 intersection L2\n");
	display(head3);
	
	
	
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

struct node* intersect(struct node *head1,struct node *head2)
{
	struct node *head3;
	head3=NULL;
	while(head1->next!=NULL && head2->next!=NULL)
	{
		if(head1->data==head2->data)
		{
			head3=add_end(head3,head1->data);
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1->data>head2->data)
		{
			head2=head2->next;
		}
		else if(head2->data>head1->data)
		{
			head1=head1->next;
		}
	}
	while(1)
	{
		if(head1->next==NULL)
		{
			if(head1->data==head2->data)
			{
				head3=add_end(head3,head1->data);
				return head3;
			}
			else if(head1->data>head2->data)
			{
				head2=head2->next;
			}
			else if(head2->data>head1->data)
			{
				return head3;
			}
		}
		else if(head2->next==NULL)
		{
			if(head1->data==head2->data)
			{
				head3=add_end(head3,head1->data);
				return head3;
			}
			else if(head2->data>head1->data)
			{
				head1=head1->next;
			}
			else if(head1->data>head2->data)
			{
				return head3;
			}
		}
	}
}

