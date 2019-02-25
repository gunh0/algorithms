#include <stdio.h>

int main() {
	char input[2];
	while (fgets(input, 2, stdin))
		printf("%s", input);
	return 0;
}