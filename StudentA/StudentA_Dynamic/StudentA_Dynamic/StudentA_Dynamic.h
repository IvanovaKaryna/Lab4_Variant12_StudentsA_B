
#pragma once

#ifdef STUDENTA_DYNAMIC_EXPORTS
#define COMBINATORICS_API __declspec(dllexport)
#else
#define COMBINATORICS_API __declspec(dllimport)
#endif

extern "C"
{
    COMBINATORICS_API unsigned long long factorial(int n);
    COMBINATORICS_API unsigned long long permutations(int n);
    COMBINATORICS_API unsigned long long combinations(int n, int k);
    COMBINATORICS_API unsigned long long arrangements(int n, int k);
}
