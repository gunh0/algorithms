#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long result = 1; // 결과를 저장할 변수, long long으로 선언하여 큰 수에 대비

    for (int i = 2; i <= N; ++i) {
        result *= i;
    }

    cout << result << endl;

    return 0;
}
