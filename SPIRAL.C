#include<stdio.h>
#include<stdlib.h>
int main()
{
	int tel,cnt,rsz,csz,sub=0,dir=0,r=0,c=0;
	int **arr;
	printf("Enter row and column size:\n");
	scanf("%d%d",&rsz,&csz);
	arr=(int**)malloc(rsz*sizeof(int*));
	for(r=0;r<rsz;r++)
	{
		arr[r]=(int*)malloc(csz*sizeof(int));
	}
	printf("Enter array elements\n");
	for(r=0;r<rsz;r++)
	{
		for(c=0;c<csz;c++)
		{
			scanf("%d",&arr[r][c]);
		}
	}
	tel=rsz*csz;
	r=0;
	c=0;
	while(--tel)
	{
		if(dir==0)
		{
			cnt=csz-sub;
			while(--cnt)
			{
				printf("%d ",arr[r][c]);
				c++;
			}
		}
		if(dir==1)
		{
			cnt=rsz-sub;
			while(--cnt)
			{
				printf("%d ",arr[r][c]);
				r++;
			}
		}
		if(dir==2)
		{
			cnt=csz-sub;
			while(--cnt)
			{
				printf("%d ",arr[r][c]);
				c--;
			}
		}
		if(dir==3)
		{
			sub++;
			cnt=rsz-sub;
			while(--cnt)
			{
				printf("%d ",arr[r][c]);
				r--;
			}
		}
		dir=(dir+1)%4;
	}
	return 0;
}