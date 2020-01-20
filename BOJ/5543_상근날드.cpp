#include<iostream>

using namespace std;

const int INF = 1000000007;

int main() {
	int temp, cheap = INF, ret = 0;

	for (int i = 0; i < 3; i++) {
		cin >> temp;
		if (cheap > temp)
			cheap = temp;
	}

	ret = cheap;
	cheap = INF;
	for (int i = 0; i < 2; i++) {
		cin >> temp;
		if (cheap > temp)
			cheap = temp;
	}

	cout << ret + cheap - 50 << endl;

	return 0;
}