#include <stdio.h>
#include <stdlib.h>

void check(int n)
{
	for(;n>0;n--)
	{
		int a1=0;int a2=0;int a3=0;
		char str[100];
		int flag=0;
		scanf("%s",str);
		int tmpP=0;int tmpT=0;int tmpA=0;
		for(int i = 0;str[i];i++)
		{
			if(str[i]!='P'&&str[i]!='A'&&str[i]!='T')
				{
					printf("NO\n");
					flag=1;
					break;
				}
			if(str[i]=='P')
				tmpP++;
			if(str[i]=='T')
				tmpT++;
			if (str[i]=='A')
				tmpA++;
		}
		if(flag==1)
			continue;
		if(tmpT!=1||tmpP!=1||tmpA==0)
		{
			printf("NO\n");
			continue;
		}
		//
		for(int i = 0,flag=0;str[i];i++)
		{
			switch(flag)
			{
				case 0:
				{
					if(str[i] == 'P')
					{
						flag = 1;
						continue;
					}
					else
						a1++;
					continue;
				}
				case 1:
				{
					if(str[i]=='T')
					{
						flag = 2;
						continue;
					}
					else
						a2++;
					continue;
				}
				case 2:
				{
					if(str[i])
					{
						a3++;
						continue;
					}
				}
			}
		}
		if(a1*a2==a3)
			printf("YES\n");
		else
			printf("NO\n");
	}

}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	check(n);
	return 0;
}