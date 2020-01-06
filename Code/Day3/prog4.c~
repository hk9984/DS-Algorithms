#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* insert_end(struct node *,int);
struct node* insert_front(struct node *,int);
void display(struct node*);

void main()
{
	int ch,n;
	struct node *last;
	last=NULL;
	
	printf("Enter:\n1 to insert at front\n2 to insert at end\n3 to display list\n0 to exit\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&n);
				last=insert_front(last,n);
				printf("Element added\n");
				continue;
			case 2:
				printf("Enter data:");
				scanf("%d",&n);
				last=insert_end(last,n);
				printf("Element added\n");
				continue;
			case 3:
				printf("Link List:");
				display(last);
				continue;
			case 0:
				break;
			default:
				printf("Enter correct choice\n");
				continue;
		}
		break;
	}
	
	printf("Final List: ");
	display(last);
}

struct node* insert_end(struct node *last,int x)		//Adding new nodes at end of link list
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(last==NULL)
	{      
		temp->next=temp;
		return temp;
	}
	temp->next=last->next;
	last->next=temp;
	return temp;
}

struct node* insert_front(struct node *last,int x)		//Adding new nodes at beginning of link list
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(last==NULL)
	{
		temp->next=temp;
		return temp;
	}
	temp->next=last->next;
	last->next=temp;
	return last;
}

void display(struct node *last)
{
	struct node *trev;
	trev=last;
	if(last==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else
	{
		while(trev->next!=last)
		{
			trev=trev->next;
			printf("%d -> ",trev->data);
		}
		trev=trev->next;
		printf("%d\n",trev->data);
	}
}
