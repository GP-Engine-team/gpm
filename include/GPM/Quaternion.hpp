/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include "constants.hpp"
#include "types.hpp"
#include "Vector3.hpp"

#include <iostream>

namespace GPM
{

union alignas(16) Quaternion
{
    struct
    {
        union
        {
            Vec3 v;
            struct { f32 x; f32 y; f32 z; };
        };
        f32 s;
    };
    f32 e[4];

    static Quaternion angleAxis(const f32 angle, const Vec3& axis) noexcept;
    static constexpr Quaternion identity() noexcept;

    // Methods
    constexpr f32               length2     ()                                      const noexcept;
    f32                         length      ()                                      const noexcept;
    constexpr f32               dot         (const Quaternion& q)                   const noexcept;
    Quaternion                  normalized  ()                                      const noexcept;
    void                        normalize   ()                                      noexcept;
    constexpr Quaternion        conjugate   ()                                      const noexcept;
    constexpr Quaternion        inversed    ()                                      const noexcept;
    Quaternion                  slerp       (const Quaternion& target, const f32 t) const noexcept;
    Quaternion                  nlerp       (const Quaternion& target, const f32 t) const noexcept;

    // Operator overloads
    constexpr Quaternion        operator+   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   ()                                      const noexcept;
    constexpr Quaternion        operator*   (const Quaternion& q)                   const noexcept;
    constexpr Vec3              operator*   (const Vec3& v)                         const noexcept;
    constexpr Quaternion        operator*   (const f32 k)                           const noexcept;
    constexpr Quaternion        operator/   (const f32 k)                           const noexcept;

    friend std::ostream&        operator<<  (std::ostream& os, const Quaternion& q) noexcept;
};

using Quat = Quaternion;

#include "Quaternion.inl"

} // End of namespace GPM