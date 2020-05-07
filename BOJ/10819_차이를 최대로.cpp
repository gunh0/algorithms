#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, max = -900;
	vector<int>nums;

	cin >> n;
	nums.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &nums[i]);

	// 오름차순 정렬
	sort(nums.begin(), nums.end());

	// 모든 경우의 수 탐색
	do {
		int tmp = 0;

		for (int i = 0; i < n - 1; i++) {
			int add = nums[i] - nums[i + 1];
			if (add < 0) add = add * -1;
			tmp += add;
		}
		if (max < tmp)
			max = tmp;

	} while (next_permutation(nums.begin(), nums.end()));

	printf("%d\n", max);

	return 0;
}