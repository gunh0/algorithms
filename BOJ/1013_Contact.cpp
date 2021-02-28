#include <iostream>
#include <string>
using namespace std;

inline bool checkPattern(const string &s)
{
    int n = s.length(), i = 0;

    while (i < n)
    {
        if (s[i] == '0')
        {
            if (i + 1 >= n || s[i + 1] != '1')
                return false;
            i += 2;
        }
        else
        { // s[i] == '1'
            if (i + 2 >= n || s[i + 1] != '0' || s[i + 2] != '0')
                return false;

            i += 3;
            while (i < n && s[i] == '0')
                i++;

            if (i >= n || s[i] != '1')
                return false;

            i++;
            while (i < n && s[i] == '1' && (i + 2 >= n || s[i + 1] != '0' || s[i + 2] != '0'))
                i++;
        }
    }

    return i == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    string s;
    while (T--)
    {
        cin >> s;
        cout << (checkPattern(s) ? "YES\n" : "NO\n");
    }

    return 0;
}