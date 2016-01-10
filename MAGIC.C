#include<stdio.h>
int main()
{
	int i,j,n,t,lim;
	int **sqr;
	printf("Enter size of square:\t");
	scanf("%d",&n);
	sqr=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		sqr[i]=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		{
			sqr[i][j]=0;
		}
	}
	lim=n*n;
	i=0;
	j=n/2;
	t=1;
	while(t<=lim)
	{
		if(sqr[i][j]==0)
		{
			sqr[i][j]=t;
			t++;
			i--;
			if(i<0)
			{
				i=n-1;
			}
			j=(j+1)%n;
		}
		else
		{
			i=(i+2)%n;
			j--;
			if(j<0)
			{
				j=n-1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",sqr[i][j]);
		}
		printf("\n");
	}
	return 0;
}