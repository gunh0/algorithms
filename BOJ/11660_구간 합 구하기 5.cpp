#include <iostream>
using namespace std;

const int MAX = 1024 + 1;

int pSum[MAX][MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int num;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            //°ãÄ¡´Â pSum[i][j]
            pSum[i + 1][j + 1] = pSum[i + 1][j] + pSum[i][j + 1] - pSum[i][j] + num;
        }
    }

    for (int i = 0; i < M; i++)
    {
        int y, x, y2, x2;
        cin >> y >> x >> y2 >> x2;
        cout << pSum[y2][x2] - pSum[y - 1][x2] - pSum[y2][x - 1] + pSum[y - 1][x - 1] << "\n";
    }

    return 0;
}