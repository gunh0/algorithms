#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int total_minutes = A * 60 + B + C;
    int hour = (total_minutes / 60) % 24;
    int minute = total_minutes % 60;

    cout << hour << " " << minute << endl;
    return 0;
}