/*
1개 이상의 원소를 가진 집합의 순열을 출력하기.

예를 들어 집합 {a, b, c}가 있다면 출력되는 모든 순열은 다음과 같다.
abc, acb, bac, bca, cba, cab
이는 다음과 같은 방식으로 구성할 수 있다.
a를 출력하고 그뒤에 {b, c}의 순열을 모두 열거한다.
b를 출력하고 그뒤에 {a, c}의 순열을 모두 열거한다.
c를 출력하고 그뒤에 {b, c}의 순열을 모두 열거한다.
즉 원소 n개에 대한 순열은 원소(n-1)개에 대한 순열을 이용하여 순환적으로 구성할 수 있다.
*/

#include <stdio.h>

char set[3] = { 'a','b','c' };
int n = 3;

void makeperm(int k) {
	int i;
	char temp;

	if (k == n) {
		for (i = 0; i < n; i++)
			printf("%c", set[i]);
		printf("\n");
	}
	else {
		for (i = k; i < n; i++) {
			temp = set[i];
			set[i] = set[k];
			set[k] = temp;

			makeperm(k + 1);

			temp = set[i];
			set[i] = set[k];
			set[k] = temp;
		}
	}
}

int main()
{
	makeperm(0);
}