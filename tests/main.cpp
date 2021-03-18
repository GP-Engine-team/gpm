#include "TestingTools.hpp"
#include "TestVec3.hpp"

// Test compilation line, execute from the root of the repository:
// - clang++: clang++ -W -Wall -Werror -O3 -D_DEBUG -ffp-contract=fast -march=native -freciprocal-math -fno-trapping-math -fno-math-errno -fno-signed-zeros -msse2 tests/main.cpp -o main.exe
// - g++: g++ -W -Wall -Werror -O3 -ffp-contract=fast -march=native -freciprocal-math -fno-trapping-math -fno-math-errno -fno-signed-zeros -msse2 tests/main.cpp -o main.exe

int main()
{
    // Random seed
    srand(__rdtsc());

    GPM::testVec3Constructors();
    GPM::testVec3StaticMethods();
    GPM::testVec3SpecificMethods();

    return 0;
}