#include <iostream>
#include <vector>

using namespace std;

int n;
long long int m;
vector<vector<int>> in;

void input()
{
	int num;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			cin >> num;
			v.push_back(num);
		}
		in.push_back(v);
	}
}

vector<vector<int>> multipleMatrix(vector<vector<int>>& first, vector<vector<int>>& second)
{
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ans[i][j] += first[i][k] * second[k][j];
			}
			ans[i][j] %= 1000;
		}
	}
	return ans;
}

vector<vector<int>> powMatrix(vector<vector<int>>& matrix, long long int b)
{
	vector<vector<int>> ans(n, vector<int>(n));
	vector<vector<int>> arr = matrix;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)    ans[i][j] = 1;
			else            ans[i][j] = 0;
		}
	}

	while (b > 0) {
		if (b % 2)
			ans = multipleMatrix(ans, arr);
		arr = multipleMatrix(arr, arr);
		b /= 2;
	}
	return ans;
}

void print(vector<vector<int>> v)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	input();
	print(powMatrix(in, m));
	return 0;
}