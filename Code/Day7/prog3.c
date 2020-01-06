#include<stdio.h>
#include<stdlib.h>

struct queue{
	int data;
	struct queue *next;
};

struct queue* enqueue(struct queue *,int);
struct queue* dequeue(struct queue *);
void display(struct queue *);

void main()
{
	int ch,data;
	struct queue *last,*temp;
	last=NULL;
	printf("Enter\n1 to Enqueue data\n2 to Dequeue data\n3 to Display\n0 to exit\n");
	while(1)
	{	
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				last=enqueue(last,data);
				printf("Element added in Queue\n");
				continue;
			case 2:
				if(last!=NULL)
				{
					temp=last->next;
					printf("Dequeue data: %d\n",temp->data);
				}
				last=dequeue(last);
				continue;
			case 3:
				printf("Queue: ");
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
}

struct queue* enqueue(struct queue *last,int x)
{
	struct queue *temp;
	temp=(struct queue*)malloc(sizeof(struct queue));
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

struct queue* dequeue(struct queue *last)
{
	int data;
	struct queue *temp;
	if(last==NULL)
		printf("Queue Empty\n");
	else if(last->next==last)
	{
		free(last);
		last=NULL;
	}
	else
	{
		temp=last->next;
		last->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
	return last;
}

void display(struct queue *last)
{
	struct queue *trev;
	trev=last;
	if(last==NULL)
	{
		printf("The queue is empty!\n");
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
