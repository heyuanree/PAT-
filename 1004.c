/*
输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩

其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112
 */

#include <stdio.h>
#include <stdlib.h>

//input the number of the students
int Number()
{
	int number;
	scanf("%d",&number);
	return number;
}
//struct define
typedef struct studentScoreNode
{
	char name[11];
	char number[11];
	int score;
	struct studentScoreNode *next;
}studentScoreNode, *studentScoreList;

//initnode
studentScoreList initNode()
{
	studentScoreList head;
	head->next = NULL;
	return(head);
}

//input score
void inputNumber(studentScoreList head)
{
	studentScoreList p = head;
	studentScoreList s;
	char c;
	int i = 0;
	while(p->next)
	{
		p = p->next;
	}
	s = (studentScoreList) malloc(sizeof(studentScoreNode));
	while((c = getchar()) != ' ')
	{
		s->name[i] = c;
		i++;
	}
	i = 0;
	while((c = getchar()) != ' ')
	{
		s->number[i] = c;
		i++;
	}
	scanf("%d", &s->score);
	s->next = p->next;
	p->next = s;
}

//compare
void compare(studentScoreList head, int *flag)
{
	//int flag[3] = 0;
	studentScoreList p = head;
	int i = 0
	//first
	while(p)
	{
		p = p->next;
		if(flag[0]<p->score)
			{
				flag[0] = p->score;
				flag[1] = i;
			}
		i++;
	}
	i = 0;p = head;flag[0]=0;
	while(p)
	{
		p = p->next;
		if(flag[0]<p->score && flag[0]<flag[1])
		{
			flag[0] = p->score;
			flag[2] = i;
		}
		i++;
	}
}

//output
void output(studentScoreList head,int* flag)
{
	int i = 0;
	for(int j = 0;j<=1;j++)
	{
		while(p && i<flag[i])
			{
				p = p->next;
			}
		printf("%s ", p->name);
		printf("%s ", p->number);
		printf("%d\n", p->score);
		p = head;
	}
}

//console
void console()
{
	int number;
	number = Number();
	studentScoreList head;
	head = initNode();
	while(number)
	{
		inputNumber(head);
		number--;
	}
	//
	int flag[3] = 0;
	compare(head, flag);
	//
	output(head);
}

int main(int argc, char const *argv[])
{
	console();
	return 0;
}