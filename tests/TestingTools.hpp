#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <intrin.h>

#include "../include/GPM/Types.hpp"
#include "../include/GPM/Vector3.hpp"
#include "../include/GPM/Matrix4.hpp"

namespace GPM
{

// Global test counters
u32 passed = 0u;
u32 failed = 0u;
u32 seed   = 0u;

void startTests()
{
    // Random seed
    seed = (u32)__rdtsc();
    srand(seed);

    fprintf(stderr, "Seed used for this round of tests: %i\n", seed);
}


void endTests()
{
    fprintf(stderr, "\nOut of %u tests, ", passed + failed);
    fprintf(stderr, "%u \033[1m\033[32mpassed\033[0m\033[0m, ", passed);
    fprintf(stderr, "%u \033[1m\033[31mfailed\033[0m\033[0m\n", failed);
}


// ============= Test macro =============
#define TEST(title, expr) \
do \
{ \
if (expr) \
{ \
    fprintf(stderr, "> \033[1m\033[32mPassed\033[0m\033[0m"); \
    ++passed; \
} \
else \
{ \
    fprintf(stderr, "X \033[1m\033[31mFailed\033[0m\033[0m"); \
    ++failed; \
} \
fprintf(stderr, " (%s:%d)\033[0m: %s\n", __FILE__, __LINE__, title); \
} while(0)



// ============= Random values =============
f32 randomf32(const f32 minval = -1e5f, const f32 maxval = 1e5f)
{
    f32 f = minval;
    f += static_cast<f32>(maxval - minval) * (static_cast<f32>(rand()) / RAND_MAX);

    return f;
}


Vec3 randomVector3(const f32 minval = -1e10f, const f32 maxval = 1e10f)
{
    return
    {
        randomf32(minval, maxval),
        randomf32(minval, maxval),
        randomf32(minval, maxval)
    };
}


Mat4 randomMatrix4(const f32 minval = -1e10f, const f32 maxval = 1e10f)
{
    return
    {
        {randomVector3(minval, maxval), randomf32(minval, maxval)},
        {randomVector3(minval, maxval), randomf32(minval, maxval)},
        {randomVector3(minval, maxval), randomf32(minval, maxval)},
        {randomVector3(minval, maxval), randomf32(minval, maxval)}
    };
}


Mat4 randomTransformMatrix4(const f32 minval = -1e10f, const f32 maxval = 1e10f)
{
    return
    {
        {randomVector3(minval, maxval), .0f},
        {randomVector3(minval, maxval), .0f},
        {randomVector3(minval, maxval), .0f},
        {randomVector3(minval, maxval), 1.f}};
}

}