#include <iostream>

using namespace std;

int main(void) {
	int N;
	int Dp[1010] = {};
	int A[1010] = {};
	int max = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (min < Dp[j])
					min = Dp[j];
			}
		}
		Dp[i] = min + 1;
		if (max < Dp[i])
			max = Dp[i];
	}
	printf("%d\n", max);
	return 0;
}