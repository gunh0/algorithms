#include <iostream>
using namespace std;

int main() {
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) { break; }
        if (b * b + c * c == a * a || a * a + c * c == b * b || b * b + a * a == c * c)
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}