/* 두개의 문자열 A, B가 다음과 같이 주어졌을 때
A와 B의 공통의 부분 문자열 중 가장 긴 것을 구하시오.

A=abcbdab
B=bdcaba
*/

#include <stdio.h>
char A[8] = { ' ', 'a', 'b', 'c', 'b', 'd', 'a', 'b' };	/* 문자열 A */
char B[7] = { ' ', 'b', 'd', 'c', 'a', 'b', 'a' };	/* 문자열 B */

int c[7][8];	/* 최대 문자열의 길이 */
int d[7][8];	/* 최대 문자열이 되도록하는 문자의 방향 */

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
				d[i][j] = 0;	// 대각선
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				d[i][j] = 1;	// 왼쪽, 즉 A문자열에는 없는 문자가 B문자열에 있을때
				// 그 문자를 제외시키고 B문자열에서 위치를 하나 당긴다.
			}
			else
			{
				c[i][j] = c[i][j - 1];
				d[i][j] = 2;	// 위쪽, 즉 B문자열에는 없는 문자가 A문자열에 있을때
				// 그 문자를 제외시키고 A문자열의 위치를 하나 당긴다.
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