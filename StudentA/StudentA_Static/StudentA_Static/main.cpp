
#include <iostream>
#include "combinatorics.h"

int main()
{
    std::cout << "Factorial 5: " << factorial(5) << '\n';
    std::cout << "Permutations 4: " << permutations(4) << '\n';
    std::cout << "Combinations C(5, 2): " << combinations(5, 2) << '\n';
    std::cout << "Arrangements A(5, 2): " << arrangements(5, 2) << '\n';

    return 0;
}
