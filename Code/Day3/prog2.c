#include<stdio.h>
#include<stdlib.h>
struct dnode* insert_at_beg(struct dnode*,int);
struct dnode* insert_at_end(struct dnode*,int);
struct dnode* delete_at_beg(struct dnode*);
struct dnode* delete_at_end(struct dnode*);
struct dnode* search(struct dnode*,int);
void display(struct dnode*);

struct dnode
{
	struct dnode *prev;
	int data;
	struct dnode *next;
};

void main()
{
	int ch,data;
	struct dnode *head,*pos;
	head=NULL;
	printf("Enter:\n1 to insert data beginning\n2to insert data at end\n3 to delete at beginning\n4 to delete at end\n5 to search data\n0 to exit\n");
	while(1)
	{	
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				head=insert_at_beg(head,data);
				printf("Element added\n");
				continue;
			case 2:
				printf("Enter data:");
				scanf("%d",&data);
				head=insert_at_end(head,data);
				printf("Element added\n");
				continue;
			case 3:
				head=delete_at_beg(head);
				printf("Element deleted\n");
				continue;
			case 4:
				head=delete_at_end(head);
				printf("Element deleted\n");
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
			case 0:
				break;
			default:
				printf("Enter valid choice\n");
		}
		break;
	}
	printf("\nFinal list:\n");
	display(head);
	printf("\n");
}

struct dnode* insert_at_beg(struct dnode* head,int data)
{
	struct dnode *temp;				//Create new node to insert
	temp=(struct dnode*)malloc(sizeof(struct dnode));
	temp->prev=NULL;				//Set Prev address to NULL
	temp->data=data;		
	temp->next=NULL;				//Set Next address to NULL
	if(head==NULL)					//If no node present in list,pass New node address as Head
	{      
		return temp;
	}
	temp->next=head;				//Else set next of New to address of head node
	head->prev=temp;				//Set prev of head node to address of new node
	return temp;					//Return address of New node as Head
}

struct dnode* insert_at_end(struct dnode* head,int data)
{
	struct dnode *trev,*temp;
	temp=(struct dnode*)malloc(sizeof(struct dnode));	//Create new node to insert
	temp->prev=NULL;				//Set Prev address to NULL
	temp->data=data;
	temp->next=NULL;				//Set Next address to NULL
	if(head==NULL)					//If no node present in list,pass New node address as Head
	{      
		return temp;
	}
	trev=head;
	while(trev->next!=NULL)				//Else treverse to the end of list
		trev=trev->next;
	trev->next=temp;				//Set next of Last node to address of New node
	temp->prev=trev;				//Set prev of New node to address of Last node
	return head;					//Return Head
}

struct dnode* delete_at_beg(struct dnode* head)
{
	struct dnode *temp;
		temp=head;
		if(head==NULL)
		{
			printf("List already empty!\n");
			return head;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
			temp->next=NULL;
			free(temp);
			return head;
		}
}

struct dnode* delete_at_end(struct dnode* head)
{
	struct dnode *temp,*pprev;
	temp=head;
	if(head==NULL)
	{	
		printf("List already empty!\n");
		return head;
	}
	else
	{
		while(temp->next!=NULL)
		{
			pprev=temp;
			temp=temp->next;
		}
		pprev->next=NULL;
		temp->prev=NULL;
		free(temp);
		return head;
	}
}

struct dnode* search(struct dnode* head,int data)
{
	if(head==NULL)
	{
		printf("The list is empty!\n");
			return NULL;
	}
	while(head->next!=NULL)				//Traverse till end of link list
	{
		if(head->data==data)			//If required data is found, return add of node
			return head;
		head=head->next;
	}
	if(head->data==data)
			return head;
	else
		return NULL;				//Else return NULL
}

void display(struct dnode* head)
{
	if(head==NULL)
	{
		printf("The list is Empty!\n");
		return;
	}
	else
	{	
		printf("Node:");
		while(head->next!=NULL)
		{
			printf("%d -> ",head->data);
			head=head->next;
		}
		printf("%d",head->data);
	}
}
