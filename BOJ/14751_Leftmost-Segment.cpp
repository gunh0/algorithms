#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ld = long double; // Define long double as ld for convenience
const ld EPS = 1e-7; // Define a small epsilon for floating-point comparisons

// Structure to represent a line in the Convex Hull Trick
struct Line {
    ld slope, intercept, x; // Slope, y-intercept, and x-coordinate of intersection
    int index; // Index of the line for identification

    // Constructor to initialize a Line object
    Line(ld m, ld b, ld x, int idx) : slope(m), intercept(b), x(x), index(idx) {}

    // Operator to sort lines based on slope and intercept
    bool operator<(const Line &rhs) const {
        if (abs(slope - rhs.slope) < EPS) return intercept < rhs.intercept; // Compare intercepts if slopes are equal
        return slope > rhs.slope; // Sort in descending order of slope
    }
};

ld minX, maxX; // Define the range for x-coordinates
vector<Line> lines; // Vector to store lines
vector<pair<ld, int>> queries; // Vector to store queries (x-coordinate and index)
vector<Line> cht; // Vector to store lines in the Convex Hull Trick
int ptr = 0; // Pointer to track the current line for queries

// Function to calculate the intersection x-coordinate of two lines
ld intersect(const Line &a, const Line &b) {
    return (b.intercept - a.intercept) / (a.slope - b.slope);
}

// Function to add a new line to the Convex Hull Trick
void addLine(Line newLine) { // Removed const to allow modification
    // Remove lines that are worse than the new line
    while (!cht.empty()) {
        Line top = cht.back();
        if (abs(top.slope - newLine.slope) < EPS) {
            if (top.intercept < newLine.intercept) return; // If the new line is better, do nothing
            cht.pop_back(); // Remove the worse line
        } else {
            ld x = intersect(top, newLine);
            if (x <= top.x) cht.pop_back(); // Remove the worse line
            else break; // Stop if the new line is better
        }
    }
    // Add the new line to the Convex Hull Trick
    if (cht.empty()) {
        cht.push_back(newLine);
    } else {
        newLine.x = intersect(cht.back(), newLine); // Calculate intersection x-coordinate
        cht.push_back(newLine);
    }
    if (ptr >= cht.size()) ptr = cht.size() - 1; // Adjust pointer if necessary
}

// Function to query the best line for a given x-coordinate
int query(ld x) {
    // Move the pointer to the best line for the given x
    while (ptr < cht.size() - 1 && cht[ptr + 1].x < x + EPS) {
        ++ptr;
    }
    return cht[ptr].index; // Return the index of the best line
}

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr); // Untie cin and cout for faster I/O

    cin >> maxX >> minX; // Read the maximum and minimum x-coordinates
    int N;
    cin >> N; // Read the number of lines

    ld dx = maxX - minX; // Calculate the difference in x-coordinates
    for (int i = 0; i < N; ++i) {
        ld upY, lowY;
        cin >> upY >> lowY; // Read the upper and lower y-coordinates
        ld dy = upY - lowY; // Calculate the difference in y-coordinates
        ld slope = dy / dx; // Calculate the slope of the line
        ld intercept = lowY - slope * minX; // Calculate the y-intercept
        lines.emplace_back(slope, intercept, minX, i + 1); // Add the line to the vector
    }

    int M;
    cin >> M; // Read the number of queries
    queries.resize(M); // Resize the queries vector
    for (int i = 0; i < M; ++i) {
        ld x;
        cin >> x; // Read the x-coordinate for the query
        queries[i] = {x, i}; // Store the query with its index
    }

    sort(lines.begin(), lines.end()); // Sort lines based on slope and intercept
    sort(queries.begin(), queries.end()); // Sort queries based on x-coordinate

    vector<int> ans(M); // Vector to store the answers for each query
    for (const auto &line: lines) {
        addLine(line); // Add each line to the Convex Hull Trick
    }

    // Process each query and store the result
    for (const auto &queryPair: queries) {
        ans[queryPair.second] = query(queryPair.first); // Get the best line for the query
    }

    // Output the results for each query
    for (int idx: ans) {
        cout << idx << '\n'; // Print the index of the best line
    }

    return 0; // Return success
}
