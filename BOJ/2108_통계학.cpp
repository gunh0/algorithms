#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, temp, mean = 0, mode = 0, min, max = 0;
	bool isSecond = false;
	cin >> N;
	vector<int> vec(N);
	vector<int> vec2(8001, 0);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		mean += vec[i];
		temp = (vec[i] <= 0) ? abs(vec[i]) : vec[i] + 4000;
		vec2[temp]++;
		if (vec2[temp] > max)
			max = vec2[temp];
	}
	sort(vec.begin(), vec.end());

	for (int i = -4000; i < 4001; i++) {
		temp = i <= 0 ? abs(i) : i + 4000;
		if (vec2[temp] == max) {
			mode = i;
			if (isSecond)
				break;
			isSecond = true;
		}
	}

	cout << round(mean / (double)N) << '\n';
	cout << vec[round(N / 2)] << '\n';
	cout << mode << '\n';
	min = vec[0];
	max = vec[vec.size() - 1];
	cout << max - min << '\n';
}