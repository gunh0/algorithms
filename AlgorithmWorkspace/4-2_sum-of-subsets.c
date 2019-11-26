/*
원소 5, 6, 10, 11, 16으로 이루어진 집합 S가 있다.
이때 집합 S의 부분집합 중 그 원소의 합이 21이되는 부분집합을 모두 찾는 코드를 구현하시오.
*/

#include <stdio.h>

int promising(int, int, int);

int set[6] = { 0,16,11,10,6,5 };	// 집합 s
int include[6];	// 각 원소들의 포함 여ㅈ부
int sum;

void sum_of_subset(int i, int subsum, int total) {
	int j, p;
	if (promising(i, subsum, total)) {
		if (subsum == sum) {
			for (j = 0; j <= i; j++)
			{
				if (include[j] == 1)
					printf("%5d", set[j]);
			}
			printf("\n");
		}
		else {
			include[i + 1] = 1;
			sum_of_subset(i + 1, subsum + set[i + 1], total - set[i + 1]);
			include[i + 1] = 0;
			sum_of_subset(i + 1, subsum, total - set[i + 1]);
		}
	}
}

int promising(int i, int subsum, int total)
{
	return (i < 6 && (subsum + total >= sum) && (subsum = sum || subsum + set[i + 1] <= sum));
}

int main()
{
	int i, total;

	sum = 21;
	total = 0;

	for (i = 0; i < 6; i++)
	{
		total += set[i];
		include[i] = 1;
	}
	sum_of_subset(0, 0, total);
}