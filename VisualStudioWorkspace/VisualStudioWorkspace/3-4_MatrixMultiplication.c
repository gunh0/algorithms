/*
�־��� ����� ������ Ƚ���� ���� ���� �ǵ���
����� ���ϴ� ������ ����ϴ� ���α׷��� �ۼ�
*/

#include <stdio.h>

#define INT_MAX 1000

int cost[7][7];
int best[7][7];
char name[7] = { ' ','A','B','C','D','E','F' };	// ����� �̸�
int r[8] = { 0,4,2,3,1,2,2,3 };	// ����� ũ�� ��, A����� 4X2, B�� ����� 2X3 ...

int n = 6;	// ����� ����

dynamic() {
	int i = 0, j = 0, k = 0, t = 0;
	for (i = 0; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			cost[i][j] = INT_MAX;
		}
		for (i = 1; i <= n; i++)
		{
			cost[i][i] = 0;
		}
		for (j = 1; j < n; i++)
		{
			for (i = 1; i <= n - j; i++)
			{
				for(k=i+1;k<=)
			}
		}
	}
}

int main()
{
	return 0;
}