#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N <= 100000 && N % 2024 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}