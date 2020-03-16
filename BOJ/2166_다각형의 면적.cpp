#include <iostream>
#define lld long long int
#define max_int 10001

using namespace std;

int n;
lld result;

struct info {
    lld x, y;
};

info point[max_int], origin;

lld ccw(info r, info p, info q) {
    lld first = (p.x - r.x) * (q.y - r.y);
    lld second = (p.y - r.y) * (q.x - r.x);
    lld result = first - second;

    return result;
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> point[i].x >> point[i].y;
    }

    origin = point[1];

    for (int i = 2; i <= n - 1; i++) {
        lld ccw_result = ccw(origin, point[i], point[i + 1]);
        result += ccw_result;
    }

    if (result < 0) result *= -1;

    printf("%lld.", result / 2);

    if (result % 2 == 0) printf("0\n");
    else printf("5\n");

    return 0;
}