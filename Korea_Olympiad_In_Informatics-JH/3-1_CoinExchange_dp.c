/*
동전교환문제를 동적프로그래밍 방법론을 적용하여 해결해보기.
거스름돈의 금액을 1~15원까지 변화시키면서 단위동전이 1원만 있는것에서 시작해
1원, 5원이 있을 때, 1원, 5원, 12원 있을 때 등으로 단위동전을 하나씩 증가시키면서
해를 찾아간다.
*/
#include <stdio.h>

int main() {
	int set[4] = { 1,5,12,50 };
	int count[16];
	int coin[16];
	int charge, i, j;

	charge = 15;
	j = 0;

	/* 단위 동전들이 오름차순으로 정렬되어 있다는 전제 조건하에
	가장 작은 단위동전이 거스름 금액보다 크면 불가능하다.*/
	if (set[j] > charge) {
		printf("impossible");
		return 0;
	}

	// 가장 작은 단위 동전을 이용한 초기화
	for (i = 0; i < set[j]; i++)
	{
		count[i] = 0;
		coin[i] = -1;
	}

	count[set[j]] = 1;
	coin[set[j]] = j;
	for (i = set[j] + 1; i <= charge; i++)
	{
		if (coin[i - set[j]] == -1)	// 불가능
		{
			count[i] = 1;
			coin[i] = -1;
		}
		else {
			count[i] = count[i - set[j]] + 1;
			coin[i] = j;
		}
	}

	for (j = 1; j < 4 && set[j] <= charge; j++)
	{
		count[set[j]] = 1;
		coin[set[j]] = j;
		for (i = set[j] + 1; i <= charge; i++)
		{
			if (coin[i - set[j]] == -1)
			{
				count[i] = 0;
				coin[i] = -1;
			}
			else if (count[i] > count[i - set[j]] + 1)
			{
				count[i] = count[i - set[j]] + 1;
				coin[i] = j;
			}
		}
	}

	i = charge;
	if (coin[i] != -1)
	{
		printf("used coins ar %d\n", count[i]);
		do
		{
			printf("%4d", set[coin[i]]);
			i = i - set[coin[i]];
		} while (i > 0);
	}
	else
		printf("impossible");

	return 0;
}