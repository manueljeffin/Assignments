#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct wordstore
{
	char word[50];
	int n;
};
int scan(char str[],struct wordstore warr[],int wcnt)
{
	int i;
	for(i=0;i<wcnt;i++)
	{
		if(strcmp(warr[i].word,str)==0)
		{
			warr[i].n++;
			return wcnt;
		}
	}
	strcpy(warr[wcnt].word,str);
	warr[wcnt].n=1;
	wcnt++;
	return wcnt;
}
int main()
{
	char temp[50],fname[100];
	char nxt;
	int ti=0,ch=1,wcnt=0,pcnt=0,lcnt=0,twcnt=0,i=0,tcnt=0;
	int mc1=0,mc2=-1,mc3=-1;
	int mw1=0,mw2=-1,mw3=-1;
	int mp=0;
	int f=1;
	int carr[27]={0};
	FILE *fp;
	struct wordstore warr[500],parr[500];
	printf("Enter file name:\t");
	scanf("%s",fname);
	fp=fopen(fname,"r");
	while((nxt=getc(fp))!=EOF)
	{
		if(isalpha(nxt))
		{
			lcnt++;
			nxt=toupper(nxt);
			temp[ti]=nxt;
			ti++;
			carr[nxt-'A']++;
		}
		else
		{
			temp[ti]='\0';
			if(nxt!=' '&&nxt!='\n')
			{
				carr[26]++;
			}
			if(ti!=0)
			{
				twcnt++;
				wcnt=scan(temp,warr,wcnt);
				if(f==1)
				{
					pcnt=scan(temp,parr,pcnt);
					f=0;
				}
				ti=0;
			}
			if(nxt=='\n')
			{
				f=1;
			}
		}
	}
	fclose(fp);
	for(i=0;i<26;i++)
	{
		if(carr[i]>=carr[mc1])
		{
			mc3=mc2;
			mc2=mc1;
			mc1=i;
		}
		else if(carr[i]>=carr[mc2]&&mc2>=0)
		{
			mc3=mc2;
			mc2=i;
		}
		else if(carr[i]>=carr[mc3]&&mc3>=0)
		{
			mc3=i;
		}
	}
	for(i=0;i<wcnt;i++)
	{
		if(warr[i].n>=warr[mw1].n)
		{
			mw3=mw2;
			mw2=mw1;
			mw1=i;
		}
		else if(warr[i].n>=warr[mw2].n&&mw2>=0)
		{
			mw3=mw2;
			mw2=i;
		}
		else if(warr[i].n>=warr[mw3].n&&mw3>=0)
		{
			mw3=i;
		}
	}
	for(i=0;i<pcnt;i++)
	{
		if(parr[i].n>=parr[mp].n)
		{
			mp=i;
		}
	}
	while(ch!=9)
	{
		printf("1.Number of words\n");
		printf("2.Number of letters\n");
		printf("3.Number of symbols\n");
		printf("4.Top 3 most common words\n");
		printf("5.Top 3 most common letters\n");
		printf("6.Most common first word of paragraphs\n");
		printf("7.Number of words used only once\n");
		printf("8.Unused letters in the document\n");
		printf("9.Exit\n");
		printf("Enter your choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Total no. of words:\t%d\n",twcnt);
				break;
			case 2:
				printf("Total no. of letters:\t%d\n",lcnt);
				break;
			case 3:
				printf("Total no. of symbols:\t%d\n",carr[26]);
				break;
			case 4:
				printf("Most common words:\n");
				if(wcnt>=1)
				{
					printf("1.%s\n",warr[mw1].word);
					if(wcnt>=2)
					{
						printf("2.%s\n",warr[mw2].word);
						if(wcnt>=3)
						{
							printf("3.%s\n",warr[mw3].word);
						}
					}
				}
				break;
			case 5:
				tcnt=lcnt;
				printf("Most common letters:\n");
				if(tcnt>=1)
				{
					printf("1.%c\n",mc1+'A');
					tcnt-=carr[mc1];
					if(tcnt>=1)
					{
						printf("2.%c\n",mc2+'A');
						tcnt-=carr[mc2];
						if(tcnt>=-1)
						{
							printf("3.%c\n",mc3+'A');
						}
					}
				}
				break;
			case 6:
				printf("Most common first word of paragraphs:\n");
				if(pcnt>=1)
				{
					printf("%s\n",parr[mp].word);
				}
				break;
			case 7:
				printf("Words used only once:\n");
				for(i=0;i<wcnt;i++)
				{
					if(warr[i].n==1)
					{
						printf("%s, ",warr[i].word);
					}
				}
				printf("\n");
				break;
			case 8:
				printf("Unused letters:\n");
				for(i=0;i<26;i++)
				{
					if(carr[i]==0)
					{
						printf("%c, ",i+'A');
					}
				}
				printf("\n");
				break;
			default:
				break;
		}
	}
	return 0;
}