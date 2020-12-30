// 10926 - ??! (https://www.acmicpc.net/problem/10926)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string username;
    cin >> username;

    username += "??!";
    cout << username << endl;

    return 0;
}
