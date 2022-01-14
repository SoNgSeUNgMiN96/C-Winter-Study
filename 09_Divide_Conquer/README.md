# Divide/Conquer (분할정복)

📌 어떤 문제를 해결하려 할 때 비슷한 작은 문제들로 나눠 해결한 후, 답을 도출해내는 방법


<br>

# 분할 정복 설계

1. Divide (분할) : 문제의 입력 사례를 둘 이상의 작은 입력 사례로 분할

2. Conquer (정복) : 작은 입력 사례들을 각각 정복 (충분히 작지 않다면 재귀 호출)

3. Combine (결합) : 필요하면, 정복한 사례들을 통합하여 원래 입력 사례의 답을 도출

<br>

![image](https://user-images.githubusercontent.com/56537513/149458160-1df0c2af-cfa4-4a64-a182-47c1f20810d3.png)

# 분할 정복 알고리즘

## 🏷️ Merge Sort (합병 정렬)

![image](https://user-images.githubusercontent.com/56537513/149458405-c44a789e-ed7a-4e93-a584-bb748c734073.png)

1) Divide
 → 입력 배열을 같은 크기의 2개의 부분 배열로 분할한다.
 
2) Conquer
 → 부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용하여 다시 분할 정복 방법을 적용한다.
 
3) Combine
 → 정렬된 부분 배열들을 하나의 배열에 합병한다.
 
 ### [ 합병 정렬 알고리즘 ]
 
  ```c
 void mergeSort(int data[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergeSort(data, p , q);
        mergeSort(data, q+1, r);
        merge(data, p, q, r);
    }
}
void merge(int data[], int p, int q, int r) {
    int i = p, j = q+1, k = p;
    int tmp[8]; // 새 배열
    while(i<=q && j<=r) {
        if(data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while(i<=q) tmp[k++] = data[i++];
    while(j<=r) tmp[k++] = data[j++];
    for(int a = p; a<=r; a++) data[a] = tmp[a];
}

```


## 🏷️ Quick Sort (퀵 정렬)

![image](https://user-images.githubusercontent.com/56537513/149458577-bd4700bd-b782-493a-971c-f9948c1ba48d.png)

1) Divide
 → 피봇 하나를 선택하여 피봇을 기준으로 2개의 부분 배열로 분할한다.
 
2) Conquer
 → 피봇을 기준으로 피봇보다 큰 값, 혹은 작은 값을 찾는다. 왼쪽에서 부터 피봇보다 큰 값을 찾고 오른쪽에서 부터는 피봇보다 작은 값을 찾아서 두 원소를 교환한다. 분할된 부분 배열의 크기가 0이나 1일 될때까지 반복한다.
 
3) Combine
 → Conquer과정에서 값의 위치가 바뀌므로 따로 결합은 하지 않는다.
 
 ### [ 퀵 정렬 알고리즘 ]
 
 ```c
 void QuickSort(A[], n) {
	if (n>1) {
    	pivot = Partition(A[0...n-1], n);	// 두 부분배열로 분할
        QuickSort(A[0...pivot-1], pivot);	// 왼쪽 부분배열 순환 호출
        QuickSort(A[pivot+1...n-1], n-pivot-1);	//오른쪽 부분배열 순환 호출
    }
}

int Partition(A[], n) {
	Left = 1;
    Right = n-1;
    
    while (Left < Right) {	// 피벗 A[0]
    	// 피벗보다 큰 값의 위치를 찾음
        while (Left < n && A[Left] < A[0]) Left++;
        // 피벗보다 작은 값의 위치를 찾음
        while (Right > 0 && A[Right] >= A[0]) Right--;
        // Left, Right 교환
        if (Left < Right) exchange(A[Left], A[Right]);
        // 피벗, Right 교환
        else exchange(A[0], A[Right]);
    }
}

```


## 🏷️ Binary Search (이진 탐색)

![image](https://user-images.githubusercontent.com/56537513/149458616-80482e45-0160-40ce-96f8-3477b80cb2f8.png)

1) Divide
 → 배열의 가운데 원소를 기준으로 왼쪽, 오른쪽 부분배열로 분할한다. 탐색키와 가운데 원소가 같으면 분할을 종료한다.
 
2) Conquer
 → 탐색키가 가운데 원소보다 작으면 왼쪽 부분배열을 대상으로 이진 탐색을 순환 호출하고, 크면 오른쪽 부분배열을 대상으로 이진 탐색을 호출한다.
 
3) Combine
 → 탐색 결과가 직접 반환되므로 결합이 불필요하다.

### [ 이진 탐색 알고리즘 - 재귀 형태 ]
```c
BinarySearch(A[], Left, Right, x) {
  if (Left > Right) return -1;	// 탐색 실패
  Mid = floor((Left + Right)/2);	// 바닥 함수
    
  if (x == A[Mid]) return Mid;
  else {
   if (x < Mid) BinarySearch(A, Left, Mid-1, x);	// 왼쪽 부분배열
   else BinarySearch(A, Mid+1, Right, x);	// 오른쪽 부분배열
  }
}

```
