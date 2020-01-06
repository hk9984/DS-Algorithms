#include<stdio.h>
#include<stdlib.h>

int* InitArray(int);
void FillElements(int*,int);
void DisplayArray(int*,int);
void ReverseArray(int*,int);
void DeleteArray(int*);

void main()
{
	int n,*arr;
	printf("Enter the size of array:");
	scanf("%d",&n);
	arr=InitArray(n);
	printf("Array of size %d initialized!\n",n);
	FillElements(arr,n);
	DisplayArray(arr,n);
	printf("Reversed array:\n");
	ReverseArray(arr,n-1);
	DisplayArray(arr,n);
	DeleteArray(arr);
	printf("Array Deleted\n");
}

int* InitArray(int n)
{
	return (int*)malloc(n*sizeof(int)); 
}

void FillElements(int *arr,int n)
{
	int i;
	printf("Insert values into the array:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
}

void DisplayArray(int *arr,int n)
{
	int i;
	printf("Array: ");
	for(i=0;i<n;i++)
		printf(" %d",arr[i]);
	printf("\n");
}

void ReverseArray(int *arr,int n)
{
	int i=0,temp;
	while(1)
	{
		if(n-i==1||n-i==2)
			break;
		else
		{
			temp=arr[i];
			arr[i]=arr[n];
			arr[n]=temp;
			i++;
			n--;
		}
	}
	temp=arr[i];
	arr[i]=arr[n];
	arr[n]=temp;
}

void DeleteArray(int *arr)
{
	free(arr);
}

