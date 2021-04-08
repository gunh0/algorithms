#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, num, cnt = 0;
	vector<int> deque;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		deque.push_back(i);

	while (M--)
	{
		cin >> num;

		int front = 0, back = 0;
		// Find which direction (front or back) the target is closer from
		for (int i = 0; i < N; i++)
		{
			if (deque[i] == num)
			{
				front = 1;
				break;
			}
			else if (deque[N - 1 - i] == num)
			{
				back = 1;
				break;
			}
		}

		// Perform operation based on which direction is closer
		if (front)
		{
			while (1)
			{
				int front_num = deque.front();
				deque.erase(deque.begin());

				if (front_num == num)
					break;
				deque.push_back(front_num);
				cnt++;
			}
		}
		else
		{
			cnt++;
			while (1)
			{
				int back_num = deque.back();
				deque.pop_back();

				if (back_num == num)
					break;
				deque.insert(deque.begin(), back_num);
				cnt++;
			}
		}

		N--;
	}

	printf("%d\n", cnt);

	return 0;
}