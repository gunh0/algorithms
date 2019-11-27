/*
�� ���ڰ� � ���� �������� �̷�����°��� �˾ƺ����� �Ѵ�.
���� ��� ���� 10�� 3�� ���� �������� �̷�������� �ϴ� ������ ������ ��� ����ϴµ�
�� �������� ��� �޶�� �Ѵ�. �� ������ ����
1+2+7=10
1+3+6=10
1+4+5=10
2+3+5=10
����ϴ� �ڵ带 �����Ͻÿ�.
*/

#include <stdio.h>

int s = 10;
int n = 3;
int k[3 + 1];

void sum_of_permutation(int i, int bound) {
	int j;
	if (i == n - 1)
	{
		k[n] = bound;
		for (j = 1; j < n; j++)
			printf("%d+", k[j]);
		printf("%d=%d\n", k[j], s);
	}
	else {
		i++;
		for (j = k[i - 1] + 1; j < s; j++) {
			k[i] = j;
			bound = promising(i);
			if (bound == 0 || k[i] >= bound) break;
			sum_of_permutation(i, bound);
		}
	}
}

int promising(int i) {
	int j;
	int sum = 0;

	for (j = 1; j <= i; j++)
		sum += k[j];
	if (sum >= s) return 0;
	else return s - sum;
}

int main()
{
	k[0] = 0;
	sum_of_permutation(0, s);
	return 0;
}