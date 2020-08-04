#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long d[100000];
long long dist[100000];
long long price[100000];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &dist[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}
	d[0] = price[0] * dist[0];
	long long min = price[0];
	for (int i = 1; i < n; i++) {
		if (price[i] < min) {
			min = price[i];
		}
		d[i] = d[i - 1] + min * dist[i];
	}
	printf("%ld\n", d[n - 1]);
}