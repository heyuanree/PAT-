/*
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。
输入样例1：

234

输出样例1：

BBSSS1234

输入样例2：

23

输出样例2：

SS123

*/

#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_INIT_SIZE
#define STACK_INIT_SIZE 31
#endif

//stack
typedef struct
{
	char *base;
	char *top;
	int stackscize;
}stack;

//init
void initStack(stack &S)
{
	S.base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base) exit(0);
	S.top = S.base;
	S.stackscize = STACK_INIT_SIZE;
}

//push
void push(stack &S, char ch)
{
	if (S.top - S.base >= S.stackscize) exit(0);
	*S.top++ = ch;
}

//pop
void pop(stack &S, char &ch)
{
	if (S.top == S.base) exit(0);
	ch = *--S.top;
}

//printf
void print(stack &S)
{
	char ch;
	while (S.top > S.base)
	{
		pop(S, ch);
		printf("%c", ch);
	}
}

//console
void console()
{

	int number;
	int i = 0;
	scanf("%d", &number);
	int tmp = number % 10;
	number = number / 10;
	stack  stackPt;
	initStack(stackPt);
	char a;
	for(int i = tmp ; i > 0; i--)
	{
		a = (char)(i + '0');
		push(stackPt, a);
	}
	while (number)
	{
		switch (i)
		{
		case 0: for (int i = 0; i < number % 10; i++) push(stackPt, 'S'); i++; break;
		case 1: for (int i = 0; i<number % 10; i++) push(stackPt, 'B'); break;
		}
		number = number / 10;
	}

	print(stackPt);
}

int main(int argc, char const *argv[])
{
	console();
	return 0;
}