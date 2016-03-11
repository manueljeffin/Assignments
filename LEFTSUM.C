#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define node struct tnode
int sum=0;
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
void addLeftLeaf(node *temp)
{
	if(temp->left->left==NULL)
	{
		sum=sum+temp->left->data;
	}
	else
	{
		addLeftLeaf(temp->left);
		addLeftLeaf(temp->right);
	}
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
	addLeftLeaf(temp);
	printf("Sum:\t%d\n",sum);
	return 0;
}

