/*
A, B, C, D, E �ټ� ����� ���� �� ���� ��ǥ 3���� �̴� ����� ������
����ϴ� �ڵ带 �����Ѵ�.
*/

#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	int n = 0, r = 0;
	int b[6][4];
	int min = 0;

	n = 5;	// �ټ����� ���
	r = 3;	// 3���� ��ǥ

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