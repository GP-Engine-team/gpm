/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include "Vector3.hpp"
#include <cfloat>
#include <cmath>
#include <iostream>

namespace GPM
{

struct Vector4
{
    // Data members
    Vec3    xyz;
    f32     w;

    Vector4() noexcept;
    constexpr Vector4(const Vec3& v, const f32 w = 1.f) noexcept;
    constexpr Vector4(const f32 x, const f32 y, const f32 z, const f32 w = 1.f) noexcept;

    // Methods
    constexpr Vector4 homogenized ()  const noexcept;
    constexpr void    homogenize  ()  noexcept;

    constexpr Vector4 operator*  (const Vector4& v) const noexcept;
    constexpr Vector4 operator/  (const Vector4& v) const noexcept;
    constexpr Vector4 operator*  (const f32 k) const noexcept;
    constexpr Vector4 operator/  (const f32 k) const noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Vector4& v) noexcept;
};

using Vec4 = Vector4;
using vec4 = Vector4;

#include "../src/Vector4.inl"

} // End of namespace Math