#include <iostream>
#include <windows.h>

using factorial_fn = unsigned long long (*)(int);
using permutations_fn = unsigned long long (*)(int);
using combinations_fn = unsigned long long (*)(int, int);
using arrangements_fn = unsigned long long (*)(int, int);

int main()
{
    std::cout << "=== Explicit linking ===\n";

    HMODULE dll = LoadLibraryA("StudentA_Dynamic.dll");

    if (dll == nullptr)
    {
        std::cerr << "Cannot load StudentA_Dynamic.dll. Error: "
                  << GetLastError() << '\n';
        return 1;
    }

    auto factorial = reinterpret_cast<factorial_fn>(
        GetProcAddress(dll, "factorial"));

    auto permutations = reinterpret_cast<permutations_fn>(
        GetProcAddress(dll, "permutations"));

    auto combinations = reinterpret_cast<combinations_fn>(
        GetProcAddress(dll, "combinations"));

    auto arrangements = reinterpret_cast<arrangements_fn>(
        GetProcAddress(dll, "arrangements"));

    if (!factorial || !permutations || !combinations || !arrangements)
    {
        std::cerr << "Cannot find one or more functions. Error: "
                  << GetLastError() << '\n';
        FreeLibrary(dll);
        return 1;
    }

    std::cout << "factorial(5) = " << factorial(5) << '\n';
    std::cout << "permutations(4) = " << permutations(4) << '\n';
    std::cout << "combinations(5, 2) = " << combinations(5, 2) << '\n';
    std::cout << "arrangements(5, 2) = " << arrangements(5, 2) << '\n';

    FreeLibrary(dll);
    std::cout << "DLL unloaded successfully\n";

    return 0;
}
