#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-braces"

#include "TestingTools.hpp"
#include "TestVec3.hpp"
#include "TestQuat.hpp"
#include "TestMat4.hpp"
#include "../include/GPM/DebugOutput.hpp"

// Test compilation line, execute from the root of the repository:
// - clang++: clang++ -W -Wall -Werror -O3 -ffp-contract=fast -march=native -fno-reciprocal-math -fno-trapping-math -fno-math-errno -fno-signed-zeros -msse2 tests/main.cpp -o main.exe
// - g++: g++ -W -Wall -Werror -O3 -ffp-contract=fast -march=native -freciprocal-math -fno-trapping-math -fno-math-errno -fno-signed-zeros -msse2 tests/main.cpp -o main.exe

int main()
{
    GPM::startTests();

    // GPM::Vector3
    GPM::testVec3Constructors();
    GPM::testVec3StaticMethods();
    GPM::testVec3SpecificMethods();

    // GPM::Quaternion
    GPM::testQuatStaticMethods();
    GPM::testQuatMethods();
    GPM::testQuatOperators();

    // GPM::Matrix4
    GPM::testMat4Methods();

    GPM::endTests();

    return 0;
}