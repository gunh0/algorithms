#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

bool intersect(int x1, int x2, double y)
{
    if ((x1 <= y && x2 >= y) || (x1 >= y && x2 <= y))
    {
        return true;
    }
    return false;
}

int main()
{
    // 입력 처리
    int maxY, minY;
    cin >> maxY >> minY;

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> segments; // (x좌표, 선분 번호)로 구성된 벡터
    for (int i = 1; i <= n; i++)
    {
        int upperX, lowX;
        cin >> upperX >> lowX;
        segments.push_back(make_pair(make_pair(upperX, lowX), i));
    }

    sort(segments.begin(), segments.end()); // x좌표 기준으로 정렬

    int m;
    cin >> m;

    vector<double> queries;
    for (int i = 0; i < m; i++)
    {
        double y;
        cin >> y;
        queries.push_back(y);
    }

    // 쿼리에 대한 답 구하기
    for (double y : queries)
    {
        int leftmost = numeric_limits<int>::max();
        for (auto segment : segments)
        {
            if (intersect(segment.first.first, segment.first.second, y))
            {
                leftmost = min(leftmost, segment.second);
            }
            if (segment.first.first > y)
            { // y보다 오른쪽에 있는 선분에 대해서는 탐색할 필요가 없음
                break;
            }
        }
        cout << leftmost << '\n';
    }

    return 0;
}
