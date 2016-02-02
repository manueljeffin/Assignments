#include<stdio.h>
int main()
{
	int n;
	float x,y;
	printf("Enter a number:\t");
	scanf("%d",&n);
	x=n;
	y=1;
	while(x>y)
	{
		x=(x+y)/2;
		y=n/x;
	}
	printf("The square root is %f\n",x);
	return 0;
}