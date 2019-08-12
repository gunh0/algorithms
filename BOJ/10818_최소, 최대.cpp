#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
	int n = 0;
	int max = -1000001, min = 1000001;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	// 모든 입력값을 지우기

	string input, temp;
	getline(cin, input);

	vector<string> tempResult;
	stringstream st(input);
	while (getline(st, temp, ' ')) {
		tempResult.push_back(temp);
	}

	vector<int> result;
	for (int i = 0; i < tempResult.size(); i++)
	{
		result.push_back(atoi(tempResult[i].c_str()));
		if (result[i] > max) max = result[i];
		if (result[i] < min) min = result[i];
	}
	
	cout << min << " " << max << endl;

	return 0;
}