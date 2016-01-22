#include<stdio.h>
#include<math.h>
int main()
{
	char a[5];
	int i=0,rev=0;
	printf("\nEnter any number:\t");
	scanf("%s",a);
	while(a[i]!='\0')
	{
		rev=rev+((a[i]-48)*pow(10,i));
		i++;
	}
	printf("The reverse is %d",rev);
	return 0;
}