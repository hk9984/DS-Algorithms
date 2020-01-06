#include<stdio.h>
#define MAX 5

int openhash(int[],int);
void inserthash(int [],int);
void delhash(int [],int);
int findhash(int [],int);

void main()
{
	int arr[MAX],pos,ch,data,i;
	for(i=0;i<MAX;i++)
		arr[i]=-1;
	printf("enter\n1 to insert in hashtable\n2 to delete\n3 to find\n0 to exit\n");
	while(1)
	{
		printf("enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter data:");
				scanf("%d",&data);
				inserthash(arr,data);
				continue;
			case 2:
				printf("enter data to delete:");
				scanf("%d",&data);
				delhash(arr,data);
				continue;
			case 3:
				printf("enter data to find:");
				scanf("%d",&data);
				pos=findhash(arr,data);
				if(pos==-99)
					printf("Data not found\n");
				else
					printf("Index of data: %d\n",pos);
				continue;
			case 0:
				break;
			default:
				printf("enter correct choice\n");
				continue;
		}
		break;
	}
	
}

int openhash(int arr[],int data)
{
	int index,temp;
	index=data%MAX;
	temp=index;
	if(arr[index]==-1)
		return index;
	else
	{
		while(arr[temp]!=-1)
		{
			temp=(temp+1)%MAX;
			if(temp==index)
			{	
				return -99;
			}
		}
		return temp;
	}
}

void inserthash(int arr[],int data)
{
	int index;
	index=openhash(arr,data);
	printf("Index=%d\n",index);
	if(index==(-99))
		printf("Hash Table Full\n");
	else
	{
		arr[index]=data;
		printf("Data Inserted\n");
	}	
}

void delhash(int arr[],int data)
{
	int index;
	index=findhash(arr,data);
	if(index!=-99)
	{
		arr[index]=-1;
		printf("Data Deleted\n");
	}
	else
		printf("Data Not Found\n");
}

int findhash(int arr[],int data)
{
	int index,temp;
	index=data%MAX;
	temp=index;
	if(arr[index]==data)
		return index;
	else
	{
		while(arr[temp]!=data)
		{
			temp=(temp+1)%MAX;
			if(temp==index)
			{	
				return -99;
			}
		}
		return temp;
	}
}
