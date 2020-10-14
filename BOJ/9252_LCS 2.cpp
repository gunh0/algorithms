#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i, j, size1, size2, len;
	string input1, input2;
	vector < vector <int> > dp;
	vector <char> ans;

	cin >> input1 >> input2;
	size1 = input1.size();
	size2 = input2.size();

	dp.resize(size1 + 1);
	dp[0].resize(size2 + 1);

	for (i = 1; i <= size1; i++)
	{
		dp[i].resize(size2 + 1);

		for (j = 1; j <= size2; j++)
		{
			if (input1[i - 1] == input2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
			{
				if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	}

	i = size1;
	j = size2;
	len = dp[i][j];

	printf("%d\n", len);
	ans.resize(len);

	while (len && i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i][j - 1])
			j--;
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		else
		{
			ans[len - 1] = input2[j - 1];
			i--; j--; len--;
		}
	}

	len = ans.size();
	for (i = 0; i < len; i++)
		printf("%c", ans[i]);

	return 0;
}