/* �ΰ��� ���ڿ� A, B�� ������ ���� �־����� ��
A�� B�� ������ �κ� ���ڿ� �� ���� �� ���� ���Ͻÿ�.

A=abcbdab
B=bdcaba
*/

#include <stdio.h>
char A[8] = { ' ', 'a', 'b', 'c', 'b', 'd', 'a', 'b' };	/* ���ڿ� A */
char B[7] = { ' ', 'b', 'd', 'c', 'a', 'b', 'a' };	/* ���ڿ� B */

int c[7][8];	/* �ִ� ���ڿ��� ���� */
int d[7][8];	/* �ִ� ���ڿ��� �ǵ����ϴ� ������ ���� */

void length_lcs() {
	int i, j;

	for (i = 0; i < 8; i++)
		c[i][0] = 0;
	for (j = 0; j < 7; j++)
		c[0][j] = 0;

	for (i = 1; i < 8; i++)
	{
		for (j = 1; j < 7; j++)
		{
			if (A[i] == B[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				d[i][j] = 0;	// �밢��
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				d[i][j] = 1;	// ����, �� A���ڿ����� ���� ���ڰ� B���ڿ��� ������
				// �� ���ڸ� ���ܽ�Ű�� B���ڿ����� ��ġ�� �ϳ� ����.
			}
			else
			{
				c[i][j] = c[i][j - 1];
				d[i][j] = 2;	// ����, �� B���ڿ����� ���� ���ڰ� A���ڿ��� ������
				// �� ���ڸ� ���ܽ�Ű�� A���ڿ��� ��ġ�� �ϳ� ����.
			}
		}
	}
}

void print_lcs(int i, int j)
{
	if (i == 0 || j == 0) return;
	if (d[i][j] == 0)
	{
		print_lcs(i - 1, j - 1);
		printf("%c", A[i]);
	}
	else if (d[i][j] == 1)
		print_lcs(i - 1, j);
	else print_lcs(i, j - 1);
}

int main()
{
	int i, j;

	length_lcs();
	print_lcs(7,6);
	return 0;
}