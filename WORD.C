#include<stdio.h>
void printdigit(char x)
{
	switch(x)
	{
		case '1':
			printf("one ");
			break;
		case '2':
			printf("two ");
			break;
		case '3':
			printf("three ");
			break;
		case '4':
			printf("four ");
			break;
		case '5':
			printf("five ");
			break;
		case '6':
			printf("six ");
			break;
		case '7':
			printf("seven ");
			break;
		case '8':
			printf("eight ");
			break;
		case '9':
			printf("nine ");
			break;
		default:
			break;
	}
}
int main()
{
	char b[4],a[4];
	int i,j,k=0;
	printf("Enter the number:\t");
	scanf("%s",b);
	for(i=0;b[i]!='\0';i++);
	for(j=3;i>=0;j--,i--)
	{
		a[j]=b[i];
	}
	while(j>=0)
	{
		a[j--]='0';
	}
	printf("In words:\t");
	if(a[0]!='0')
	{
		printdigit(a[0]);
		printf("hundred ");
		k=1;
	}
	if(k==1)
	{
		printf("and ");
	}
	switch(a[1])
	{
		case '0':
			break;
		case '1':
			switch(a[2])
			{
				case '0':
					printf("ten ");
					break;
				case '1':
					printf("eleven ");
					break;
				case '2':
					printf("twelve ");
					break;
				case '3':
					printf("thirteen ");
					break;
				case '4':
					printf("fourteen ");
					break;
				case '5':
					printf("fifteen ");
					break;
				case '6':
					printf("sixteen ");
					break;
				case '7':
					printf("seventeen ");
					break;
				case '8':
					printf("eighteen ");
					break;
				case '9':
					printf("nineteen ");
					break;
				default:
					break;
			}
			break;
		case '2':
			printf("and twenty ");
			break;
		case '3':
			printf("and thirty ");
			break;
		case '4':
			printf("and fourty ");
			break;
		case '5':
			printf("and fifty ");
			break;
		case '6':
			printf("and sixty ");
			break;
		case '7':
			printf("and seventy ");
			break;
		case '8':
			printf("and eighty ");
			break;
		case '9':
			printf("and ninety ");
			break;
		default:
			break;
	}
	if(a[1]!='1')
	{
		if(a[2]!='0'&&a[1]!='0'&&a[2]=='0')
		{
			printf("and ");
		}
		printdigit(a[2]);
	}
	if(a[0]=='0'&&a[1]=='0'&&a[2]=='0')
	{
		printf("zero ");
	}
	printf("\n");
	return 0;
}
