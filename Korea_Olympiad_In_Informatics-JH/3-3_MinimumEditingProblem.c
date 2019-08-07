/*
���ڿ� A=aabab�� ���ڿ� b=babb�� �־��� ���� ��,
���ڿ� A�� ���ڿ� B�� ����(����, ����, ��ü)�Ͽ� �ٲٷ� �Ѵ�.
�̶� �����ϴ� Ƚ���� �ּҰ� �ǵ��� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� a(b�� ��ü)aba(����)b�� 2ȸ�� �������� �ٲ� �� �ִ�.
*/

#include <stdio.h>
char A[6] = { ' ','a','a','b','a','b' };
char B[5] = { ' ','b','a','b','b' };
int c[6][5];
int d[6][5];

void min_edit()
{
	int i = 0, j = 0;
	int x=0, y=0, z=0;
	
	for (i = 0; i <= 5; i++)
	{
		c[i][0] = i;
		d[i][0] = 1;	/* ���� �� */
	}
	for (j = 0; j < 4; j++)
	{
		c[0][j] = j;
		d[0][j] = 2;	/* ���� �� */
	}
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			x = c[i - 1][j] + 1;
			y = c[i][j - 1] + 1;
			if (A[i] == B[j]) z = c[i - 1][j - 1];
			else z = c[i - 1][j - 1] + 1;

			if (x <= y && x <= z) {
				c[i][j] = x;
				d[i][j] = 1;
			}
			else if (y <= x && y <= z) {
				c[i][j] = y;
				d[i][j] = 2;
			}
			else if (z <= x && z <= y)
			{
				c[i][j] = z;
				if (A[i] == B[j]) d[i][j] = 0;
				else d[i][j] = 3;	/* ��ü �� */
			}
		}
	}
}

void print_result(int i, int j)
{
	if (i == 0 && j == 0) return;
	else if (i == 0 && j != 0)
	{
		print_result(i, j - 1);
		printf("A���ڿ��� %d��° ��ġ�� ����%c�� ����\n", i, B[j]);
	}
	else if (i != 0 && j == 0)
	{
		print_result(i - 1, j);
		printf("A���ڿ��� %d��° ����%c�� ����\n", i, A[i]);
	}
	else if (d[i][j] == 0) print_result(i - 1, j - 1);
	else if (d[i][j] == 1)
	{
		print_result(i - 1, j);
		printf("A���ڿ��� %d��° ����%c�� ����\n", i, A[i]);
	}
	else if (d[i][j] == 2)
	{
		print_result(i, j - 1);
		printf("A���ڿ��� %d��° ��ġ�� ����%c�� ����\n", i, B[j]);
	}
	else {
		print_result(i - 1, j - 1);
		printf("A���ڿ��� %d��° ����%c�� %c�� ��ü\n", i, A[i], B[j]);
	}
}

int main()
{
	min_edit();
	print_result(5,4);
	return 0;
}
