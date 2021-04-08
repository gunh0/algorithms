#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int rows = r2 - r1 + 1;
    int cols = c2 - c1 + 1;

    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    int r = 0, c = 0;
    int num = 1;

    // Place starting number at (0, 0)
    if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
    {
        grid[r - r1][c - c1] = num;
    }
    num++;

    // Directions: right, up, left, down (counter-clockwise)
    int dr[] = {0, -1, 0, 1};
    int dc[] = {1, 0, -1, 0};

    // Calculate maximum distance we need to spiral out
    int maxDist = max({abs(r1), abs(r2), abs(c1), abs(c2)}) * 2 + 10;

    int steps = 1;
    int totalSteps = 0;

    // Spiral pattern: right n, up n, left n+1, down n+1, repeat
    while (totalSteps < maxDist * maxDist)
    {
        // Move right 'steps' times
        for (int i = 0; i < steps && totalSteps < maxDist * maxDist; i++)
        {
            c += dc[0];
            r += dr[0];
            if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
            {
                grid[r - r1][c - c1] = num;
            }
            num++;
            totalSteps++;
        }

        // Move up 'steps' times
        for (int i = 0; i < steps && totalSteps < maxDist * maxDist; i++)
        {
            c += dc[1];
            r += dr[1];
            if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
            {
                grid[r - r1][c - c1] = num;
            }
            num++;
            totalSteps++;
        }

        steps++;

        // Move left 'steps' times
        for (int i = 0; i < steps && totalSteps < maxDist * maxDist; i++)
        {
            c += dc[2];
            r += dr[2];
            if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
            {
                grid[r - r1][c - c1] = num;
            }
            num++;
            totalSteps++;
        }

        // Move down 'steps' times
        for (int i = 0; i < steps && totalSteps < maxDist * maxDist; i++)
        {
            c += dc[3];
            r += dr[3];
            if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
            {
                grid[r - r1][c - c1] = num;
            }
            num++;
            totalSteps++;
        }

        steps++;
    }

    // Find maximum value to determine output width
    int maxVal = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maxVal = max(maxVal, grid[i][j]);
        }
    }

    int width = to_string(maxVal).length();

    // Print the grid with proper formatting
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            string numStr = to_string(grid[i][j]);
            int padding = width - numStr.length();
            // Left-pad with spaces
            for (int k = 0; k < padding; k++)
            {
                cout << " ";
            }
            cout << numStr;
            if (j < cols - 1)
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
