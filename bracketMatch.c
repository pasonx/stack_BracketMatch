#include <stdio.h>
#include <stdlib.h>

#define MAX 100 
typedef struct stack{
	char ch[MAX];
	int top;
}stack;
void InitStack(stack * s)
{
	s->top = -1;
}
bool isEmpty(stack * s)
{
	if (s->top == -1)
		return true;
	return false;
}
int Push(stack * s, char ch)
{
	if (s->top == MAX - 1)
		return -1;
	s->top++;
	s->ch[s->top] = ch;
	return 0;
}
int Pop(stack * s, char * ch)
{
	if (s->top == -1)
		return -1;
	*ch = s->ch[s->top];
	s->top--;
	return 0;
}
int getTop(stack * s, char * ch)
{
	if (s->top == -1)
		return -1;
	*ch = s->ch[s->top];
	return 0;
}
bool Match(char ch, char str)
{
	if (ch == '(' && str == ')')
		return true;
	if (ch == '[' && str == ']')
		return true;
	if (ch == '{' && str == '}')
		return true;
	else
		return false;
}

int main()
{
	stack s;
	char ch;
	char str[100];
	gets(str);
	InitStack(&s);
	for (int i = 0; str[i] != NULL; i++)
	{
		switch (str[i])
		{
		case '(':
		case '{':
		case '[':
			Push(&s, str[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (isEmpty(&s))
				printf("Do not match!\n");
			else
			{
				getTop(&s, &ch);
				if (Match(ch, str[i]))
					Pop(&s, &ch);
				else
					printf("Do not match\n");
			}
		}
	}
	if (isEmpty(&s))
		printf("Match\n");
	else
		printf("Do not match!\n");
	return 0;
}
