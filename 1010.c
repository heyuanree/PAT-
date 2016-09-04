/*

设计函数求一元多项式的导数。（注：xn（n为整数）的一阶导数为n*xn-1。）

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。
输入样例：

3 4 -5 2 6 1 -2 0

输出样例：

12 3 -10 1 6 0


 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int a[100];
	int b[100];
	int i = 0;
	int j = 0;
	int cur = 0;
	do
	{
		scanf("%d", &a[i]);
		i++;
	}while(getchar() != '\n');
	for(j = 0, cur = 0;j <= i - 2;)
	{
		if(a[j+1] == 0)
		{
			j = j + 2;
		}
		else
		{
			b[cur] = a[j] * a[j+1];
			b[cur+1] = a[j+1] - 1;
			j = j + 2;
			cur = cur + 2;
		}
	}
	if(cur == 0)
		printf("0 0");
	else
	{
		for(int k = 0;k < cur;k++)
		{
			if(k != cur - 1)
				printf("%d ",b[k]);
			else
				printf("%d", b[k]);
		}
	}
	return 0;
}