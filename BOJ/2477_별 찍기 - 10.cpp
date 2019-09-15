#include <iostream>

using namespace std;

char map[3000][3000];	// 3^7==2187 이다.

void init(int n)	// Initialize Map
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			map[i][j] = ' ';
		}
	}
}

void solve(int n, int x, int y)
{
	if (n == 1)	// n이 1이면 현재 위치 (map[x][y]를 *로 채움
	{
		map[x][y] = '*';
		return;
	}
	
	/* 중간 과정 확인
	for (int i = 0; i < n; ++i) {	// 맵 출력
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	*/

	int div = n / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {	// (0,1,2) (0,1,2)로 보았을때 1은 중간 위치이므로
				continue;	// i가 1이고 j가 1이면 공백으로 처리
			}
			solve(div, x + (div * i), y + (div * j));  // 3으로 나누어서 문제를 해결
		}
	}
	return;
}

int main(int argc, char* argv[])
{
	int n;
	cin >> n;

	init(n);
	solve(n, 0, 0);

	for (int i = 0; i < n; ++i) {	// 맵 출력
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}