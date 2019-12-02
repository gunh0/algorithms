#include <stdio.h>
int n = 4;
int cnt = 0;

void hanoi(int start, int dest, int n) {
	int help;
	if (n == 1) {
		cnt += 1;
		printf("��ũ %d��(��) %d���� %d(��)�� �ű��.\n", n, start, dest);
	}
	else {
		help = 6 - start - dest;
		hanoi(start, help, n - 1);
		cnt += 1;
		printf("��ũ %d��(��) %d���� %d(��)�� �ű��.\n", n, start, dest);
		hanoi(help, dest, n - 1);
	}
}

int main()
{
	hanoi(1, 3, n);
	printf("\n��ũ�� �ּ� �̵� Ƚ���� %d�̴�.", cnt);
}