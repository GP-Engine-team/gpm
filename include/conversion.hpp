#pragma once

#include "Quaternion.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Matrix3.hpp"
#include "Matrix4.hpp"

namespace GPM
{

constexpr Mat3       toMatrix3   (const Mat4& m) noexcept;
constexpr Mat4       toMatrix4   (const Mat3& m) noexcept;

constexpr Mat3       toMatrix3   (const Quat& q) noexcept;
constexpr Mat4       toMatrix4   (const Quat& q) noexcept;

Quat                 toQuaternion(const Mat3& m) noexcept;
Quat                 toQuaternion(const Mat4& m) noexcept;

#include "../src/conversion.inl"

}