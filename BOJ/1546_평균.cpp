#include <iostream>

using namespace std;

int main()
{
	int input = 0, max = 0;
	double result = 0;
	cin >> input;
	double* arr = new double[input];
	for (int i = 0; i < input; i++)
	{
		cin >> arr[i];
		if (arr[i]>max) max = arr[i];
	}
	for (int j = 0; j < input; j++)
	{
		result = result + ((arr[j] / max) * 100);
	}
	delete[] arr;
	arr = NULL;

	cout << result / input << endl;
	return 0;
}