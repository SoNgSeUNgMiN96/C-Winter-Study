//
//  main.c
//  MissingBracket
//
//  Created by rabbi on 2021/12/21.
//

// No. 1541

// 세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
// 그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
// 괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

// 첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
// 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
// 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

// 1. 문자열 리터럴의 주소가 할당된 포인터는 scanf 함수에서 사용할 수 없다.(포인터에 저장된 메모리의 주소는 읽기 전용 메모리를 가리키고 있기 때문, 쓰기가 불가능)
// 2. 입력값을 문자열 포인터에 저장하려면 문자열이 들어갈 공간을 할당해주어야 한다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char equation[100]; // 입력받는 식
    char* token;
    char* sArr[30] = {NULL, }; // "-"로 파싱한 문자열들을 저장하는 문자열 배열
    int num[50];
    int i = 0; // "-" 기준으로 파싱할 때의 인덱스(개수)
    int count = 0; // 숫자의 개수
    int sum = 0; // "-" 기준으로 파싱했을 때의 나눠진 문자열의 합
    int result = 0; // 계산한 후의 값
    scanf("%s", equation);
    
    // 식을 "-"로 파싱
    sArr[i] = strtok(equation, "-");

    while(sArr[i] != NULL) {
        sArr[++i] = strtok(NULL, "-");
    }

    // "+" 파싱 및 계산
    for(int j = 0; j < i; j++) {
        // "+"가 포함되어 있다면(숫자가 아니라면)
        if(strstr(sArr[j], "+")) {
            token = strtok(sArr[j], "+");
            while(token != NULL) {
                sum += atoi(token); // 문자열을 숫자로 변환
                token = strtok(NULL, "+");
            }
            num[count++] = sum;
        } else {
            num[count++] = atoi(sArr[j]);
        }
        sum = 0; // sum 0으로 초기화
    }
    
    // 계산
    result = num[0];
    for(int k = 1; k < count; k++) {
        result -= num[k];
    }
    printf("%d", result);
}
