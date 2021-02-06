// 15953번 상금 헌터
#include <iostream>

using namespace std;

int main()
{
	int t, a, b, ans;
	int reward_2017[] = {0, 500, 300, 200, 50, 30, 10};
	int reward_2018[] = {0, 512, 256, 128, 64, 32};
	int people_2017[] = {0, 1, 3, 6, 10, 15, 21};
	int people_2018[] = {0, 1, 3, 7, 15, 31};

	cin >> t;

	while (t--)
	{
		ans = 0; // 상금 금액 초기화
		cin >> a >> b;

		for (int i = 0; i < 6; i++)
		{
			if (people_2017[i] < a && a <= people_2017[i + 1])
			{
				ans += reward_2017[i + 1];
				break;
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (people_2018[i] < b && b <= people_2018[i + 1])
			{
				ans += reward_2018[i + 1];
				break;
			}
		}

		cout << ans * 10000 << endl; // '원' 단위의 예상 상금 출력
	}

	return 0;
}