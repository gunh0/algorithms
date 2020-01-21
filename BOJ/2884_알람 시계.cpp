#include <iostream>
using namespace std;

int H, M;

void Earlier()
{
	int hour, minute;
	if (M < 45) {
		minute = (60 + M - 45) % 60;
		hour = H - 1;
		// hour 이 0일 경우에서 1시간 빼는경우 23으로 가야한다.
		if (hour < 0)
			hour = 23;
	}
	else
	{
		minute = M - 45;
		hour = H;
	}
	cout << hour << " " << minute << endl;
}

int main()
{
	cin >> H >> M;
	Earlier();
	return 0;
}