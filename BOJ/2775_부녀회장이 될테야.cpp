#include <iostream>

using namespace std;

int arr[15][14];

void fillArr() {
	for (int i = 0; i < 14; i++)
		arr[0][i] = i+1;

	for (int i = 1; i <= 14; i++)
		arr[i][0] = 1;
		
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j < 14; j++)
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
	}
}

int main()
{
	int t = 0;
	cin >> t;
	
	fillArr();

	for (int i = 0; i < t; i++) {
		int result = 1;
		
		int k, n;
		cin >> k;
		cin >> n;

		cout << arr[k][n-1] << endl;
	}
	return 0;
}