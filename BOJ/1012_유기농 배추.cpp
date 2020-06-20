#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

void Result()
{
	// 테스트 케이스를 입력받는다.
	int t;
	scanf("%d", &t);

	while (t--) {
		int m, n, k;	// 가로, 세로, 배추갯수
		scanf("%d %d %d", &m, &n, &k);

		int map[50][50];
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j)
				map[i][j] = 0;

		// 배추위치 입력
		for (int i = 0; i < k; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}

		int result = 0;

		while (true) {
			// 지렁이없는 배추 위치 찾아 떨구기
			bool find = false;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					// 배추 위치
					if (map[i][j] == 1)
					{
						find = true;
						map[i][j] = 2;
						result++;	// 시용한 지렁이 갯수 증가
						break;
					}
				}
				if (find == true)break;
			}

			if (find == false)break;

			// 지렁이의 번식
			bool extend;
			do
			{
				extend = false;
				for (int i = 0; i < m; ++i)
					for (int j = 0; j < n; ++j)
						if (map[i][j] == 2)
						{
							// 지렁이 왼쪽 번식
							if (i > 0 && map[i - 1][j] == 1) { map[i - 1][j] = 2; extend = true; }
							// 지렁이 오른쪽 번식
							if (i < m - 1 && map[i + 1][j] == 1) { map[i + 1][j] = 2; extend = true; }
							// 지렁이 위쪽 번식
							if (j > 0 && map[i][j - 1] == 1) { map[i][j - 1] = 2; extend = true; }
							// 지렁이 아래쪽 번식
							if (j < n - 1 && map[i][j + 1] == 1) { map[i][j + 1] = 2; extend = true; }
						}
			} while (extend == true);
		}
		printf("%d\n", result);
	}
}

int main()
{
	Result();
	return 0;
}