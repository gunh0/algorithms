#include<algorithm>
#include<iostream>
using namespace std;

int n, m, num[8], result[8];

// 입력받은 n개의 수들 중에서 골랐던 수열과 똑같은 수열을
// 고르지 않게 m개를 고르고 출력해주는 함수
void getResult(int count, int start) {

	// m개를 골랐다면 출력합니다
	if (count == m) {
		for (int i = 0; i < m; i++)
			cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	int prev_num = -1;  // 바로 직전에 골랐던 수를 저장하는 변수

	// start부터 n-1까지의 인덱스 중 m개를 선택
	for (int i = start; i < n; i++) {

		// 중복되는 수열을 출력하지 않기위해 바로 직전에
		// 골랐던 수를 고르지 않고, 비내림차순으로 출력하기 위해
		// 항상 골랐던 수보다 크거나 같은 수를 고르게끔 i를 인자로 넘겨줌
		if (prev_num != num[i]) {
			result[count] = num[i];
			prev_num = num[i];
			getResult(count + 1, i);
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	// 수열은 사전 순으로 출력해야 하므로
	// 입력을 받고 오름차순으로 정렬
	sort(num, num + n);

	getResult(0, 0);
	return 0;
}
