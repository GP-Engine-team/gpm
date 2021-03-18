#pragma once

#if defined(_MSC_VER)
#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif


#include "Types.hpp"
#include <math.h>

namespace GPM
{

f32 clamp(const f32 k, const f32 lo, const f32 hi);

#include "Calc.inl"

}