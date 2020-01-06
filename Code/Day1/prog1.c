#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*);
void main()
{
	int *p1,*p2;
	p1=(int*)malloc(sizeof(int));
	p2=(int*)malloc(sizeof(int));
	*p1=5;
	*p2=10;
	printf("Values before swapping: %d %d\n",*p1,*p2);
	swap(p1,p2);
	printf("Values before after: %d %d\n",*p1,*p2);
}

void swap(int *p1,int *p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}
