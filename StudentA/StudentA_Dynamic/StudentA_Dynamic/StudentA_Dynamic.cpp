
#include "StudentA_Dynamic.h"

unsigned long long factorial(int n)
{
    if (n < 0 || n > 20)
        return 0;

    unsigned long long result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

unsigned long long permutations(int n)
{
    return factorial(n);
}

unsigned long long combinations(int n, int k)
{
    if (n < 0 || k < 0 || k > n || n > 20)
        return 0;

    return factorial(n) / (factorial(k) * factorial(n - k));
}

unsigned long long arrangements(int n, int k)
{
    if (n < 0 || k < 0 || k > n || n > 20)
        return 0;

    return factorial(n) / factorial(n - k);
}
