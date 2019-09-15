#include <iostream>

using namespace std;

char map[3000][3000];	// 3^7==2187 �̴�.

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
	if (n == 1)	// n�� 1�̸� ���� ��ġ (map[x][y]�� *�� ä��
	{
		map[x][y] = '*';
		return;
	}
	
	/* �߰� ���� Ȯ��
	for (int i = 0; i < n; ++i) {	// �� ���
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	*/

	int div = n / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {	// (0,1,2) (0,1,2)�� �������� 1�� �߰� ��ġ�̹Ƿ�
				continue;	// i�� 1�̰� j�� 1�̸� �������� ó��
			}
			solve(div, x + (div * i), y + (div * j));  // 3���� ����� ������ �ذ�
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

	for (int i = 0; i < n; ++i) {	// �� ���
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}