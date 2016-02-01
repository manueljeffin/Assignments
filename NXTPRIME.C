#include<stdio.h>
#include<math.h>
int main()
{
	int f,n,rtn,i;
	printf("Enter a number:\t");
	scanf("%d",&n);
	do
	{
		rtn=sqrt(n);
		f=1;
		for(i=2;i<=rtn;i++)
		{
			if(n%i==0)
			{
				f=0;
				break;
			}
		}
		n++;
	}while(f==0);
	n--;
	printf("The next prime is %d",n);
	return 0;
}