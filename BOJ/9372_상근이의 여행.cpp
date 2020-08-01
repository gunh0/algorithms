#include <iostream>  
using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		for (int m_idx = 0; m_idx < M; m_idx++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << "\n";
	}
	return 0;
}