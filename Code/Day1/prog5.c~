#include<stdio.h>
#define N 5
#define M 5
void merge(int[],int[],int[]);
void main()
{
	int a[N],b[M],c[N+M],i;
	printf("enter elements in array 1\n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	printf("enter elements in array 2\n");
	for(i=0;i<M;i++)
		scanf("%d",&b[i]);
	merge(a,b,c);
	printf("merged array\n");
	for(i=0;i<(N+M);i++)
		printf("%d ",c[i]);
	printf("\n");
}

void merge(int a[],int b[],int c[])
{
	int i=0,j=0,k=0;
	while(i<N&&j<M)
	{
		if(a[i]<b[j])
			c[k++]=a[i++];
		if(a[i]>b[j])
			c[k++]=b[j++];
	}
	while(j<M)
		c[k++]=b[j++];
	while(i<N)
		c[k++]=a[i++];
}
