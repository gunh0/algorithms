#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int i = 0, j = 0, ans = 0;
	int sum = 0;
	int temp = 0;
	int arr[25] = { 0, };
	char str[51];

	cin >> str;

	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if (str[i] == '-') {
			sum += temp;
			arr[j] = sum;
			j++;
			temp = 0;
			sum = 0;
		}
		else if (str[i] == '+') {
			sum += temp;
			temp = 0;
		}
		else {
			temp *= 10;
			temp += (str[i] - '0');
		}
	}

	sum += temp;
	arr[j] = sum;

	ans = arr[0];
	for (i = 1; i < 25; i++) {
		ans -= arr[i];
	}
	printf("%d\n", ans);

	return 0;
}