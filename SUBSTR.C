#include<stdio.h>
int main()
{
	char str[50];
	int t,wall=0,i=1,j=0,max=0;
	printf("Enter a string:\n");
	scanf("%s",str);
	while(str[i]!='\0')
	{
		t=1;
		j=i-1;
		while(j>wall)
		{
			if(str[i]==str[j])
				break;
			j--;
			t++;
		}
		if(t>max)
		{
			max=t;
		}
		wall=j;
		i++;
	}
	printf("Longest substring without repetition is of length: %d\n",max);
	return 0;
}
