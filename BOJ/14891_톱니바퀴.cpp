#include <iostream>
#include <memory.h>

using namespace std;

bool check[4];
int map[4][8];
int k;

//시계방향 회전
void cw(int* array) {
    int tmp = array[7];
    for (int i = 7; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = tmp;
}

//반시계방향 회전
void ccw(int* array) {
    int tmp = array[0];
    for (int i = 0; i < 7; i++) {
        array[i] = array[i + 1];
    }
    array[7] = tmp;
}

void swit(int* array, int flag) {
    if (flag == 1) {
        cw(array);
    }
    else {
        ccw(array);
    }
}

void solve(int n, int flag) {
    check[n] = true;
    if (n + 1 < 4 && !check[n + 1]) {
        if (map[n][2] != map[n + 1][6]) {
            solve(n + 1, -1 * flag);
        }
    }
    if (n - 1 >= 0 && !check[n - 1]) {
        if (map[n][6] != map[n - 1][2]) {
            solve(n - 1, -1 * flag);
        }
    }
    swit(map[n], flag);
}

int main() {
    char input[9];
    for (int i = 0; i < 4; i++) {
        cin >> input;
        for (int j = 0; j < 8; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        memset(check, 0, sizeof(check));
        solve(x - 1, y);
    }

    int score = 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (map[i][0] == 1) res += score;
        score *= 2;
    }

    printf("%d\n", res);
}
