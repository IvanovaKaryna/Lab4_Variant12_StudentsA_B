# Student B SDK — Permutation Library

## Files
- include/PermutationLib.h — public header
- lib/libPermutationStatic.a — static library for GCC/MinGW

## Usage
Add the include directory to the compiler search path and link
lib/libPermutationStatic.a with the client application.

Example:
g++ main.cpp -I include lib/libPermutationStatic.a -o Client.exe
