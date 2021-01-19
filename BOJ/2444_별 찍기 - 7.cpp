#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= 2 * N - 1; i++)
    {
        int starCount = i <= N ? 2 * i - 1 : 2 * (2 * N - i) - 1;
        int spaceCount = (2 * N - starCount) / 2;

        for (int j = 0; j < spaceCount; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < starCount; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
