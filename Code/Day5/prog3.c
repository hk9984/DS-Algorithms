#include<stdio.h>
#include<stdlib.h>
int binary_search(int[],int,int,int);
void main()
{
	int n,*arr,i,s,result;
	printf("Enter size of array:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("Enter Elements in sorted order\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter element to be searched:");
	scanf("%d",&s);
	result=binary_search(arr,s,0,n-1);
	if(result==-1)
		printf("element not found\n");
	else
		printf("Element is Present at %d location\n",result);
}

int binary_search(int arr[],int s,int f,int l)
{
	int med,pos;
	med=(l+f)/2;
	if(s==arr[med])
		return med+1;
	else if(s>arr[med]&&s<=arr[l])
		pos=binary_search(arr,s,med+1,l);
	else if(s<arr[med]&&s>=arr[f])
		pos=binary_search(arr,s,f,med-1);
	else
		return -1;
	return pos;
}
