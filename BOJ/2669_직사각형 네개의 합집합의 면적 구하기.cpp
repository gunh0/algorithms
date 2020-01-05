#include <iostream>

using namespace std;

int map[101][101] = { 0, };
int i, j;

void draw()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (i = b; i < d; i++)
    {
        for (j = a; j < c; j++)
            map[i][j] ++;
    }
}

int main()
{
    int total = 0;
    draw();
    draw();
    draw();
    draw();

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (map[i][j] >= 1)
                total++;
        }

    }

    printf("%d", total);
    return 0;
}