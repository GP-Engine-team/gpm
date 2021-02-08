#pragma once

#include "Matrix4.hpp"
#include "types.hpp"

#include <cmath>

namespace GPM
{

// Transformation
constexpr Mat4 translation(const Vec3& t)   noexcept;
Mat4           rotationX  (const f32 angle) noexcept;
Mat4           rotationY  (const f32 angle) noexcept;
Mat4           rotationZ  (const f32 angle) noexcept;
Mat4           rotation   (const Vec3& t)   noexcept;
constexpr Mat4 scaling    (const Vec3& t)   noexcept;
Mat4           TRS        (const Vec3& t,
                           const Vec3& r,
                           const Vec3& s)   noexcept;

// Referential
Mat4           normalMat  (const Mat4& m)   noexcept;
constexpr Vec3 right      (const Mat4& m)   noexcept;
constexpr Vec3 up         (const Mat4& m)   noexcept;
constexpr Vec3 forward    (const Mat4& m)   noexcept;
constexpr Vec3 position   (const Mat4& m)   noexcept;

// View
constexpr Mat4 symFrustrum(const f32 right,
                           const f32 top,
                           const f32 near,
                           const f32 far)   noexcept;
Mat4           perspective(const f32 fovY,
                           const f32 aspect,
                           const f32 near,
                           const f32 far)   noexcept;
constexpr Mat4 viewport   (const f32 x,
                           const f32 y,
                           const f32 width,
                           const f32 height) noexcept;

#include "../src/Transform.inl"

} // End of namespace GPM