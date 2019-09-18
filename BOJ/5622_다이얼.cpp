#include <iostream>

using namespace std;

int main() {
	char arr[20];
	int a = 0;
	int i;
	cin >> arr;

	for (i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 65 && arr[i] <= 67)
			a += 3;
		else if (arr[i] >= 68 && arr[i] <= 70)
			a += 4;
		else if (arr[i] >= 71 && arr[i] <= 73)
			a += 5;
		else if (arr[i] >= 74 && arr[i] <= 76)
			a += 6;
		else if (arr[i] >= 77 && arr[i] <= 79)
			a += 7;
		else if (arr[i] >= 80 && arr[i] <= 83)
			a += 8;
		else if (arr[i] >= 84 && arr[i] <= 86)
			a += 9;
		else if (arr[i] >= 87 && arr[i] <= 90)
			a += 10;
		else if (arr[i] == 0)
			a += 11;
		else if (arr[i] == 1)
			a += 2;
	}

	cout << a << endl;

	return 0;
}