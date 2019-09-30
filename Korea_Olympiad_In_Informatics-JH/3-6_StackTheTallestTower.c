/*
���� ���� ž �ױ�
�ظ��� ���簢���� ������ü �������� ����Ͽ� ž�� �װ��� �Ѵ�.
ž�� ������ �� ���� �Ʒ����� ���� �����鼭 ����� ����.
�Ʒ��� ������ �����ϸ鼭 ���� ���� ž�� ���� �� �ִ� ����� �����Ѵ�.

1) ������ ȸ����ų �� ����. ��, ������ �ظ����� ����� �� ����.
2) �ظ��� ���̰� ���� ������ ������, ���� ���԰� ���� ������ ����.
3) �������� ���̴� ���� ���� �ִ�.
4) ž�� ���� �� �ظ��� ���� ���� ���� �ظ��� ���� ������ ���� �� ����.
4) ���԰� ���ſ� ������ ���԰� ������ ���� ���� ���� �� ����.

�Է��� ù���� �Էµ� ������ ���� �־�����.
�Է����� �־����� ������ ���� �ִ� 100���̴�.
��° �ٺ��ʹ� �� �ٿ� �Ѱ��� ������ ���� ������ ���� �ظ��� ����, ����, ���԰� ���ʴ�� ���� ������ �־�����.

����� ù���� ���� ������ ���� ����Ѵ�.
�� ��° �� ���ʹ� ž�� ���� �� �������� ���� �Ʒ� �������� ���ʷ� ����Ѵ�.
*/

#include <stdio.h>

int number[5] = { 1,2,3,4,5 };	// ���� ��ȣ
int width[5] = { 25,4,9,16,1 };	// ����
int height[5] = { 3,4,2,2,5 };	// ����
int weight[5] = { 4,6,3,5,2 };	// ����
int block[5];	// i��°���� �Ʒ��� ���̴� ���� ��ȣ
int highest[5];	// i��°������ �ְ� ����

void sort()	// ���� ����
{
	int i = 0, j = 0, temp = 0, flag = 1;

	for (i = 4; i > 0 && flag == 1; i--)
	{
		flag = 0;
		for (j = 1; j <= i; j++)
		{
			if (width[j - 1] < width[j])	// ���� ����
			{
				temp = number[j];
				number[j] = number[j - 1];
				number[j - 1] = temp;

				temp = width[j];
				width[j] = width[j - 1];
				width[j - 1] = temp;

				temp = height[j];
				height[j] = height[j - 1];
				height[j - 1] = temp;

				temp = weight[j];
				weight[j] = weight[j - 1];
				weight[j - 1] = temp;

				flag = 1;
			}
		}
	}
}

void dynamic()
{
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		highest[i] = height[i];
		block[i] = -1;	// �Ʒ��� �ƹ��͵� ����.
	}
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (weight[i] < weight[j]) {	// ���԰� ���ſ��� �Ʒ��� ���� �� �ִ�.
				if (highest[i] < highest[j] + height[i]) {
					highest[i] = highest[j] + height[i];
					block[i] = j;
				}
			}
		}
	}
}

void print_result()
{
	int max = 0;
	int num, cnt, i, path[5];

	for (i = 0; i < 5; i++)	// �ְ� ���̸� ã�´�.
	{
		if (max < highest[i]) {
			max = highest[i];
			num = i;
		}
	}
	cnt = 0;
	path[cnt] = number[num];
	cnt++;
	while (block[num] != -1)
	{
		path[cnt] = number[block[num]];
		cnt += 1;
		num = block[num];
	}
	path[cnt] = -1;

	printf("���̴� ������ ���� : %d\n", cnt);
	for (i = 0; path[i] != -1; i++)
		printf("���̴� ������ ���� %d : %d\n", i, path[i]);
}

int main()
{
	sort();
	dynamic();
	print_result();
	return 0;
}
