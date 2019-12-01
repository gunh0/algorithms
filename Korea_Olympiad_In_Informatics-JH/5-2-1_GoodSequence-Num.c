/*
숫자 1, 2, 3으로만 이루어지는 수열이 있다.
임의 길이의 인접한 두개의 부분 수열이 동일한 것이 있으면,
그 수열을 나쁜 수열이라고 부른다.
그렇지 않은 수열은 좋은 수열이다.

다음은 나쁜 수열의 예이다.
33
32121323
123123213

다음은 좋은 수열의 예이다.
2
32
32123
1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하시오.
예를들면, 1213121과 2123212는 모두 좋은 수열이지만 그중에서 작은 수를 나타내는 수열은 1213121이다.
*/

#include <stdio.h>

int str[7];
int n = 7;

void make(int len) {
	int i, j, k, flag, cnt;

	if (len == n)
	{
		for (i = 0; i < n; i++)
			printf("%d", str[i]);
		exit();
	}
	else {
		for (i = 1; i <= 3; i++) {
			flag = 1;
			cnt = 0;
			str[len] = i;
			for (j = 1; j <= (len + 1) / 2; j++) {
				for (k = 0; k < j; k++) {
					if (str[len - j - k] == str[len - k])
						cnt += 1;
				}
				if (cnt == j) {
					flag = 0;	// 동일한 부분 수열이 있다.
					break;
				}
			}
			if (flag == 1)	make(len + 1);
		}
	}
}

int main() {
	make(0);
	return 0;
}