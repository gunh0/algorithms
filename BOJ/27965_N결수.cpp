#include <iostream>

// Function to calculate (base^exp) % mod efficiently
long long power_mod(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main()
{
    long long N, K;
    std::cin >> N >> K;

    // Initialize result
    long long result = 0;

    for (long long i = 1; i <= N; i++)
    {
        // Calculate the number of digits in i
        long long temp = i;
        int digits = 0;
        while (temp > 0)
        {
            temp /= 10;
            digits++;
        }

        // Calculate 10^digits % K using fast exponentiation
        long long power_of_ten = power_mod(10, digits, K);

        // Update result using modular arithmetic
        result = ((result * power_of_ten) % K + (i % K)) % K;
    }

    std::cout << result << std::endl;

    return 0;
}