#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int n, A[11];
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = n; i > 0; i--)
		v.insert(v.begin() + A[i], i);	// v.begin()+A[i]¿¡ i°ª insert

	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0)
			printf("%d ", v[i]);
	}

	return 0;
}