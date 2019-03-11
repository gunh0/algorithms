#include <iostream>

using namespace std;

int main(){
	int A = 0, B = 0, C = 0;
	int mid = 0;
	cin >> A >> B >> C;

	if (A >= B && A >= C)
	{
		if (B >= C) mid = B;
		else mid = C;
	}
	else if (B >= A && B >= C)
	{
		if (A >= C) mid = A;
		else mid = C;
	}
	else
	{
		if (A >= B) mid = A;
		else mid = B;
	}

	cout << mid << endl;
	return 0;
}
	

