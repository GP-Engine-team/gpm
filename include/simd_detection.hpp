#pragma once

#include <intrin.h>

#if defined(__MMX__)
#   define MMX 1
#endif
#if defined(__SSE__)
#   define SSE 1
#endif
#if defined(__SSE2__)
#   define SSE2 1
#endif
#if defined(__SSE3__)
#   define SSE3 1
#endif
#if defined(__SSSE3__)
#   define SSSE3 1
#endif
#if defined(__SSE4_1__)
#    define SSE4_1 1
#endif
#if defined(__SSE4_2__)
#    define SSE4_2 1
#endif

#if defined(__AVX__)
#   define AVX 1
#if defined(__AVX2__)
#   define AVX2 1
#endif

#if defined(__FMA__)
#   define FMA 1
#endif