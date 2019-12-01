/*
1�� �̻��� ���Ҹ� ���� ������ ������ ����ϱ�.

���� ��� ���� {a, b, c}�� �ִٸ� ��µǴ� ��� ������ ������ ����.
abc, acb, bac, bca, cba, cab
�̴� ������ ���� ������� ������ �� �ִ�.
a�� ����ϰ� �׵ڿ� {b, c}�� ������ ��� �����Ѵ�.
b�� ����ϰ� �׵ڿ� {a, c}�� ������ ��� �����Ѵ�.
c�� ����ϰ� �׵ڿ� {b, c}�� ������ ��� �����Ѵ�.
�� ���� n���� ���� ������ ����(n-1)���� ���� ������ �̿��Ͽ� ��ȯ������ ������ �� �ִ�.
*/

#include <stdio.h>

char set[3] = { 'a','b','c' };
int n = 3;

void makeperm(int k) {
	int i;
	char temp;

	if (k == n) {
		for (i = 0; i < n; i++)
			printf("%c", set[i]);
		printf("\n");
	}
	else {
		for (i = k; i < n; i++) {
			temp = set[i];
			set[i] = set[k];
			set[k] = temp;

			makeperm(k + 1);

			temp = set[i];
			set[i] = set[k];
			set[k] = temp;
		}
	}
}

int main()
{
	makeperm(0);
}