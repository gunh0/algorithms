/*
퀵정렬
배열 a에 원소가 25, 8, 3, 29, 73, 24, 78, 51, 30, 28이 있을 때,
오름차순으로 정렬한다.
*/

#include <stdio.h>

int a[10] = { 25, 8, 3, 29, 73, 24, 78, 51, 30, 28 };
int n = 10;

void quick_sort(int left, int right) {
	int pivot;
	int i, j, temp;
	int t;

	if (left < right) {
		pivot = a[left];
		i = left + 1;
		j = right;
		while (1) {
			while (a[i] < pivot)i++;
			while (a[j] > pivot)j--;
			if (i >= j)break;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		temp = a[j];
		a[j] = a[left];
		a[left] = temp;
		quick_sort(left, j - 1);
		quick_sort(j + 1, right);
	}
}

int main()
{
	int i;

	quick_sort(0, n - 1);
	for (i = 0; i < n; i++)
		printf("%3d", a[i]);

	return 0;
}