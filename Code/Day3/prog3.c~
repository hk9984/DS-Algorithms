#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node* insert_beg(struct node *,int);
void display(struct node*);

struct node* self_adjusting_find(struct node *,int);

void main()
{
	int ch,data;
	struct node *head;
	head=NULL;
	printf("Enter:\n1 to enter new node\n2 to Find required node\n0 to exit\n");
	while(1)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				head=insert_beg(head,data);
				printf("Element added\n");
				continue;
			case 2:
				printf("Enter value of node to find:");
				scanf("%d",&data);
				head=self_adjusting_find(head,data);
				printf("New List:");
				display(head);
				continue;
			case 0:
				break;
			default:
				printf("Enter correct choice\n");
		}
		break;
	}
	printf("Final list: ");
	display(head);
}

struct node* insert_beg(struct node *head,int x)		//Adding new nodes at beginning of link list
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

struct node* self_adjusting_find(struct node *head,int data)
{
	struct node *trev,*prev;
	trev=head;
	prev=NULL;
	if(head==NULL)
	{
		printf("The list is empty!");
		return NULL;
	}
	while(trev->next!=NULL)					//Traverse till end of link list
	{
		if(trev->data==data)				//If required data is found, return add of node
		{
			prev->next=trev->next;//next->trev
			trev->next=head->next;
			head=trev;
			return head;
		}
		prev=trev;
		trev=trev->next;
	}
	if(trev->data==data)
	{	
		prev->next=trev->next;//next->trev
		trev->next=head->next;
		head=trev;
	}
	else
		printf("Required node not found:No changes made");
	return head;
}


	
void display(struct node *head)
{
	if(head==NULL)
	{
		printf("The list is empty!\n");
		return;
	}
	else
	{
		while(head->next!=NULL)
		{
			printf("%d -> ",head->data);
			head=head->next;
		}
		printf("%d\n",head->data);
	}
}	

