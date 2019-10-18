/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int Answer;
int arr[1000001] = { 0, 0, 1, 0, };

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	/*
	vector<int> arr;
	arr.push_back(0);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(0);
	for (int i = 4; i < 1000000; i+=2)
	{
		if (i % 2 == 0)
		{
			arr.push_back(arr[i / 2] + 1);
			arr[i - 1] = arr[i] + 1;
			arr.push_back(0);
		}
	}
	*/
	
	for (int i = 4; i < 1000001; i += 2)
	{
		arr[i] = arr[i / 2] + 1;
		arr[i - 1] = arr[i] + 1;
	}

	/*
	for (int i = 0; i < 1000; i++)
	{
		cout << arr[i] << endl;
	}
	*/

	//cout << "end" << endl;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, m;
		cin >> n >> m;
		for (int i = n; i <= m; i++)
		{
			Answer += arr[i];

		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		printf("Case #%d\n%d\n", test_case + 1, Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}