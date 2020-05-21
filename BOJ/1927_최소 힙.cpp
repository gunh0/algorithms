#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, input, endPoint = 0;
long long arr[100001];

void initHeap() {
	for (int i = 1; i < 100001; ++i) arr[i] = 2500000000;
}

void insertHeap(int input) {
	++endPoint;
	int cur = endPoint;
	while (cur > 0) {
		if (arr[cur / 2] > input) {
			arr[cur] = arr[cur / 2];
			cur = cur / 2;
		}
		else break;
	}
	arr[cur] = input;
}

void popHeap() {
	if (!endPoint) {
		printf("0\n");
		return;
	}
	int root = 1, returnValue = arr[root], value = arr[endPoint];
	arr[endPoint] = 2500000000; --endPoint;
	if (!endPoint) {
		printf("%d\n", returnValue);
		return;
	}
	while (root * 2 + 1 < 100001 && (value > arr[root * 2] || value > arr[root * 2 + 1])) {
		if (arr[root * 2] > arr[root * 2 + 1]) {
			arr[root] = arr[root * 2 + 1];
			root = root * 2 + 1;
		}
		else {
			arr[root] = arr[root * 2];
			root = root * 2;
		}
	}
	arr[root] = value;
	printf("%d\n", returnValue);
}

int main(void) {
	initHeap();
	scanf("%d", &N);
	for (int n = 0; n < N; ++n) {
		scanf("%d", &input);
		if (!input) {
			popHeap();
		}
		else insertHeap(input);
	}
}