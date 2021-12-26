# Binary Search (이진탐색)



## 💎 Tips



## 🏷️ Manual

### 예시코드 (Binary_Search Code)
```c
// data : 탐색할 오름차순으로 정렬된 정수 배열
// n : 정수 배열의 크기
// key : 찾고자하는 값
int binsearch(int data[], int n, int key) {
    int low, high;
    int mid;
 
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == data[mid]) {            //탐색 성공
            return mid;        
        }
        else if (key < data[mid]) {        //탐색 범위를 아래쪽으로
            high = mid - 1;
        }
        else if (key > data[mid]) {        //탐색 범위를 위쪽으로
            low = mid + 1;
        }
    }
    return -1;                            //탐색 실패
}

```

### 예시코드2 (Binary_Search Code 적용 코드)
```c
#include <stdio.h>
 
int binsearch(int data[], int n, int key);
 
int main(int argc, char *argv[])
{
    int a[10] = { 2, 8, 13, 16, 20, 22, 34, 45, 56, 77 };    //정렬된 자료
    int index;
    int key;
 
    scanf("%d", &key);
    index = binsearch(a, 10, key);
    if (index == -1) {
        printf("자료가 없습니다!\n");
    }
    else {
        printf("자료가 %d번째에 있습니다.\n", index + 1);
    }
    return 0;
}

```

## 📚 References
