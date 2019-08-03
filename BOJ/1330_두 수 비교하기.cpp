#include <iostream>

using namespace std;

int main()
{
	int input1 = 0, input2 = 0;

	cin >> input1 >> input2;

	if (input1 > input2)
		cout << ">" << endl;
	else if (input1 < input2)
		cout << "<" << endl;
	else
		cout << "==" << endl;

	return 0;
}