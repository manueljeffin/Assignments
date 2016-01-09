#include<stdio.h>
int main()
{
	int n,lim=1,i,j=1,k=1;
	printf("Enter input:\t");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		lim=lim*2;
	}
	for(i=1;i<lim;i++)
	{	
		k=1;
		j=1;
		printf("\n");
		while(j<=i)
		{
			if((i&j)!=0)
			{
				printf("%d ",k);
			}
			j=j*2;
			k++;
		}
	}
	printf("\n");
	return 0;
}
