#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int prize = 0;

    // All three dice are the same
    if (a == b && b == c)
    {
        prize = 10000 + a * 1000;
    }
    // Two dice are the same
    else if (a == b || a == c)
    {
        prize = 1000 + a * 100;
    }
    else if (b == c)
    {
        prize = 1000 + b * 100;
    }
    // All dice are different
    else
    {
        int maxVal = max({a, b, c});
        prize = maxVal * 100;
    }

    cout << prize << endl;

    return 0;
}
