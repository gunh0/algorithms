#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double rounding(double num, int digit)
{
	return(floor(pow(10, digit) * num + (double)0.5) / pow(10, digit));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase = 0, index = 1;
	double snum = 0, avg = 0, ratio = 0;

	cin >> testcase;

	while (index <= testcase)
	{
		vector<double> score;
		cin >> snum;
		for (int i = 0; i < snum; i++)
		{
			int inputTmp = 0;
			cin >> inputTmp;
			score.push_back(inputTmp);
			avg += score[i];
		}
		avg /= snum;

		for (int j = 0; j < snum; j++)
		{
			if (score[j] > avg)
				ratio += (1 / snum) * 100;
		}
		ratio = rounding(ratio, 3);
		cout << fixed << setprecision(3) << ratio << "%\n";
		ratio = 0;
		avg = 0;
		index++;
	}

	return 0;
}