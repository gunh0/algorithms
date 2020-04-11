#include <iostream>
using namespace std;

const int MAX = 16;

typedef struct
{
	int y, x;
}Dir;

// 가로, 세로, 대각선
Dir moveDir[3] = { {0, 1}, {1, 0}, {1, 1} };

int N;
int result;
int arr[MAX][MAX];

void func(int y, int x, int pipe)
{
	if (y == N - 1 && x == N - 1)
	{
		result++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0))
		{
			// 가로 -> 세로, 세로 -> 가로 불가능
			continue;
		}

		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		if (nextY >= N || nextX >= N || arr[nextY][nextX] == 1)
		{
			// 범위를 벗어나거나, 벽일 경우
			continue;
		}

		if (i == 2 && (arr[y][x + 1] == 1 || arr[y + 1][x] == 1))
		{
			// 대각선인 경우, 확인해야할 벽
			continue;
		}

		func(nextY, nextX, i);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	// 가장 처음 파이프는 방향이 가로인 파이프
	func(0, 1, 0);

	cout << result << "\n";
	return 0;
}