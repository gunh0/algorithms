#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main() {
    double R, S1, S2;
    std::cin >> R;
    S1 = M_PI * R * R;
    S2 = R * R * 2;

    printf("%.6f\n", S1);
    printf("%.6f\n", S2);
    return 0;
}