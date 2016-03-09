#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nameindex
{
	char name[15];
	int num;
	int pos[10];
};
int main()
{
	struct nameindex ni[10];
	char names[10][30];
	char tmp[15];
	int n,i,j,k=0,f=0;
	printf("Enter no. of names:\n");
	scanf("%d",&n);
	printf("Enter names:\n");
	gets(tmp);
	for(i=0;i<n;i++)
	{
		gets(names[i]);
		k=0;
		f=0;
		for(j=0;j<50;j++)
		{
			if((names[i][j]>='A')&&(names[i][j]<='Z'))
			{
				if((names[i][j+1]>='a')&&(names[i][j+1]<='z'))
				{
					f=1;
					tmp[k]=names[i][j];
					k++;
					j++;
				}
			}
			if(f==1)
			{
				if((names[i][j]>='a')&&(names[i][j]<='z'))
				{
					tmp[k]=names[i][j];
					k++;
				}
				else
				{
					tmp[k]='\0';
					strcpy(names[i],tmp);
					break;
				}
			}
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		f=0;
		for(j=k-1;j>=0;j--)
		{
			if(strcmp(names[i],ni[j].name)==0)
			{
				ni[j].num++;
				ni[j].pos[ni[j].num-1]=i+1;
				f=1;
			}
		}
		if(f==0)
		{
			strcpy(ni[k].name,names[i]);
			ni[k].num=1;
			ni[k].pos[0]=i+1;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%s %d [",ni[i].name,ni[i].num);
		for(j=0;j<ni[i].num;j++)
		{
			printf("%d ",ni[i].pos[j]);
		}
		printf("]\n");
	}
	return 0;
}
