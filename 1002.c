#include <stdlib.h>
#include <stdio.h>

char str[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int sum;

int number()
{
	int sum = 0;
	char tmp;
	while((tmp = getchar()) != '\n')
	{
		sum += tmp -'0';
	}
	return sum;
}

void output(int sum,int a)
{
/*
	while(sum!=0)
	{
		int tmp = 0;
		tmp = sum%10;
		sum = sum/10;
		printf("%s",str[tmp]);
		if(sum>0)
			printf(" ");
	}
*/
	if(a>=10)
		output(sum,a/10);
	printf("%s",str[a%10]);
	if(a!=sum)
		printf(" ");
}
int main()
{
	sum = number();
	output(sum,sum);
	return 0;
}