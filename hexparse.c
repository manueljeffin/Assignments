#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define HTOI(a,b) hextoint(a,b)
int* hextoint(char hstr[],int sz)
{
    int i,j,mul;
    int *arr;
    if(sz%2==0)
    {
        mul=16;
    }
    else
    {
        mul=1;
    }
    j=0;
    arr=(int*)malloc(((sz+1)/2)*sizeof(int));
    memset(arr,0,(sz+1)/2);
    for(i=0;i<sz;i++)
    {
        if(hstr[i]>='0'&&hstr[i]<='9')
        {
            arr[j]=arr[j]+(hstr[i]-'0')*mul;
        }
        else
        {
            arr[j]=arr[j]+(hstr[i]-'A'+10)*mul;
        }
        if(mul==16)
        {
            mul=1;
        }
        else
        {
            mul=16;
            j++;
        }
    }
    return arr;
}
int main()
{
    char hstr[65];
    int *arr;
    int i,sz;
    printf("Enter the hex string:\n");
    scanf("%s",hstr);
    sz=strlen(hstr);
    arr=HTOI(hstr,sz);
    sz=(sz+1)/2;
    printf("Result:\n");
    for(i=0;i<sz;i++)
    {
        printf("%x\n",arr[i]);
    }
    return 0;
}
