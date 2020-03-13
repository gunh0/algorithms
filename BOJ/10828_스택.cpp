#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int stack[10000];

int main() {
	int N, i, j, num, top = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		char cmd[BUFSIZ];
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			scanf("%d", &num);
			stack[top] = num;
			top++;
		}

		if (strcmp(cmd, "pop") == 0) {
			if (top <= 0)
				printf("-1\n");
			else {
				printf("%d\n", stack[top - 1]);
				top--;
			}
		}

		if (strcmp(cmd, "size") == 0) {
			printf("%d\n", top);
		}

		if (strcmp(cmd, "empty") == 0) {
			if (top <= 0)
				printf("1\n");
			else
				printf("0\n");
		}

		if (strcmp(cmd, "top") == 0) {
			if (top <= 0)
				printf("-1\n");
			else
				printf("%d\n", stack[top - 1]);
		}
	}

	return 0;
}