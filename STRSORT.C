#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct intstr
{
	char a[10];
	int sz;
};
int main()
{
	int i,j,len,mi;
	struct intstr *arr;
	struct intstr tmp,min;
	printf("Enter no. of elements:\n");
	scanf("%d",&len);
	arr=(struct intstr *)malloc(len*sizeof(struct intstr));
	printf("Enter array elements:\n");
	for(i=0;i<len;i++)
	{
		scanf("%s",arr[i].a);
		arr[i].sz=strlen(arr[i].a);
	}
	for(i=0;i<len-1;i++)
	{
		min=arr[i];
		for(j=i+1;j<len;j++)
		{
			if(arr[j].sz<min.sz)
			{
				min=arr[j];
				mi=j;
			}
			else if(arr[j].sz==min.sz)
			{
				if(strcmp(arr[j].a,min.a)<0)
				{
					min=arr[j];
					mi=j;
				}
			}
		}
		tmp=arr[i];
		arr[i]=arr[mi];
		arr[mi]=tmp;
	}
	printf("Sorted array:\n");
	for(i=0;i<len;i++)
	{
		printf("%s\n",arr[i].a);
	}
	return 0;
}