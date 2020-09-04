#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	// 행렬의 크기(도시의 개수)를 입력
	int n;
	cin >> n;

	int** w = new int* [n];
	for (int i = 0; i < n; ++i)
		w[i] = new int[n];

	// 행렬의 원소(도시간의 이동거리)를 입력
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
			cin >> w[x][y];
	}

	// 최소값을 구해야 하므로 가능한 최대거리를 초기값으로 설정
	// (도시의 개수 10개 이하, 도시 거리 최대 1,000,000 = 최대 거리 수 10 x 1,000,000)
	int result = 10000001;

	// 최소값을 구하기 위한 임시 저장변수
	int pres = 0;

	// 행(column) 번호 값을 벡터에 대입
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		v[i] = i;

	do
	{
		for (int i = 0; i < n; i++)
		{
			// 원소의 행(column)은 다음 원소의 열(row)이 된다.
			int j = i + 1;

			// 도시의 개수보다 많아질 때, 마지막 원소의 열(row)은 처음 도시로 돌아간다.
			if (i + 1 >= n)
				j = 0;

			// 가는길이 없으면 계산하지 않고 pres에 최대값을 대입 (거리계산이 되지 않도록 함)
			if (w[v[i]][v[j]] == 0)
				pres = 10000001;

			// 각각 원소값을 더해서 총 거리 값을 계산
			pres = pres + w[v[i]][v[j]];

		}

		// 초기값(10000001)보다 작으면 result에 
		if (pres < result)
			result = pres;
		pres = 0;

	} while (next_permutation(v.begin(), v.end()));

	cout << result << endl;

	for (int i = 0; i < n; ++i) {
		delete[] w[i];
	}
	delete[] w;

	return 0;
}
