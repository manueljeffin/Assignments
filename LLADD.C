#include<stdio.h>
#include<stdlib.h>
struct node
{
	int digit;
	struct node *nxt;
}*h1=NULL,*h2=NULL,*res=NULL,*tmp=NULL;
int l1=0,l2=0;
struct node* insert(int x,struct node *head)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->digit=x;
	if(head==NULL)
	{
		temp->nxt=NULL;
	}
	else
	{
		temp->nxt=head;
	}
	head=temp;
	return head;
}
struct node* create(int x,struct node *head)
{
	int len=0;
	while(x>0)
	{
		head=insert(x%10,head);
		x/=10;
		len++;
	}
	if(l1==0)
	{
		l1=len;
	}
	else
	{
		l2=len;
	}
	return head;
}
struct node* add(struct node *hd1,struct node *hd2)
{
	int diff,mul=1,sum=0;
	struct node *t1,*t2;
	diff=abs(l1-l2);
	if(l1>l2)
	{
		t1=hd1;
		t2=hd2;
	}
	else
	{
		t1=hd2;
		t2=hd1;
	}
	while(diff>0)
	{
		tmp=insert(t1->digit,tmp);
		t1=t1->nxt;
		diff--;
	}
	while(t1!=NULL)
	{
		tmp=insert(t1->digit+t2->digit,tmp);
		t1=t1->nxt;
		t2=t2->nxt;
	}
	while(tmp!=NULL)
	{
		sum=sum+tmp->digit*mul;
		mul=mul*10;
		tmp=tmp->nxt;
	}
	res=create(sum,res);
	return res;
}
int main()
{
	int a,b,c;
	struct node *res;
	printf("Enter two numbers:\n");
	scanf("%d%d",&a,&b);
	h1=create(a,h1);
	h2=create(b,h2);
	res=add(h1,h2);
	while(res!=NULL)
	{
		printf("%d",res->digit);
		res=res->nxt;
	}
	return 0;
}



