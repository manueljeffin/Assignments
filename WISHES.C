#include<stdio.h>
#include<dos.h>
int main()
{
	char arr[]="Happy pongal";
	int i=0;
	for(i=0;arr[i]!='\0';i++)
	{
		printf("%c",arr[i]);
		sleep(1);
	}
	return 0;
}