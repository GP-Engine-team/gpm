#pragma once

#include "constants.hpp"
#include "types.hpp"
#include "Vector3.hpp"

#ifdef _DEBUG
#include <iostream>
#endif

namespace GPM
{

struct Quaternion
{
    Vec3 v;
    f32  s;

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

    // Getters, optional, only for comfort
    constexpr f32               x           ()                                      const noexcept;
    constexpr f32               y           ()                                      const noexcept;
    constexpr f32               z           ()                                      const noexcept;
    constexpr f32               w           ()                                      const noexcept;

    // Operator overloads
    constexpr Quaternion        operator+   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   (const Quaternion& q)                   const noexcept;
    constexpr Quaternion        operator-   ()                                      const noexcept;
    constexpr Quaternion        operator*   (const Quaternion& q)                   const noexcept;
    constexpr Vec3              operator*   (const Vec3& v)                         const noexcept;
    constexpr Quaternion        operator*   (const f32 k)                           const noexcept;
    constexpr Quaternion        operator/   (const f32 k)                           const noexcept;
    constexpr f32               operator[]  (const u8 i)                            const noexcept;
    constexpr f32&              operator[]  (const u8 i)                            noexcept;

    #ifdef _DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q) noexcept;
    #endif
};

#include "Quaternion.inl"

} // End of namespace GPM