#include<stdio.h>
#include<stdlib.h>
int main()
{	
	int **a;
	int t,sz,i,j,dsz;
	printf("Enter size of matrix:\t");
	scanf("%d",&sz);
	*a=(int**)malloc(sz*sizeof(int));
	for(i=0;i<sz;i++)
	{
		a[i]=(int*)malloc(sz*sizeof(int));
	}
	printf("Enter matrix elements\n");
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dsz=sz-1;
	for(i=0;i<dsz;i++)
	{
		for(j=i+1;j<sz;j++)
		{	
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
	printf("Transposed matrix:\n");
	for(i=0;i<sz;i++)
	{
		for(j=0;j<sz;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}