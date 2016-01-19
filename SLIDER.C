#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int **arr;
	char ch;
	int tmp,sz,lim,i,j,ck,er,ec,r,c,fill=1;
	printf("Enter board size:\t");
	scanf("%d",&sz);
	lim=sz*sz;
	arr=(int**)malloc(sz*sizeof(int*));
	for(i=0;i<sz;i++)
	{
		arr[i]=(int*)malloc(sz*sizeof(int));
		for(j=0;j<sz;j++)
		{
			arr[i][j]=fill;
			fill++;
		}
	}
	for(i=0;i<sz;i++)
	{
		randomize();
		for(j=0;j<sz;j++)
		{
			r=random(sz);
			c=random(sz);
			tmp=arr[i][j];
			arr[i][j]=arr[r][c];
			arr[r][c]=tmp;
		}
	}
	while(1)
	{
		for(i=0;i<sz;i++)
		{
			for(j=0;j<sz;j++)
			{
				if(arr[i][j]==lim)
				{
					printf(" \t");
					er=i;
					ec=j;
				}
				else
				{
					printf("%d\t",arr[i][j]);
				}
			}
			printf("\n");
		}
		printf("U->Up\tL->Left\tD->Down\tR->Right\tQ->Quit\n");
		printf("Enter a choice:\t");
		scanf("%c",&ch);
		if(ch=='U')
		{
			if(er!=0)
			{
				arr[er][ec]=arr[er-1][ec];
				arr[er-1][ec]=lim;
			}
		}
		else if(ch=='L')
		{
			if(ec!=0)
			{
				arr[er][ec]=arr[er][ec-1];
				arr[er][ec-1]=lim;
			}
		}
		else if(ch=='R')
		{
			if(ec!=(sz-1))
			{
				arr[er][ec]=arr[er][ec+1];
				arr[er][ec+1]=lim;
			}
		}
		else if(ch=='D')
		{
			if(er!=(sz-1))
			{
				arr[er][ec]=arr[er+1][ec];
				arr[er+1][ec]=lim;
			}
		}
		else if(ch=='Q')
		{
			break;
		}
		ck=1;
		for(i=0;i<sz;i++)
		{
			for(j=0;j<sz;j++)
			{
				if(arr[i][j]!=lim)
				{
					if(ck==arr[i][j])
					{
						ck++;
					}
					else
					{
						ck=0;
						break;
					}
				}
			}
			if(ck==0)
			{
				break;
			}
		}
		if(ck==lim)
		{
			printf("The puzzle is complete!!\n");
			break;
		}
		else
		{
			clrscr();
		}
	}
	return 0;
}