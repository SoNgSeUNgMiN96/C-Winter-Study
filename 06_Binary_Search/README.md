# Binary Search (이진탐색)


## 💎 Tips

📌 이미  `정렬` 되어 있는 배열에서 탐색 범위를 반씩 줄여 가며 찾고자 하는 값을 찾는 탐색 방법


- 최악의 경우에도 선형 탐색보다 시간복잡도가 좋은 효율적인 탐색 방법
- 시간복잡도 : O(logN)



## 🏷️ Manual

[ 구현 순서 ] 

1. 배열을 정렬
2. 정렬된 배열에서 양쪽 끝 인덱스를 이용해 중간 인덱스를 찾음(mid)
3. mid 인덱스와 배열에서 찾고자 하는 값(target)을 비교
4. target이 나올 때까지 탐색 과정을 반복
   - mid값보다 target이 크면 left를 mid+1로 이동시키고 오른쪽 구간을 탐색
   - mid값보다 target이 작다면 right를 mid-1로 이동시키고 왼쪽 구간을 탐색
5. target이 없다면 None을 반환

[ 구현 방식 ]

1. 정렬
2. 반복 || 재귀

---

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

### 🧐 이분 탐색 vs 투 포인터

> **이분 탐색**
> 
- 시간복잡도 : O(logN)
- 가정 : 데이터가 정렬되어 있어야 함
- 방식 : mid를 활용해 매 연산마다 탐색하는 범위를 절반으로 좁혀 나감

> **투 포인터**
> 
- 시간복잡도 : O(N)
- 가정 : X
- 방식 : 양끝단에서 한칸씩 이동하면서 알맞는 값을 찾음
