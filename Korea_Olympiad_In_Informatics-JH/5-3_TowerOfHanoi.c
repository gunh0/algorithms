#include <stdio.h>
int n = 4;
int cnt = 0;

void hanoi(int start, int dest, int n) {
	int help;
	if (n == 1) {
		cnt += 1;
		printf("디스크 %d을(를) %d에서 %d(으)로 옮긴다.\n", n, start, dest);
	}
	else {
		help = 6 - start - dest;
		hanoi(start, help, n - 1);
		cnt += 1;
		printf("디스크 %d을(를) %d에서 %d(으)로 옮긴다.\n", n, start, dest);
		hanoi(help, dest, n - 1);
	}
}

int main()
{
	hanoi(1, 3, n);
	printf("\n디스크의 최소 이동 횟수는 %d이다.", cnt);
}