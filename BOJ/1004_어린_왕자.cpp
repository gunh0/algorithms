#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a point (x, y) lies inside a circle defined by center (cx, cy) and radius r
bool isInside(int x, int y, int cx, int cy, int r)
{
    return (pow(x - cx, 2) + pow(y - cy, 2) < pow(r, 2));
}

int main()
{
    int T; // Number of test cases
    cin >> T;
    while (T--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // Departure and arrival points

        int n; // Number of planetary systems
        cin >> n;

        int count = 0; // Count of planetary system boundaries crossed
        while (n--)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r; // Center and radius of a planetary system

            // Check if departure and arrival points are inside or outside the planetary system
            bool startInside = isInside(x1, y1, cx, cy, r);
            bool endInside = isInside(x2, y2, cx, cy, r);

            // If only one of the points is inside, increase the count
            if (startInside != endInside)
            {
                count++;
            }
        }

        cout << count << endl; // Print the minimum number of entries/exits
    }
    return 0;
}
