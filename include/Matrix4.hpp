/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include "types.hpp"
#include "Vector4.hpp"

#include <iomanip>
#include <iostream>

namespace GPM
{

#define MAT4_COL  4u
#define MAT4_COEF 16u

// Aligned as 16 to enable auto-vectorization
union alignas(16) Matrix4
{
    // Data members
    f32  e[MAT4_COEF];
    Vec4 c[MAT4_COL];

    // Constructors
    Matrix4() noexcept = default;
    constexpr Matrix4(const f32 e0,  const f32 e1,  const f32 e2,  const f32 e3,
                      const f32 e4,  const f32 e5,  const f32 e6,  const f32 e7,
                      const f32 e8,  const f32 e9,  const f32 e10, const f32 e11,
                      const f32 e12, const f32 e13, const f32 e14, const f32 e15) noexcept;
    constexpr Matrix4(const Vec4& c0, const Vec4& c1, const Vec4& c2, const Vec4& c3) noexcept;

    // Static methods, pseudo-constructors
    static constexpr Matrix4 zero       ()                       noexcept;
    static constexpr Matrix4 identity   ()                       noexcept;

    // Methods
    Matrix4             cofactor        ()                       const noexcept;
    constexpr Matrix4   transposed      ()                       const noexcept;
    constexpr Matrix4   adjugate        ()                       const noexcept;
    constexpr f32       det             ()                       const noexcept;
    Matrix4             inversed        ()                       const noexcept;
    constexpr f32       trace           ()                       const noexcept;

    // Operator overloads
    constexpr Matrix4&  operator*=      (const Matrix4& m)       noexcept;
    constexpr Matrix4&  operator/=      (const f32 k)            noexcept;
    constexpr Matrix4   operator*       (const Matrix4& m)       const noexcept;
    constexpr Vec4      operator*       (const Vec4& v)          const noexcept;
    Matrix4             operator/       (const f32 k)            const noexcept;

    friend std::ostream& operator<<     (std::ostream& os, const Matrix4& m) noexcept;
};

using Mat4 = Matrix4;
using mat4 = Matrix4;

#include "../src/Matrix4.inl"

} // End of namespace Math