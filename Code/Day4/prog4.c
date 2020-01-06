#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void Merge(int[],int,int);
void MergeSort(int[],int,int);

int main()
{
	int n,i,j;
	int arr[MAX];
	printf("Enter Number of element\n");
	scanf("%d",&n);
	printf("Enter Elements\n");
	for(j=0;j<n;j++)
	{
			scanf("%d",&arr[j]);
	}
	MergeSort(arr,0,n-1);	
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void Merge(int a[],int i,int j)
{
	int k,*b,mid,start,l;
	b=(int*)malloc(MAX*sizeof(int));
	start=i;
	mid=(i+j)/2;
	k=mid+1;
	l=i;
	while(i<=mid && k<=j)
	{
		if(a[i]>a[k])
			b[l++]=a[i++];
		else
			b[l++]=a[k++];
	}
	if(i>mid)
	{
		while(k<=j)
			b[l++]=a[k++];
	}
	else if(k>j)
	{
		while(i<=mid)
			b[l++]=a[i++];
	}
	for(l=start;l<=j;l++)
	a[l]=b[l];
}

void MergeSort(int a[],int i,int j)
{
	int b,mid;
	if(i>=j)
		return;
	else
	{
		mid=(i+j)/2;
		MergeSort(a,i,mid);
		MergeSort(a,mid+1,j);
		Merge(a,i,j);
	}
	

	
}
