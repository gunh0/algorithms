/*
A, B, C, D, E 다섯 사람이 있을 때 이중 대표 3명을 뽑는 방법의 갯수를
출력하는 코드를 구현한다.
*/

#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	int n = 0, r = 0;
	int b[6][4];
	int min = 0;

	n = 5;	// 다섯명의 사람
	r = 3;	// 3명의 대표

	for (i = 0; i <= n; i++)
	{
		min = (i < r) ? i : r;
		for (j = 0; j <= min; j++)
		{
			if (j == 0 || j == i)b[i][j] = 1;
			else b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}

	printf("%d", b[n][r]);

	return 0;
}