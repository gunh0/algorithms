/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

int Answer;

int scoreboard[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };
int A, B, C, D, E, N;

int score(double angle) {
	int a = (int)(angle / 18.0);
	return scoreboard[a];
}

int reward(double r) {
	if (r > A&& r < B)
		return 1;
	else if (r > B&& r < C)
		return 3;
	else if (r > C&& r < D)
		return 1;
	else if (r > D&& r < E)
		return 2;
	else return 0;
}

int compute_score(double r, double angle) {
	if (r < A)
		return 50;
	return score(angle) * reward(r);
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
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		double x, y, angle, r;

		cin >> A >> B >> C >> D >> E;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%lf", &x);
			scanf("%lf", &y);

			r = sqrt((x * x) + (y * y));
			angle = atan2(y, x);
			angle = angle * (double)180 / 3.141592653 + 9;
			if (angle < 0)	angle += 360;
			Answer += compute_score(r, angle);
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}