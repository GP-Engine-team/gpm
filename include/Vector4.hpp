/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include <cfloat>
#include <cmath>
#include <iostream>

#include "Vector3.hpp"

namespace GPM
{

union alignas(16) Vector4
{
    // Data members
    struct
    {
        union 
        {
            Vec3 xyz;

            struct
            {
                union
                {
                    Vec2 xy;
                    struct { f32 x; f32 y; };
                };

                f32 z;
            };
        };

        f32 w;
    };

    f32 e[4];

    Vector4() noexcept = default;
    constexpr Vector4(const f32 k)                                              noexcept;
    constexpr Vector4(const f32 x, const f32 y, const f32 z, const f32 w = 1.f) noexcept;
    constexpr Vector4(const Vec2& v, const f32 z = .0f, const f32 w = 1.f)      noexcept;
    constexpr Vector4(const Vec3& v, const f32 w = 1.f)                         noexcept;
    constexpr Vector4(const f32 coef[4])                                        noexcept;

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