#include<stdio.h>
#include<stdlib.h>

struct bst* insert(struct bst *,int);
struct bst* find(struct bst *,int);
struct bst* find_min(struct bst *);
struct bst* find_max(struct bst *);
struct bst* delete(struct bst *,int);

struct bst{
	int data;
	struct bst *rchild;
	struct bst *lchild;
};

void main()
{
	int ch,data;
	struct bst *root=NULL,*pos;
	printf("Enter\n1 to Insert\n2 to Delete\n3 to find\n4 to find min\n5 to find max\n0 to exit\n");
	while(1)
	{
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Data: ");
				scanf("%d",&data);
				root=insert(root,data);
				continue;
			case 2:
				printf("Enter data to delete: ");
				scanf("%d",&data);
				root=delete(root,data);
				continue;
			case 3:
				printf("Enter data to find: ");
				scanf("%d",&data);
				pos=find(root,data);
				if(pos==NULL)
					printf("Element Absent\n");
				else
					printf("Position %p\n",pos);
				continue;
			case 4:
				pos=find_min(root);
				printf("Min: %d\n",pos->data);
				continue;
			case 5:
				pos=find_max(root);
				printf("Max: %d\n",pos->data);
				continue;
			case 0:
				break;
			default: 
				continue;
		}
		break;
	}
}

struct bst* insert(struct bst *root,int data)
{
	//struct bst *temp;
	if(root==NULL)
	{
		root=(struct bst*)malloc(sizeof(struct bst));
		root->data=data;
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else
	{
		if(data>root->data)
			root->rchild=insert(root->rchild,data);
		else if(data<root->data)
			root->lchild=insert(root->lchild,data);
	}
	return root;
}

struct bst* find(struct bst *root,int data)
{
	if(root==NULL)
		return root;
	else
	{
		if(data>root->data)
			return find(root->rchild,data);
		else if(data<root->data)
			return find(root->lchild,data);
		else
			return root;
	}
}

struct bst* find_min(struct bst *root)
{
	if(root->lchild==NULL)
		return root;
	else
		return find_min(root->lchild);
}

struct bst* find_max(struct bst *root)
{
	if(root->rchild==NULL)
		return root;
	else
		return find_max(root->rchild);
}

struct bst* delete(struct bst *root,int data)
{
	struct bst *temp;
	if(root==NULL)
		return root;
	else
	{
		if(data>root->data)
			root->rchild=delete(root->rchild,data);
		else if(data<root->data)
			root->lchild=delete(root->lchild,data);
		else
		{
			if(root->lchild!=NULL&&root->rchild!=NULL)
			{
				temp=find_max(root->lchild);
				root->data=temp->data;
				root->lchild=delete(root->lchild,temp->data);
			}
			else 
			{
				temp=root;
				if(root->lchild==NULL)
					root=root->rchild;
				else if(root->rchild==NULL)
					root=root->lchild;
				free(temp);
			}
		}
	}
	return root;
}
