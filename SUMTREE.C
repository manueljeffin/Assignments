#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define node struct tnode
struct tnode
{
	int data;
	node *left;
	node *right;
}*root=NULL;
node* create(int arr[],int i, int sz)
{
	node* temp;
	int lref,rref;
	lref=2*i+1;
	rref=2*i+2;
	temp=(node*)malloc(sizeof(node));
	temp->data=arr[i];
	if(root==NULL)
	{
		root=temp;
	}
	if(lref<sz)
	{
		temp->left=create(arr,lref,sz);
	}
	else
	{
		temp->left=NULL;
	}
	if(rref<sz)
	{
		temp->right=create(arr,rref,sz);
	}
	else
	{
		temp->right=NULL;
	}
	return temp;
}
int treeSum(node *temp)
{
	int sum;
	if((temp->left==NULL)&&(temp->right==NULL))
	{
		return temp->data;
	}
	else if(temp==NULL)
	{
		return 0;
	}
	else
	{
		sum=temp->data+treeSum(temp->left)+treeSum(temp->right);
	}
	return sum;
}
int isSumTree(node *temp)
{
	int sum;
	if(temp->left==NULL&&temp->right==NULL)
	{
		return 1;
	}
	else if(isSumTree(temp->left)==1&&isSumTree(temp->right)==1)
	{
		sum=treeSum(temp->left)+treeSum(temp->right);
		if(sum==temp->data)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int *arr;
	int dep,sz,i;
	node* temp;
	printf("Enter no. of levels:\t");
	scanf("%d",&dep);
	sz=pow(2,dep)-1;
	arr=(int *)malloc(sz*sizeof(int));
	printf("Enter tree elements level-wise from left to right\n");
	for(i=0;i<sz;i++)
	{
		scanf("%d",&arr[i]);
	}
	temp=create(arr,0,sz);
	if(isSumTree(temp)==1)
	{
		printf("This is a sum tree\n");
	}
	else
	{
		printf("This is not a sum tree\n");
	}
	return 0;
}

