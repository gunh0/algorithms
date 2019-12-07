/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

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

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

		int n = 0;
		vector<int> vec;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int input;
			cin >> input;
			vec.push_back(input);
		}

		sort(vec.begin(), vec.end());

		int maxval = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] + n - i >= maxval)
				maxval = vec[i] + n - i;
		}

		int cnt = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] + n < maxval)
				cnt++;
			else
			{
				Answer = n - cnt;
				break;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;	//Your program should return 0 on normal termination.
}