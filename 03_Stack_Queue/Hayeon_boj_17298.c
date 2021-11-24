//  오큰수 (백준 17298번)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode
{
	element data;
	struct stackNode *link;
} stackNode;

stackNode *top;

int isEmpty()
{
	if (top == NULL)
		return 1;
	else
		return 0;
}

void push(element item)
{
	stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()
{
	element item;
	stackNode *temp = top;

	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else
	{
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek()
{
	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else
	{
		return (top->data);
	}
}

void printStack()
{
	stackNode *p = top;
	printf("\n STACK [ ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

void main()
{
	int N = 0;
	scanf("%d", &N);

	int *arr = (int *)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	int *answer = (int *)malloc(sizeof(int) * N);
	int j = 0;

	for (int i = N - 1; i >= 0; i--) // 3 5 2 7
	{
		if (i == N - 1)
		{
			answer[j] = -1;
			j++;
			push(arr[i]);
			continue;
		}
		while (!isEmpty())
		{
			if (arr[i] < peek())
			{
				answer[j] = peek();
				j++;
				push(arr[i]);
				break;
			}
			else
			{
				pop();
			}
		}
		if (isEmpty())
		{
			answer[j] = -1;
			j++;
			push(arr[i]);
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		printf("%d ", answer[i]);
	}
}