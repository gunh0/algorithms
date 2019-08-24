#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main() {
	int t, n;
	char a[21];
	
	cin >> t;

	for (int i = 0; i < t; i++) {
		scanf("%d %s", &n, a);
		for (int x = 0; a[x] != '\0'; x++)
		{
			for (int y = 0; y < n; y++)
				cout << a[x];
		}
		printf("\n");
	}
}