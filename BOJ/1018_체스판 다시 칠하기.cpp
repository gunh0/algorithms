#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 50;

int M, N;

string board[MAX];

//(0, 0)�� W�� ü������
string whiteFirst[8] = {
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};

//(0, 0)�� B�� ü������
string blackFirst[8] = {
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

//(0, 0)�� W�� ü������ ���� �ٲ� ĭ ��
int whiteFirstChange(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != whiteFirst[i - y][j - x])
				cnt++;

	return cnt;
}

//(0, 0)�� B�� ü������ ���� �ٲ� ĭ ��
int blackFirstChange(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
		for (int j = x; j < x + 8; j++)
			if (board[i][j] != blackFirst[i - y][j - x])
				cnt++;
	return cnt;
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	int result = INF;

	for (int i = 0; i + 7 < N; i++)
		for (int j = 0; j + 7 < M; j++)
			result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));

	cout << result << endl;
	return 0;
}

