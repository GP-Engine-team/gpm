/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include <cfloat>
#include <cmath>
#include <iostream>

#include "Vector2.hpp"

namespace GPM
{

union Vector3
{
    // Data members
    struct
    {
        union
        {
            Vec2 xy;
            struct { f32 x; f32 y; };
        };
        
        f32 z;
    };

    f32 e[3];

    // Constructors
    Vector3() = default;
    constexpr Vector3(const f32 k)                                          noexcept;
    constexpr Vector3(const f32 x, const f32 y, const f32 z)                noexcept;
    constexpr Vector3(Vec2 v, const f32 z = .0f)                            noexcept;
    constexpr Vector3(const f32 coef[3])                                    noexcept;

    // Static methods (pseudo-constructors)
    static constexpr Vector3 zero           ()                              noexcept;
    static constexpr Vector3 one            ()                              noexcept;
    static constexpr Vector3 right          ()                              noexcept;
    static constexpr Vector3 up             ()                              noexcept;
    static constexpr Vector3 forward        ()                              noexcept;

    // Member methods
    constexpr f32       length2             ()                              const noexcept;
    f32                 length              ()                              const noexcept;
    constexpr f32       dot                 (const Vector3& v)              const noexcept;
    constexpr Vector3   cross               (const Vector3& v)              const noexcept;
    constexpr bool      isNull              ()                              const noexcept;
    constexpr bool      isOrthogonalTo      (const Vector3& v)              const noexcept;
    constexpr bool      isNormalized        ()                              const noexcept;
    constexpr bool      isOrthonormalTo     (const Vector3& v)              const noexcept;
    constexpr bool      isColinearTo        (const Vector3& v)              const noexcept;
    bool                isEqualTo           (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    bool                isNotEqualTo        (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    void                normalize           ()                              noexcept;
    constexpr f32       distance2To         (const Vector3& v)              const noexcept;
    f32     	        distanceTo		    (const Vector3& v)              const noexcept;
    f32     	        angleWithUnitary    (const Vector3& v)              const noexcept;
    f32                 angleWith		    (const Vector3& v)              const noexcept;
    f32                 triangleArea	    (const Vector3& v)              const noexcept;
    Vector3             normalized          ()                              const noexcept;
    constexpr Vector3   projectedOnUnitary  (const Vector3& v)              const noexcept;
    constexpr Vector3   projectedOn         (const Vector3& v)              const noexcept;
    Vector3             rotatedAroundUnitary(const Vector3& v,
                                             const f32 angle)               const noexcept;
    Vector3             rotatedAround       (const Vector3& v,
                                             const f32 angle)               const noexcept;
    constexpr Vector3   lerp                (const Vector3& v,
                                             const f32 t)                   const noexcept;

    // Operator overloads
    constexpr Vector3&	operator+=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator+=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator-=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator-=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator*=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator*=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator/=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator/=          (const Vector3&& v)             noexcept;
    constexpr Vector3&  operator*=          (const f32 k)                   noexcept;
    constexpr Vector3&  operator/=          (const f32 k)                   noexcept;
    constexpr Vector3   operator+           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator+           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator-           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator*           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator*           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator/           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator/           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           ()                              const noexcept;
    constexpr Vector3	operator*           (const f32 k)                   const noexcept;
    constexpr Vector3	operator/           (const f32 k)                   const noexcept;

    friend std::ostream& operator<<         (std::ostream& os, const Vector3& v) noexcept;
};

using Vec3 = Vector3;
using vec3 = Vector3;

#include "../src/Vector3.inl"

} // End of namespace Math