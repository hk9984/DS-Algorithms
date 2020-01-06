#include<stdio.h>
#define MAX 5

struct cqueue
{
	int queue[MAX];
	int front;
	int end;
};

void initialize(struct cqueue *);
void enqueue(struct cqueue *,int);
int dequeue(struct cqueue *);
void display(struct cqueue *);

void main()
{
	struct cqueue q;
	int ch,data;
	initialize(&q);
	printf("Enter\n1 for ENQUEUE\n2 for DEQUEUE\n3 for DISPLAY\n0 for EXIT\n");
	while(1)
	{
		printf("Enter Choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter data:");
				scanf("%d",&data);
				enqueue(&q,data);
				continue;
			case 2:
				data=dequeue(&q);
				printf("DEQUEUE Data is %d\n",data);
				continue;
			case 3:
				printf("Data in QUEUE\n");
				display(&q);
				continue;
			case 0:
				break;
			default :
				printf("enter correct choice \n");
				continue;
		}
		break;
	}
}

void initialize(struct cqueue *q)
{
	q->front=-1;
	q->end=-1;
}

void enqueue(struct cqueue *q,int data)
{
	if(q->end==-1)
	{
		q->front=q->end=0;
	}
	else
	{
		q->end=(q->end+1)%MAX;
		if(q->end==q->front)
		{
			printf("Queue is full\n");
			return;
		}
	}
	q->queue[q->end]=data;
}

int dequeue(struct cqueue *q)
{
	int data;
	if(q->front==-1)
	{
		printf("Queue Empty\n");
		return;
	}
	else
	{
		data=q->queue[q->front];
		if(q->front==q->end)
			q->front=q->end=-1;
		else
			q->front=(q->front+1)%MAX;
	}
	return data;
}

void display(struct cqueue *q)
{
	int i=q->front,j=q->end;
	if(i==-1)
	{
		printf("Queue Empty\n");
		return;
	}
	while(i!=j)
	{
		printf("%d ",q->queue[i]);
		i=(i+1)%MAX;
	}
	printf("%d\n",q->queue[i]);
}
