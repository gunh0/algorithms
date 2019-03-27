#include <iostream>

using namespace std;

int main(void){
	int N = 0;
	int temp1 = 0, temp2 = 0, temp3 = -1;
	int count = 0;

	cin >> N;
	temp1 = N % 10;
	temp2 = (N / 10 + N % 10) % 10;
	while (temp3 != N){
		temp3 = temp1 * 10 + temp2;
		temp1 = temp2;
		temp2 = (temp3 / 10 + temp3 % 10) % 10;
		count++;
	}
	cout << count << endl;
}