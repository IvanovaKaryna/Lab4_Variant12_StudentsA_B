
#include <iostream>
#include "StudentA_Dynamic.h"

int main()
{
    std::cout << "=== Implicit linking ===\n";

    std::cout << "factorial(5) = " << factorial(5) << '\n';
    std::cout << "permutations(4) = " << permutations(4) << '\n';
    std::cout << "combinations(5, 2) = " << combinations(5, 2) << '\n';
    std::cout << "arrangements(5, 2) = " << arrangements(5, 2) << '\n';

    return 0;
}
