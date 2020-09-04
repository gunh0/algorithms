#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	// ����� ũ��(������ ����)�� �Է�
	int n;
	cin >> n;

	int** w = new int* [n];
	for (int i = 0; i < n; ++i)
		w[i] = new int[n];

	// ����� ����(���ð��� �̵��Ÿ�)�� �Է�
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
			cin >> w[x][y];
	}

	// �ּҰ��� ���ؾ� �ϹǷ� ������ �ִ�Ÿ��� �ʱⰪ���� ����
	// (������ ���� 10�� ����, ���� �Ÿ� �ִ� 1,000,000 = �ִ� �Ÿ� �� 10 x 1,000,000)
	int result = 10000001;

	// �ּҰ��� ���ϱ� ���� �ӽ� ���庯��
	int pres = 0;

	// ��(column) ��ȣ ���� ���Ϳ� ����
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		v[i] = i;

	do
	{
		for (int i = 0; i < n; i++)
		{
			// ������ ��(column)�� ���� ������ ��(row)�� �ȴ�.
			int j = i + 1;

			// ������ �������� ������ ��, ������ ������ ��(row)�� ó�� ���÷� ���ư���.
			if (i + 1 >= n)
				j = 0;

			// ���±��� ������ ������� �ʰ� pres�� �ִ밪�� ���� (�Ÿ������ ���� �ʵ��� ��)
			if (w[v[i]][v[j]] == 0)
				pres = 10000001;

			// ���� ���Ұ��� ���ؼ� �� �Ÿ� ���� ���
			pres = pres + w[v[i]][v[j]];

		}

		// �ʱⰪ(10000001)���� ������ result�� 
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
