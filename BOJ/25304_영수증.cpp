#include <iostream>

int main()
{
    // Read the receipt total
    long long totalAmount;
    std::cin >> totalAmount;

    // Read the number of different items
    int itemCount;
    std::cin >> itemCount;

    // Calculate the actual total from items
    long long calculatedTotal = 0;

    // Process each item
    for (int i = 0; i < itemCount; i++)
    {
        int price, quantity;
        std::cin >> price >> quantity;

        // Add the cost of this item to the calculated total
        calculatedTotal += static_cast<long long>(price) * quantity;
    }

    // Check if the calculated total matches the receipt total
    if (calculatedTotal == totalAmount)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}