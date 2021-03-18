#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "../include/GPM/Types.hpp"
#include "../include/GPM/Vector3.hpp"

#define TEST(title, expr) \
do \
{ \
if (expr) \
{ \
    fprintf(stderr, "> \033[1m\033[32mPassed\033[0m\033[0m: "); \
} \
else \
{ \
    fprintf(stderr, "X \033[1m\033[31mFailed\033[0m\033[0m: "); \
} \
fprintf(stderr, "%s\n", title); \
} while(0)

namespace GPM
{

f32 randomf32()
{
    f32 f = rand();
    f += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (rand() - rand())));
    f += static_cast<float>(rand()) / rand();

#ifdef _DEBUG
    fprintf(stderr, "%f is used for the following tests\n", f);
#endif

    return f;
}


Vec3 randomVector3()
{
    f32 x = rand(), y = rand(), z = rand();
    x += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (rand() - rand())));
    x += static_cast<float>(rand()) / rand();
    y += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (rand() - rand())));
    y += static_cast<float>(rand()) / rand();
    z += static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (rand() - rand())));
    z += static_cast<float>(rand()) / rand();

    const Vec3 v{x, y, z};

#ifdef _DEBUG
    fprintf(stderr, "[%f, %f, %f] is used for the following tests\n", v.x, v.y, v.z);
#endif

    return v;
}


bool areEqual(const f32 a, const f32 b, const f32 eps = 1e-6)
{
    return fabs(b - a) < eps;
}

}