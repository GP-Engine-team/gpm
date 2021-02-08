/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once
#include "types.hpp"
#include "Vector3.hpp"

#include <iomanip>
#include <iostream>

namespace GPM
{

#define MAT3_COL  3u
#define MAT3_SIZE 9u

struct Matrix3
{
    // Data members, aligned by 16 to enable auto-vectorization
    alignas(16) f32 coef[MAT3_SIZE];

    // Static methods, pseudo-constructors
    static constexpr Matrix3 zero       ()                  noexcept;
    static constexpr Matrix3 identity   ()                  noexcept;

    // Methods
    constexpr Matrix3   cofactor        ()                  const noexcept;
    constexpr Matrix3   transposed      ()                  const noexcept;
    constexpr Matrix3   adjugate        ()                  const noexcept;
    constexpr f32       det             ()                  const noexcept;
    Matrix3             inversed        ()                  const noexcept;
    constexpr f32       trace           ()                  const noexcept;

    // Operator overloads
    constexpr Matrix3&  operator*=      (const Matrix3& m)  noexcept;
    constexpr Matrix3&  operator/=      (const f32 k)       noexcept;
    Matrix3             operator*       (const Matrix3& m)  const noexcept;
    constexpr Vec3      operator*       (const Vec3& v)     const noexcept;
    Matrix3             operator/       (const f32 k)       const noexcept;
    constexpr f32       operator[]      (const u8 i)        const noexcept;
    constexpr f32       operator()      (const u8 i, const u8 j) const noexcept;

    friend std::ostream& operator<<     (std::ostream& os, const Matrix3& m) noexcept;
};

using Mat3 = Matrix3;
using mat3 = Matrix3;

#include "../src/Matrix3.inl"

} // End of namespace Math