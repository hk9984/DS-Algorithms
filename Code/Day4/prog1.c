#include<stdio.h>

void bubble_sort(int[],int);

void main()
{
	int arr[20],n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	bubble_sort(arr,n);
	printf("Sorted array:");
	for(i=0;i<n;i++)
		printf("%d",arr[i]);
	printf("\n");
}

void bubble_sort(int arr[],int n)
{
	int i,j,temp;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}	
} 
				
