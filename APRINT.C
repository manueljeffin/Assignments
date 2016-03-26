#include<stdio.h>
#include<conio.h>
int main()
{
	int t,tmcnt,tacnt=0;
	int acnt=1;
	printf("Enter no. of test cases:\t");
	scanf("%d",&t);
	while(t--)
	{
		tacnt=0;
		acnt=1;
		printf("Enter no. of moves:\t");
		scanf("%d",&tmcnt);
		while(tmcnt>0)
		{
			if(tacnt/3>=acnt)
			{
				acnt=tacnt;
				tacnt*=2;
				tmcnt-=3;
			}
			else
			{
				tacnt+=acnt;
				tmcnt--;
			}
		}
		printf("Maximum length:\t%d\n",tacnt);
	 }
	 return 0;
}
