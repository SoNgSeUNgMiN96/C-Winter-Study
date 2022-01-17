// 같은 수로 만들기 (백준 2374번)

/* [ 알고리즘 ]
* 
* 1. 연속으로 동일한 값은 그 중 하나만 체크하도록 설정 (추가해주지 않음)
* 2. 자신보다 작은 값이 나오면 그냥 본인 삭제되고 새로운 값 추가 (더 작은 값이 본인의 값까지 포함하기 때문)
* 3. 자신보다 큰 값이 나오면 두개의 차를 더해주고 본인 삭제하고 새로운 값 추가
* 4. 끝까지 가게 되면 이제 남은 값들을 제일 큰값에서 빼줌
* 
* - 제일 최근에 들어온걸 빼주는 후입선출(스택) 사용
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long Data;

struct Stack {
	Data data;
	struct Stack* link;
}typedef Stack;

typedef struct {
	Stack* top;
} Top;

typedef struct {
	Stack* bottom;
} Bottom;


Top* createStack(void) {
	Top* start_stack; // 이 부분이 이중포인터를 의미
	start_stack = (Top*)malloc(sizeof(Top));
	start_stack->top = NULL;
	return start_stack;
}

void push(Top* stack, Data data) {

	Stack* newstack;
	newstack = (Stack*)malloc(sizeof(Stack));
	newstack->data = data;

	newstack->link = stack->top; // stack으로 하면 오류뜸
	stack->top = newstack;
	return;
}

int isEmpty_Stack(Top* stack);

Data pop(Top* stack) {
	// Stack* temp = (Stack*)malloc(sizeof(Stack)); // 공간을 temp 주소에 할당해주고 사용하지 않고 다른 곳을 가리키게함
	// temp = stack->top;  // 그래서 이부분은 없어도됨
	Data item;
	if (isEmpty_Stack(stack)) {
		printf("빈 Stack 입니다.");
		return 0;
	}
	else {
		//item = temp->data; 
		//stack->top = temp->link;
		//free(temp);
		item = stack->top->data;
		stack->top = stack->top->link; // 이부분은 실제로 뒤로 밀려지는 부분이라 이렇게 작성해도 무방
		return item;
	}
}

int isEmpty_Stack(Top* stack) {
	if (stack->top == NULL) return 1;  // stack자체가 null 인지 볼게 아니라 stack->top이 null인지 판단해줘야함
	return 0;
}

Data peekStack(Top* stack) {

	if (isEmpty_Stack(stack)) {
		return 0;
	}
	else {
		Data data = stack->top->data;
		return data;
	}
}

int main() {
	int n;
	scanf("%d", &n); // 입력의 개수

	long* list = (long*)malloc(sizeof(long) * (n + 1));
	long max = 0; // 입력값중 최대값
	for (int i = 0; i < n; i++) {
		scanf("%ld", &list[i]);
		if (max < list[i]) max = list[i];
	}

	Top* stack;
	stack = createStack();
	long answer=0;

	for (int i = 0; i < n; i++) {
		if (isEmpty_Stack(stack)) push(stack, list[i]);
		else {
			if (peekStack(stack) > list[i]) {
				pop(stack);
				push(stack, list[i]);
			}
			else if (peekStack(stack) < list[i]) {
				answer += list[i] - pop(stack);
				push(stack, list[i]);
			}
			else { // 동일한 경우
				continue;
			}
		}
	}

	while (!isEmpty_Stack(stack)) {
		answer += max - pop(stack);
	}

	printf("%ld", answer);
	return 0;
}