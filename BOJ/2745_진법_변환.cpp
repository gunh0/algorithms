#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string N;
    int B;
    cin >> N >> B;

    long long result = 0;
    for (char c : N)
    {
        int value;
        if (isdigit(c))
            value = c - '0';
        else
            value = c - 'A' + 10;
        result = result * B + value;
    }
    cout << result << '\n';
    return 0;
}