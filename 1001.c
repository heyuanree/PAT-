#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	do
	{
		scanf("%d",&a);
		if (a>10000 && a<0)
		{
			printf("请输入数字\n");
			continue;
		}
	}while(0);
	while(a!=1)
	{
		if(a%2==0)
		{
			a = a/2;
		}
		else
		{
			a = (3*a+1)/2;
		}
		b++;
	}
	printf("%d",b);
}