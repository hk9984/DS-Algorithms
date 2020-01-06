#include<stdio.h>

void insertion_sort(int[],int);

void main()
{
	int arr[20],n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	insertion_sort(arr,n);
	printf("Sorted array:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void insertion_sort(int arr[],int n)
{
	int i=0,j=0,k=0,temp;
	for(i=0;i<n-1;i++)
	{
		j=i+1;
		for(k=0;k<=i;k++)
		{
			if(arr[j]<arr[k])
			{
				temp=arr[j];
				while(j>k)
				{
	 				arr[j]=arr[j-1];
					j--;
				}
				arr[k]=temp;
				break;
			}	
		}                                                                                                         
	}
}
