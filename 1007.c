/*
大素数对
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//
int sushu(int number)
{
	for(int i = 2;i <= sqrt(number);i++)
	{
		if(number % i == 0)
			return 0;
	}
	return number;
}

int main(int argc, char const *argv[])
{
	int a = 0;
	int b = 2;
	int total = 0;
	int max;
	scanf("%d", &max);
	for(int tmp = 3;tmp <= max;tmp++)
	{
		if(sushu(tmp))
		{
			if(a < b)
				a = tmp;
			else
				b = tmp;
			if(abs(a - b) == 2)
				total++;
		}
	}
	printf("%d", total);
	return 0;
}