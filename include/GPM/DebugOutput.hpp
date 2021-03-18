/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include <iomanip>
#include <iostream>

namespace GPM
{

std::ostream& operator<<(std::ostream& os, const Matrix3& m)        noexcept;
std::ostream& operator<<(std::ostream& os, const Matrix4& m)        noexcept;
std::ostream& operator<<(std::ostream& os, const Quaternion& q)     noexcept;
std::ostream& operator<<(std::ostream& os, const SplitTransform& m) noexcept;
std::ostream& operator<<(std::ostream& os, const Transform& m)      noexcept;
std::ostream& operator<<(std::ostream& os, const Vector2& v)        noexcept;
std::ostream& operator<<(std::ostream& os, const Vector3& v)        noexcept;
std::ostream& operator<<(std::ostream& os, const Vector4& v)        noexcept;

#include "DebugOutput.inl"

} // End of namespace GPM