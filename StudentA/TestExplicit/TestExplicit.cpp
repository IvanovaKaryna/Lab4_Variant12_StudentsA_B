
#include <iostream>
#include <windows.h>

using namespace std;

typedef int (*NextPermutationFunc)(int*, int);
typedef int (*HeapPermutationFunc)(const int*, int, int*, int);
typedef int (*GenerateAllFunc)(const int*, int, int*, int);
typedef int (*PermutationCountFunc)(int);

int main()
{
    HMODULE library = LoadLibraryW(L"PermutationDLL.dll");

    if (library == nullptr) {
        DWORD error = GetLastError();

        cout << "Error: DLL load failed!" << endl;
        cout << "Windows error code: " << error << endl;

        system("pause");
        return 1;
    }

    auto nextPermutation = reinterpret_cast<NextPermutationFunc>(
        GetProcAddress(library, "nextPermutation"));

    auto heapPermutation = reinterpret_cast<HeapPermutationFunc>(
        GetProcAddress(library, "heapPermutation"));

    auto generateAll = reinterpret_cast<GenerateAllFunc>(
        GetProcAddress(library, "generateAll"));

    auto permutationCount = reinterpret_cast<PermutationCountFunc>(
        GetProcAddress(library, "permutationCount"));

    if (!nextPermutation || !heapPermutation ||
        !generateAll || !permutationCount)
    {
        cout << "Error: function not found!" << endl;
        FreeLibrary(library);
        return 1;
    }

    cout << "DLL loaded successfully!" << endl;
    cout << "Permutation count for 5: "
        << permutationCount(5) << endl;

    int values[] = { 1, 2, 3 };
    int next[] = { 1, 2, 3 };
    int output[18] = {};

    cout << "Next permutation result: "
        << nextPermutation(next, 3) << endl;

    cout << "Heap permutations generated: "
        << heapPermutation(values, 3, output, 18) << endl;

    cout << "All permutations generated: "
        << generateAll(values, 3, output, 18) << endl;

    FreeLibrary(library);
    return 0;
}
