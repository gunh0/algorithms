/*
������ȯ������ �������α׷��� ������� �����Ͽ� �ذ��غ���.
�Ž������� �ݾ��� 1~15������ ��ȭ��Ű�鼭 ���������� 1���� �ִ°Ϳ��� ������
1��, 5���� ���� ��, 1��, 5��, 12�� ���� �� ������ ���������� �ϳ��� ������Ű�鼭
�ظ� ã�ư���.
*/
#include <stdio.h>

int main() {
	int set[4] = { 1,5,12,50 };
	int count[16];
	int coin[16];
	int charge, i, j;

	charge = 15;
	j = 0;

	/* ���� �������� ������������ ���ĵǾ� �ִٴ� ���� �����Ͽ�
	���� ���� ���������� �Ž��� �ݾ׺��� ũ�� �Ұ����ϴ�.*/
	if (set[j] > charge) {
		printf("impossible");
		return 0;
	}

	// ���� ���� ���� ������ �̿��� �ʱ�ȭ
	for (i = 0; i < set[j]; i++)
	{
		count[i] = 0;
		coin[i] = -1;
	}

	count[set[j]] = 1;
	coin[set[j]] = j;
	for (i = set[j] + 1; i <= charge; i++)
	{
		if (coin[i - set[j]] == -1)	// �Ұ���
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