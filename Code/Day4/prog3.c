#include<stdio.h>

void selection_sort(int[],int);

void main()
{
	int arr[20],n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	selection_sort(arr,n);
	printf("Sorted array:");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	printf("\n");
}

void selection_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
} 
