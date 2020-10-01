#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX 1010

int N;
int Arr[MAX];
int DP[MAX];
vector<int> LIS[MAX];
vector<int> Answer;

int Max(int A, int B)
{
    if (A > B)
        return A;
    return B;
}

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> Arr[i];
}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = 1;
        LIS[i].push_back(Arr[i]);
        for (int j = 1; j < i; j++)
        {
            if (Arr[i] > Arr[j])
            {
                if (DP[i] < DP[j] + 1)
                {
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(Arr[i]);
                    DP[i] = DP[j] + 1;
                }
            }
        }
        if (Answer.size() < LIS[i].size())
        {
            Answer = LIS[i];
        }
    }

    cout << Answer.size() << endl;
    for (int i = 0; i < Answer.size(); i++)
        cout << Answer[i] << " ";
    cout << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}