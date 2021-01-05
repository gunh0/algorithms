#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const double EPSILON = 1e-9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int maxY, minY, n, m;
    cin >> maxY >> minY >> n;

    // 각 선분을 나타내는 구조체
    struct Line
    {
        int num;
        double x1, x2, y;
        Line(int num, double x1, double x2, double y) : num(num), x1(x1), x2(x2), y(y) {}
        // 선분을 y 좌표에 대해 오름차순으로 정렬하기 위한 비교 함수
        bool operator<(const Line &rhs) const
        {
            return y < rhs.y;
        }
    };

    vector<Line> lines;
    for (int i = 1; i <= n; i++)
    {
        double x1, x2;
        cin >> x1 >> x2;
        lines.emplace_back(i, x1, x2, maxY - (maxY - minY) * x1 / (x1 - x2));
    }

    // 선분을 y 좌표에 대해 오름차순으로 정렬
    sort(lines.begin(), lines.end());

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        double queryY;
        cin >> queryY;
        double leftmost = -1;
        int ans = -1;
        for (const auto &line : lines)
        {
            // y 좌표가 현재 쿼리 y 좌표보다 높은 경우, 더 이상 체크할 필요 없음
            if (line.y > queryY + EPSILON)
            {
                break;
            }
            // y 좌표가 현재 쿼리 y 좌표와 거의 같은 경우 (EPSILON 이하), 왼쪽 끝점의 x 좌표가 가장 작은 선분 선택
            if (abs(line.y - queryY) < EPSILON && (leftmost == -1 || line.x1 < leftmost))
            {
                leftmost = line.x1;
                ans = line.num;
            }
            // y 좌표와 현재 쿼리 y 좌표 사이에 있는 경우, 교차 여부 판단
            if (line.y < queryY + EPSILON && line.y > queryY - EPSILON)
            {
                double x = line.x1 + (line.x2 - line.x1) * (queryY - line.y) / (line.y - minY);
                if (x >= leftmost + EPSILON && x <= line.x1 + EPSILON)
                {
                    leftmost = x;
                    ans = line.num;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
