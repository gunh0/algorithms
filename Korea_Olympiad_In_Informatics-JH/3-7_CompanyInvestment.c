/*
어떤 투자가가 여러 기업들에게 돈을 투자해서 최대의 이익을 얻고자 한다.
단, 투자는 만원단위로 할 수 있으며 각 기업은 많이 투자할수록 많은 이익을 투자가에게 돌려준다.
돈을 투자하지 않은 경우는 당연히 얻게되는 이익도 없다.
*/

#include <stdio.h>
#define COM 20	// 최대 20개의 기업
#define MAX_INVEST 300	// 최대 300만원까지 투자 가능

int dynamic[COM][MAX_INVEST];
int invest[COM][MAX_INVEST];	// COM번째 회사에 투자한 금액

int c = 2;	// 2개 회사
int m = 4;	// 4만원

int main()
{
	int in[MAX_INVEST][COM] = { {0,0,0},{0,5,1},{0,6,5},{0,7,9},{0,8,15} };
	int i, j, k;

	for (i = 0; i <= c; i++)
		dynamic[0][i] = 0;
	for (i = 0; i <= m; i++)
		dynamic[i][0] = 0;

	for (i = 1; i <= c; i++)	// i는 현재 기업 번호
	{
		for (j = 1; j <= m; j++)	// j는 현재 기업에 투자한 금액
		{
			for (k = 0; k <= j;  k++)	// 현재 이전의 기업까지 투자한 금액
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