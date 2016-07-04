#include<stdio.h>
int main()
{
	//see file paper
	char str[50];
	int t,wall=0,i=1,j=0,max=0;
	printf("Enter a string:\n");
	scanf("%s",str);
	//wall sets the limit till which we have to scan , t is the length 
	//wall with recognize that something is repeating, at the end of the repeating substring and update itself,
	//for eg: in ababc, wall will update itself wen j is at index 3 and i is at index 4
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
