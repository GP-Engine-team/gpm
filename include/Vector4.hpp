#pragma once
#include "Vector3.hpp"

namespace GPM
{

struct Vector4
{
    // Data members
    Vec3    xyz{Vec3::zero()};
    f32     w  {.0f};

    constexpr Vector4() noexcept = default;
    constexpr Vector4(const Vec3& v, const f32 w = 1.f) noexcept;
    constexpr Vector4(const f32 x, const f32 y, const f32 z, const f32 w = 1.f) noexcept;

    // Methods
    constexpr Vector4 homogenized ()  const noexcept;
    constexpr void    homogenize  ()  noexcept;

    constexpr Vector4 operator*  (const Vector4& v) const noexcept;
    constexpr Vector4 operator/  (const Vector4& v) const noexcept;
    constexpr Vector4 operator*  (const f32 k) const noexcept;
    constexpr Vector4 operator/  (const f32 k) const noexcept;

    #ifdef _DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector4& v) noexcept;
    #endif
};

using Vec4 = Vector4;
using vec4 = Vector4;

#include "../src/Vector4.inl"

} // End of namespace Math