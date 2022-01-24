// 종이의 개수 (백준 1780번)

/* [ 알고리즘 ]
 *
 * 1. 완전탐색으로 종이가 모두 같은 수로 되어있는지 체크
 * 2. 같은 수로 되어있으면 각각 -1, 0, 1 로만 이루어진 종이의 개수를 카운트해줌
 * 3. 만약, 같은 수로 되어있지 않다면 3^k*1, 3^k*2, 3^k*3 으로 (가로, 세로) 분할
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void partition(int** map, int w, int l, int size);
bool check(int** map, int w, int l, int size);

int zeroCount = 0;  // 0
int minusCount = 0; // -1
int plusCount = 0;  // 1

int main() {
	int N;
	scanf("%d", &N);

	int** map;
	map = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		map[i] = (int*)malloc(sizeof(int) * N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	partition(map, 0, 0, N);

	printf("%d\n%d\n%d", minusCount, zeroCount, plusCount);

	for (int i = 0; i < N; i++) {
		free(map[i]);
	}
	free(map);
}

void partition(int**map, int w, int l, int size) {
	if (check(map, w, l, size)) {
		switch (map[l][w]) {
			case 0: zeroCount++; break;
			case -1: minusCount++; break;
			case 1: plusCount++; break;
			default: break;
		}
	}
	else {
		/*
			 *  A B C
			 *  D E F
			 *  G H I
			 */
		int resize = size / 3;

		// A
		partition(map, w, l, resize);
		// B
		partition(map, w + resize, l, resize);
		// C
		partition(map, w + resize * 2, l, resize);
		// D
		partition(map, w, l + resize, resize);
		// E
		partition(map, w + resize, l + resize, resize);
		// F
		partition(map, w + resize * 2, l + resize, resize);
		// G
		partition(map, w, l + resize * 2, resize);
		// H
		partition(map, w + resize, l + resize * 2, resize);
		// I
		partition(map, w + resize * 2, l + resize * 2, resize);
	}
	return;
}

bool check(int** map, int w, int l, int size) {
	int color = map[l][w];

	for (int i = l; i < l +size; i++) {
		for (int j = w; j < w + size; j++) {
			if (map[i][j] != color) return false;
		}
	}
	return true;
}