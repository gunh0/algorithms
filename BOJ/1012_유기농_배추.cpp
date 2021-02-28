#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

void Result()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);

		int map[50][50];
		for (int i = 0; i < 50; ++i)
			for (int j = 0; j < 50; ++j)
				map[i][j] = 0;

		for (int i = 0; i < k; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}

		int result = 0;

		while (true)
		{
			bool find = false;
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (map[i][j] == 1)
					{
						find = true;
						map[i][j] = 2;
						result++;
						break;
					}
				}
				if (find == true)
					break;
			}

			if (find == false)
				break;

			bool extend;
			do
			{
				extend = false;
				for (int i = 0; i < m; ++i)
					for (int j = 0; j < n; ++j)
						if (map[i][j] == 2)
						{
							if (i > 0 && map[i - 1][j] == 1)
							{
								map[i - 1][j] = 2;
								extend = true;
							}
							if (i < m - 1 && map[i + 1][j] == 1)
							{
								map[i + 1][j] = 2;
								extend = true;
							}
							if (j > 0 && map[i][j - 1] == 1)
							{
								map[i][j - 1] = 2;
								extend = true;
							}
							if (j < n - 1 && map[i][j + 1] == 1)
							{
								map[i][j + 1] = 2;
								extend = true;
							}
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