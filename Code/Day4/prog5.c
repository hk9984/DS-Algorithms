#include<stdio.h>
void quick_sort(int[],int,int);
void main()
{
	int arr[20],n,i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quick_sort(arr,0,n-1);
	printf("Sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void quick_sort(int arr[],int first,int last)
{
	int i=first,j=last-1,p=last,n,temp,l;
	n=last-first+1;
	if(n==2)
	{
		if(arr[first]>arr[last])
		{
			temp=arr[first];
			arr[first]=arr[last];
			arr[last]=temp;
		}
		return;
	}
	while(n>0)
	{
		while(arr[i]<=arr[p])
			i++;
		while(arr[j]>arr[p])
			j--;
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
		else if(i>j)
		{
			if(i<p)
			{
			temp=arr[i];
			arr[i]=arr[p];
			arr[p]=temp;
			}
			else
			{
				i=p;
			}
			quick_sort(arr,first,i-1);
			quick_sort(arr,i+1,last);
			break;
		}
		n--;
	}
	
	
	
}
