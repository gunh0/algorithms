#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    int a_cnt = A - N < 0 ? a_cnt = A : a_cnt = N;
    int b_cnt = B - N < 0 ? b_cnt = B : b_cnt = N;
    int c_cnt = C - N < 0 ? c_cnt = C : c_cnt = N;

    cout << a_cnt + b_cnt + c_cnt << endl;

    return 0;
}
