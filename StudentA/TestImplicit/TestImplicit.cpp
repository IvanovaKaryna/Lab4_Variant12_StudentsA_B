#include <iostream>
#include "PermutationLib.h"

using namespace std;

int main()
{
    cout << "Permutation count for 5: "
        << permutationCount(5) << endl;

    int values[] = { 1, 2, 3 };
    int output[18];

    cout << "Next permutation result: "
        << nextPermutation(values, 3) << endl;

    int heapResult = heapPermutation(values, 3, output, 18);
    cout << "Heap permutations generated: "
        << heapResult << endl;

    int allResult = generateAll(values, 3, output, 18);
    cout << "All permutations generated: "
        << allResult << endl;

    return 0;
}