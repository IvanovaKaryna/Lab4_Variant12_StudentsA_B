
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

    cout << "\nPermutation count tests" << endl;
    cout << "Permutation count for 5: "
        << permutationCount(5) << endl;
    cout << "Permutation count for 0: "
        << permutationCount(0) << endl;
    cout << "Permutation count for -1: "
        << permutationCount(-1) << endl;
    cout << "Permutation count for 13: "
        << permutationCount(13) << endl;

    cout << "\nNext permutation tests" << endl;

    int next[] = { 1, 2, 3 };

    cout << "Next permutation result: "
        << nextPermutation(next, 3) << endl;
    cout << "After next permutation: "
        << next[0] << " " << next[1] << " " << next[2] << endl;

    int last[] = { 3, 2, 1 };

    cout << "Last permutation result: "
        << nextPermutation(last, 3) << endl;
    cout << "After last permutation: "
        << last[0] << " " << last[1] << " " << last[2] << endl;

    cout << "\nPermutation generation tests" << endl;

    int values[] = { 1, 2, 3 };
    int output[18] = {};

    cout << "Heap permutations generated: "
        << heapPermutation(values, 3, output, 18) << endl;
    cout << "All permutations generated: "
        << generateAll(values, 3, output, 18) << endl;

    cout << "\nSmall buffer tests" << endl;

    int smallOutput[5] = {};

    cout << "Heap permutation with small buffer: "
        << heapPermutation(values, 3, smallOutput, 5) << endl;
    cout << "All permutations with small buffer: "
        << generateAll(values, 3, smallOutput, 5) << endl;

    cout << "\nNull pointer tests" << endl;

    cout << "Next permutation nullptr: "
        << nextPermutation(nullptr, 3) << endl;
    cout << "Heap nullptr input: "
        << heapPermutation(nullptr, 3, output, 18) << endl;
    cout << "Heap nullptr output: "
        << heapPermutation(values, 3, nullptr, 18) << endl;
    cout << "Generate nullptr input: "
        << generateAll(nullptr, 3, output, 18) << endl;
    cout << "Generate nullptr output: "
        << generateAll(values, 3, nullptr, 18) << endl;

    cout << "\nZero-length tests" << endl;

    cout << "Next permutation length 0: "
        << nextPermutation(values, 0) << endl;
    cout << "Heap permutation length 0: "
        << heapPermutation(values, 0, output, 18) << endl;
    cout << "Generate all length 0: "
        << generateAll(values, 0, output, 18) << endl;

    FreeLibrary(library);

    cout << "\nTests completed." << endl;

    return 0;
}
