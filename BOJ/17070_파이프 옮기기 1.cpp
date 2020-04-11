#include <iostream>
using namespace std;

const int MAX = 16;

typedef struct
{
	int y, x;
}Dir;

// ����, ����, �밢��
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
			// ���� -> ����, ���� -> ���� �Ұ���
			continue;
		}

		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		if (nextY >= N || nextX >= N || arr[nextY][nextX] == 1)
		{
			// ������ ����ų�, ���� ���
			continue;
		}

		if (i == 2 && (arr[y][x + 1] == 1 || arr[y + 1][x] == 1))
		{
			// �밢���� ���, Ȯ���ؾ��� ��
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

	// ���� ó�� �������� ������ ������ ������
	func(0, 1, 0);

	cout << result << "\n";
	return 0;
}