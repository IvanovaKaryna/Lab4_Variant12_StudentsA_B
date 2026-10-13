#include "StudentA_Dynamic.h"
#include <limits>

unsigned long long factorial(int n)
{
    if (n < 0)
        return 0;

    unsigned long long result = 1;

    for (int i = 2; i <= n; ++i)
    {
        if (result > std::numeric_limits<unsigned long long>::max() /
                         static_cast<unsigned long long>(i))
            return 0;

        result *= static_cast<unsigned long long>(i);
    }

    return result;
}

unsigned long long permutations(int n)
{
    return factorial(n);
}

unsigned long long combinations(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;

    if (k > n - k)
        k = n - k;

    unsigned long long result = 1;

    for (int i = 1; i <= k; ++i)
    {
        unsigned long long numerator =
            static_cast<unsigned long long>(n - k + i);

        result = result * numerator / static_cast<unsigned long long>(i);
    }

    return result;
}

unsigned long long arrangements(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;

    unsigned long long result = 1;

    for (int i = 0; i < k; ++i)
    {
        unsigned long long factor =
            static_cast<unsigned long long>(n - i);

        if (result > std::numeric_limits<unsigned long long>::max() / factor)
            return 0;

        result *= factor;
    }

    return result;
}
