//
//  main.c
//  RouterInstallation
//
//  Created by rabbi on 2022/01/03.
//

// No. 2110

// 도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
//
// 도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
//
// C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

// 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

// 첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

// 가장 인접한 두 공유기 사이의 거리가 최대 -> 모든 공유기들의 사이 간격이 공평하게 설치되기를 바라는 것

#include <stdio.h>
#include <stdlib.h>

// QuickSort
void QuickSort(int arr[], int left, int right) {
  int L = left, R = right;
  int temp;
  int pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

  //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
  while (L <= R) {

  //pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
    while (arr[L] < pivot) //left부터 증가하며 pivot 이상의 값을 찾음.
      L++;
    while (arr[R] > pivot) //right부터 감소하며 pivot 이하 값을 찾음.
      R--;
    //L, R 모두 최대 pivot 위치까지 이동.

    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
      if (L != R) { //같지 않은 경우만.
        temp = arr[L];
        arr[L] = arr[R];
        arr[R] = temp;
      } //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
      L++; R--; //그리고 L,R 한 칸 더 진행.
    }
  }

  if (left < R)
    QuickSort(arr, left, R);
  if (L < right)
    QuickSort(arr, L, right);
}

int main(int argc, const char * argv[]) {
    int num; // 집 개수
    int RouterNum; // 공유기 개수
    
    scanf("%d %d", &num, &RouterNum);
    
    int* house = (int*)malloc(sizeof(int) * num); // 집의 좌표를 저장하는 배열
    
    for(int i = 0; i < num; i++) {
        scanf("%d", &house[i]);
    }
    
    QuickSort(house, 0, num-1); // Sorting
    
    int count; // 공유기 개수 카운트 변수
    int left = 1; // 공유기 사이의 최소 거리
    int right = house[num-1] - house[0]; // 공유기 사이의 최대 거리
    int maxDistance = 0; // 갱신 거리(공유기 사이의)
    
    // 이분 탐색
    while(left<=right) {
        int mid = (left+right) / 2;
        
        int temp = house[0]; // 첫 번째 집에 공유기 설치
        
        count = 1; // 공유기 개수: 1
        
        for(int i = 1; i < num; i++) {
            if(house[i] - temp >= mid) { // 공유기 사이의 최소 간격을 mid로 설정
                count++; // 공유기 설치
                temp = house[i]; // temp를 다음 집으로 좌표 설정
            }
        }
        
        if(count >= RouterNum) { // 설치한 공유기 개수가 목표 개수보다 많다면
            left = mid + 1;
            maxDistance = mid;
        } else { // 설치한 공유기 개수가 목표 개수보다 적다면
            right = mid - 1;
        }
    }
    
    printf("%d", maxDistance);
    
    return 0;
}
