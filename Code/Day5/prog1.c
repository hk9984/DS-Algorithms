#include<stdio.h>
#include<stdlib.h>

void heapsort(int[],int);
void maxheap(int[],int);
void swap(int [],int,int);

void main()
{
	int *arr,n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapsort(arr,n);
	printf("Sorted array:");
	for(i=0;i<n;i++)
		printf(" %d",arr[i]);
	printf("\n");
}

void heapsort(int arr[],int n)
{
	while(n-1>0)
	{
		maxheap(arr,n);
		swap(arr,0,n-1);
		n--;
	}
}

void maxheap(int arr[],int n)
{
	int rchild,lchild,i,temp;
	for(i=(n-2)/2;i>=0;i--)
	{
		rchild=(2*i)+2;
		lchild=(2*i)+1;
		if(rchild<=n-1)
		{
			if(arr[lchild]>arr[rchild])
				swap(arr,lchild,rchild);
			if(arr[i]<arr[rchild])
				swap(arr,i,rchild);
		}
		else
		{
			if(arr[i]<arr[lchild])
				swap(arr,lchild,i);
		}
	}
}

void swap(int arr[],int i,int j)
{
	int temp;
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
