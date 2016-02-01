#include<stdio.h>
#include<math.h>
int main()
{
	int num,base,len,i,val;
	char *res;
	printf("Number:\t");
	scanf("%d",&num);
	printf("Base:\t");
	scanf("%d",&base);
	len=(log(num)/log(base))+1;
	res=(char *)malloc(len*sizeof(char));
	i=len-1;
	while(num>0)
	{
		val=num%base;
		if(val<10)
		{
			res[i]='0'+val;
		}
		else
		{
			res[i]='A'+val-10;
		}
		num=num/base;
		i--;
	}
	printf("Output:\t");
	for(i=0;i<len;i++)
	{
		printf("%c",res[i]);
	}
	printf("\n");
	return 0;
}