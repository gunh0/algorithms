/*
� ���ڰ��� ���� ����鿡�� ���� �����ؼ� �ִ��� ������ ����� �Ѵ�.
��, ���ڴ� ���������� �� �� ������ �� ����� ���� �����Ҽ��� ���� ������ ���ڰ����� �����ش�.
���� �������� ���� ���� �翬�� ��ԵǴ� ���͵� ����.
*/

#include <stdio.h>
#define COM 20	// �ִ� 20���� ���
#define MAX_INVEST 300	// �ִ� 300�������� ���� ����

int dynamic[COM][MAX_INVEST];
int invest[COM][MAX_INVEST];	// COM��° ȸ�翡 ������ �ݾ�

int c = 2;	// 2�� ȸ��
int m = 4;	// 4����

int main()
{
	int in[MAX_INVEST][COM] = { {0,0,0},{0,5,1},{0,6,5},{0,7,9},{0,8,15} };
	int i, j, k;

	for (i = 0; i <= c; i++)
		dynamic[0][i] = 0;
	for (i = 0; i <= m; i++)
		dynamic[i][0] = 0;

	for (i = 1; i <= c; i++)	// i�� ���� ��� ��ȣ
	{
		for (j = 1; j <= m; j++)	// j�� ���� ����� ������ �ݾ�
		{
			for (k = 0; k <= j;  k++)	// ���� ������ ������� ������ �ݾ�
			{
				if (dynamic[j][i] < dynamic[k][i - 1] + in[j - k][i])
				{
					dynamic[j][i] = dynamic[k][i - 1] + in[j - k][i];
					invest[j][i] = j - k;
				}
			}
		}
	}

	printf("Max Benefit : %d\n", dynamic[m][c]);
	
	return 0;
}