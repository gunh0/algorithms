#include <iostream>
#include <vector>
#include <stack>

int main()
{
    // Read number of towers
    int n;
    std::cin >> n;

    // Read tower heights
    std::vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> heights[i];
    }

    // Vector to store results (which tower receives the signal)
    std::vector<int> result(n, 0);

    // Stack to store previous towers (index, height)
    std::stack<std::pair<int, int>> tower_stack;

    // Process each tower
    for (int i = 0; i < n; i++)
    {
        // Current tower height
        int current_height = heights[i];

        // Find the first taller tower to the left
        while (!tower_stack.empty() && tower_stack.top().second < current_height)
        {
            tower_stack.pop();
        }

        // If there's a taller tower to the left, it receives the signal
        if (!tower_stack.empty())
        {
            result[i] = tower_stack.top().first + 1; // +1 for 1-indexed output
        }

        // Add current tower to the stack
        tower_stack.push({i, current_height});
    }

    // Output the results
    for (int i = 0; i < n; i++)
    {
        std::cout << result[i];
        if (i < n - 1)
        {
            std::cout << " ";
        }
    }

    return 0;
}