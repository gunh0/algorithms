#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<unsigned long long> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);

	int n;
	cin >> n;
	if (n >= 3) {
		for (int i = 3; i <= n; i++)
			vec.push_back(vec[i - 2] + vec[i - 1]);
	}
	cout << vec[n] << endl;
	return 0;
}