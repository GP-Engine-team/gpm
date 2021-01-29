#pragma once

#include <cmath>
#include <cfloat>

#ifdef _DEBUG
#include <iomanip>
#include <iostream>
#endif

namespace GPM
{

struct Vector2
{
    // Data members
    f32 x{.0f};
    f32 y{.0f};
    
    // Static methods (pseudo-constructors)
    static constexpr Vector2 zero   () noexcept;
    static constexpr Vector2 right  () noexcept;
    static constexpr Vector2 up     () noexcept;

    // Member methods
    constexpr f32       length2             ()                  const noexcept;
    f32                 length              ()                  const noexcept;
    constexpr f32       dot                 (const Vector2& v)  const noexcept;
    constexpr f32       cross               (const Vector2& v)  const noexcept;
    constexpr bool      isNull              ()                  const noexcept;
    constexpr bool      isOrthogonalTo      (const Vector2& v)  const noexcept;
    constexpr bool      isNormalized        ()                  const noexcept;
    constexpr bool      isOrthonormalTo     (const Vector2& v)  const noexcept;
    constexpr bool      isColinearTo        (const Vector2& v)  const noexcept;
    bool                isEqualTo           (const Vector2& v,
                                             const f32 eps = FLT_EPSILON) const noexcept;
    bool                isNotEqualTo        (const Vector2& v,
                                             const f32 eps = FLT_EPSILON) const noexcept;
    void                normalize           ()                  noexcept;
    constexpr f32       distance2To         (const Vector2& v)  const noexcept;
    f32                 distanceTo          (const Vector2& v)  const noexcept;
    f32                 angleWithUnitary    (const Vector2& v)  const noexcept;
    f32                 angleWith           (const Vector2& v)  const noexcept;
    constexpr f32       triangleArea        (const Vector2& v)  const noexcept;
    Vector2             normalized          ()                  const noexcept;
    constexpr Vector2   projectedOnUnitary  (const Vector2& v)  const noexcept;
    constexpr Vector2   projectedOn         (const Vector2& v)  const noexcept;
    Vector2             rotated             (const f32 angle)   const noexcept;
    constexpr Vector2   rotated90           ()                  const noexcept;
    constexpr Vector2   lerp                (const Vector2& v, const f32 f32) const noexcept;

    // Operator overloads
    constexpr Vector2&  operator+=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator+=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator-=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator-=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator*=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator*=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator/=          (const Vector2& v)  noexcept;
    constexpr Vector2&  operator/=          (const Vector2&& v) noexcept;
    constexpr Vector2&  operator*=          (const f32 k)       noexcept;
    constexpr Vector2&  operator/=          (const f32 k)       noexcept;
    constexpr Vector2   operator+           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator+           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator-           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator-           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator*           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator*           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator/           (const Vector2& v)  const noexcept;
    constexpr Vector2   operator/           (const Vector2&& v) const noexcept;
    constexpr Vector2   operator-           ()                  const noexcept;
    constexpr Vector2   operator*           (const f32 k)       const noexcept;
    constexpr Vector2   operator/           (const f32 k)       const noexcept;

    #ifdef _DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector2& v) noexcept;
    #endif
};

using Vec2 = Vector2;
using vec2 = Vector2;

#include "../src/Vector2.inl"

} // End of namespace Math