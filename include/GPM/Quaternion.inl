﻿/* =================== Static methods (pseudo-constructors) =================== */
inline Quaternion Quaternion::angleAxis(const f32 angle, const Vec3& axis) noexcept
{
    const f32 halfAngle{angle * .5f};
    return {axis.normalized() * sinf(halfAngle), cosf(halfAngle)};
}

inline constexpr Quaternion Quaternion::identity() noexcept
{
    return {Vec3::zero(), 1.f};
}

inline Quaternion Quaternion::lookAt(const Vec3& sourcePoint, const Vec3& destPoint) noexcept
{
    Vec3 forwardVector = (destPoint - sourcePoint).normalized();

    float dot = Vec3::dot(Vec3::forward(), forwardVector);

    if (std::abs(dot - (-1.0f)) < 0.000001f)
    {
        return Quaternion::angleAxis(PI, Vec3::up());
    }
    if (std::abs(dot - (1.0f)) < 0.000001f)
    {
        return Quaternion::identity();
    }

    float rotAngle = (float)std::acos(dot);
    Vec3  rotAxis  = Vec3::cross(Vec3::forward(), forwardVector);
    rotAxis        = rotAxis.normalized();
    return Quaternion::angleAxis(rotAngle, rotAxis);
}

/* =================== Methods =================== */
inline constexpr f32 Quaternion::length2() const noexcept
{
    return v.length2() + s * s;
}

inline f32 Quaternion::length() const noexcept
{
    return sqrtf(length2());
}

inline constexpr f32 Quaternion::dot(const Quaternion& q) const noexcept
{
    return v.dot(q.v) + s * q.s;
}

inline Quaternion Quaternion::normalized() const noexcept
{
    return *this / length();
}

inline void Quaternion::normalize() noexcept
{
    const f32 reciprocal_len{1.f / length()};
    v *= reciprocal_len;
    s *= reciprocal_len;
}

inline constexpr Quaternion Quaternion::conjugate() const noexcept
{
    return {-v, s};
}

inline constexpr Quaternion Quaternion::inversed() const noexcept
{
    return conjugate() / length2();
}

inline Quaternion Quaternion::slerp(const Quaternion& target, const f32 t) const noexcept
{
    const f32 angle{acosf(dot(target))};
    return (*this * (sinf((1.f - t) * angle)) + target * sinf(t * angle)) / sinf(angle);
}

inline Quaternion Quaternion::nlerp(const Quaternion& target, const f32 t) const noexcept
{
    const Quaternion q{*this * (1.f - t) + target * t};
    return q.normalized();
}

/* =================== Operator overloads =================== */
inline constexpr Quaternion Quaternion::operator+(const Quaternion& q) const noexcept
{
    return {v + q.v, s + q.s};
}

inline constexpr Quaternion Quaternion::operator-(const Quaternion& q) const noexcept
{
    return {v - q.v, s - q.s};
}

inline constexpr Quaternion Quaternion::operator-() const noexcept
{
    return {-v, -s};
}

inline constexpr Quaternion Quaternion::operator*(const Quaternion& q) const noexcept
{
    return {q.v * s + v * q.s + v.cross(q.v), s * q.s - v.dot(q.v)};
}

// The quaternion is assumed normalized
inline constexpr Vec3 Quaternion::operator*(const Vec3& p) const noexcept
{
    return v * (2.f * s * s - 1.f) + v * v.dot(p) + v.cross(p) * (2.f * s);
}

inline constexpr Quaternion Quaternion::operator*(const f32 k) const noexcept
{
    return {v * k, s * k};
}

inline constexpr Quaternion Quaternion::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};

    return {v * reciprocal, s * reciprocal};
}

inline std::ostream& operator<<(std::ostream& os, const Quaternion& q) noexcept
{
    return os << '[' << q.s << ", " << q.v << ']';
}
