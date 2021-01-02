#include <iostream>
using namespace std;

const int MAXN = 100;

int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];

int main()
{
    int N, M;
    cin >> N >> M;

    // 행렬 A 입력 받기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    // 행렬 B 입력 받기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> B[i][j];
        }
    }

    // 행렬 A와 B를 더해서 C 행렬 만들기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // C 행렬 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
