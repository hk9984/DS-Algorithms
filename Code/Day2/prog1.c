#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* insert_end(struct node *,int);
struct node* insert_beg(struct node *,int);
struct node* delete_beg(struct node *);
struct node* delete_end(struct node *);
struct node* insert_after(struct node *,int,int);
void display(struct node*);
struct node* search(struct node*,int);


void main()
{
	int ch,data,x;
	struct node *head,*pos;
	head=NULL;
	printf("Enter:\n1 to insert data beginning\n2to insert data at end\n3 to delete at beginning\n4 to delete at end\n5 to search data\n6 to insert data after index data\n0 to exit\n");
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
				printf("Enter data:");
				scanf("%d",&data);
				head=insert_end(head,data);
				printf("Element added\n");
				continue;
			case 3:
				head=delete_beg(head);
				continue;
			case 4:
				head=delete_end(head);
				continue;
			case 5:
				pos=NULL;
				printf("Enter value:");
				scanf("%d",&data);
				pos=search(head,data);
				if(pos==NULL)
					printf("Data not found!\n");
				else
				{
					printf("Postion of data:%p\n",pos);
					printf("Data:%d\n",pos->data);
				}
				continue;
			case 6:
				printf("Enter data to insert:");
				scanf("%d",&data);
				printf("Enter index data:");
				scanf("%d",&x);
				head=insert_after(head,data,x);
				continue;
			case 0:
				break;
			default:
				printf("Enter valid choice\n");
		}
		break;
	}
	printf("Final List: ");
	display(head);
}

struct node* insert_end(struct node *head,int x)		//Adding new nodes at end of link list
{
	struct node *trev,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
		temp->next=NULL;
	if(head==NULL)
	{      
		return temp;
	}
	trev=head;
	while(trev->next!=NULL)
		trev=trev->next;
	trev->next=temp;
	return head;
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

struct node* search(struct node *head,int data)			//Function to search the required element
{
	if(head==NULL)
	{
		printf("The list is empty!");
		return NULL;
	}
	while(head->next!=NULL)					//Traverse till end of link list
	{
		if(head->data==data)				//If required data is found, return add of node
			return head;
		head=head->next;
	}
	if(head->data==data)
			return head;
	else
		return NULL;					//Else return NULL
}

struct node* delete_beg(struct node *head)
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("List already empty!");
		return head;
	}
	else
	{
		head=head->next;
		temp->next=NULL;
		free(temp);
		printf("Element deleted");
		return head;
	}
}

struct node* delete_end(struct node *head)
{
	struct node *temp,*prev;
	temp=head;
	if(head==NULL)
	{	
		printf("List already empty!");
		return head;
	}
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		free(temp);
		printf("Element deleted");
		return head;
	}
}

struct node* insert_after(struct node *head,int data,int dat)
{
	struct node *temp,*trev;
	trev=head;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		printf("List is empty!\Element added at beginning\n");
		return temp;
	}
	else
	{
		while(trev->next!=NULL)
		{
			if(trev->data==dat)
			{
				temp->next=trev->next;
				trev->next=temp;
				printf("Element added");
				return head;
			}
			trev=trev->next;
		}
		if(trev->data==dat)
			printf("Element added");
		else
			printf("Index value not found!:Element added at end\n");

		trev->next=temp;
		return head;
	
	}
}
