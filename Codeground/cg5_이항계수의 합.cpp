/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#define divisor (unsigned long long)1000000007

using namespace std;

typedef unsigned long long ull;

int Answer;

ull fact[2000003];

void factorial(ull k)
{
	for (int i = 0; i <= k; i++) {
		if(i)
			fact[i] = (i * fact[i - 1]) % divisor;
		else
			fact[i] = 1;
	}
}

ull mod(ull x, ull k) {
	if (k == 1) 
		return x;
	ull t = mod(x, k / 2);
	ull result = t;
	result = (result * t) % divisor;
	if (k % 2 == 1) result = (result * x) % divisor;
	return result;
}

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
	factorial(2000002);
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

		int n, m;
		ull val;
		cin >> n >> m;
		val = mod((fact[n + 1] * fact[m + 1]) % divisor, divisor - 2);
		Answer = ((fact[n + m + 2] * val) % divisor) - 1;

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;	//Your program should return 0 on normal termination.
}