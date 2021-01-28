/* =================== Static methods (pseudo-constructors) =================== */
inline constexpr Vector3 Vector3::zero() noexcept
{ return {.0f, .0f, .0f}; }


inline constexpr Vector3 Vector3::one() noexcept
{ return {1.f, 1.f, 1.f}; }


inline constexpr Vector3 Vector3::left() noexcept
{ return {1.f, .0f, .0f}; }


inline constexpr Vector3 Vector3::up() noexcept
{ return {.0f, 1.f, .0f}; }


inline constexpr Vector3 Vector3::forward() noexcept
{ return {.0f, .0f, 1.f}; }




/* =================== Methods =================== */
inline constexpr f32 Vector3::length2() const noexcept
{ return (x * x) + (y * y) + (z * z); }


inline f32 Vector3::length() const noexcept
{ return sqrtf(length2()); }


inline constexpr f32 Vector3::dot(const Vector3& v) const noexcept
{ return (x * v.x) + (y * v.y) + (z * v.z); }


inline constexpr Vector3 Vector3::cross(const Vector3& v) const noexcept
{
    return {(v.z * y) - (z * v.y),
            (v.x * z) - (x * v.z),
            (v.y * x) - (y * v.x)};
}


inline constexpr bool Vector3::isNull() const noexcept
{ return !x && !y && !z; }


inline constexpr bool Vector3::isOrthogonalTo(const Vector3& v) const noexcept
{ return !dot(v); }


inline constexpr bool Vector3::isNormalized() const noexcept
{ return !(length2() - 1.f); }


inline constexpr bool Vector3::isOrthonormalTo(const Vector3& v) const noexcept
{ return !dot(v) && isNormalized() && v.isNormalized(); }


inline constexpr bool Vector3::isColinearTo(const Vector3& v) const noexcept
{ return cross(v).isNull(); }


inline bool Vector3::isEqualTo(const Vector3& v, const f32 eps) const noexcept
{ return fabs(x - v.x) <= eps && fabs(y - v.y) <= eps && fabs(z - v.z) <= eps; }


inline bool Vector3::isNotEqualTo(const Vector3& v, const f32 eps) const noexcept
{ return fabs(x - v.x) > eps || fabs(y - v.y) > eps || fabs(z - v.z) > eps; }


inline void Vector3::normalize() noexcept
{
    const f32 reciprocal{1.f / length()};

    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;
}


inline constexpr f32 Vector3::distance2To(const Vector3& v) const noexcept
{ return (*this - v).length2(); }


inline f32 Vector3::distanceTo(const Vector3& v) const noexcept
{ return (*this - v).length(); }


inline f32 Vector3::angleWithUnitary(const Vector3& v) const noexcept
{ return acosf(dot(v) / length()); }


inline f32 Vector3::angleWith(const Vector3& v) const noexcept
{ return acosf(dot(v) / sqrtf(length2() * v.length2())); }


inline f32 Vector3::triangleArea(const Vector3& v) const noexcept
{ return cross(v).length() * .5f; }


inline constexpr Vector3 Vector3::projectedOnUnitary(const Vector3& v) const noexcept
{ return v * dot(v); }


inline constexpr Vector3 Vector3::projectedOn(const Vector3& v) const noexcept
{ return v * (dot(v) / v.length2()); }



inline Vector3 Vector3::normalized() const noexcept
{
    const f32 reciprocal{1.f / length()};

    return {x * reciprocal, y * reciprocal, z * reciprocal};
}


// Rodriguez rotation around v, by angle radians
inline Vector3 Vector3::rotatedAroundUnitary(const Vector3& v, const f32 angle) const noexcept
{
	const Vector3   cp{v.cross(*this)};
	const f32	    cosAngle{cosf(angle)}, dp{dot(v)};

    return (*this * cosAngle) + (cp * sinf(angle)) + v * (dp * (1.f - cosAngle));
}


inline Vector3 Vector3::rotatedAround(const Vector3& v, const f32 angle) const noexcept
{ return rotatedAroundUnitary(v.normalized(), angle); }


inline constexpr Vector3 Vector3::lerp(const Vector3& v, const f32 t) const noexcept
{
    const f32 tmp{1.f - t};

    return {(x * tmp) + (v.x * t), (y * tmp) + (v.y * t), (z * tmp) + (v.z * t)};
}



inline constexpr Vector3& Vector3::operator+=(const Vector3& v) noexcept
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator+=(const Vector3&& v) noexcept
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator-=(const Vector3& v) noexcept
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator-=(const Vector3&& v) noexcept
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}


inline constexpr Vector3& Vector3::operator*=(const Vector3& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator*=(const Vector3&& v) noexcept
{
    x *= v.x;
    y *= v.y;
    z *= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const Vector3& v) noexcept
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const Vector3&& v) noexcept
{
    x /= v.x;
    y /= v.y;
    z /= v.z;

    return *this;
}


inline constexpr Vector3& Vector3::operator*=(const f32 k) noexcept
{
    x *= k;
    y *= k;
    z *= k;

    return *this;
}


inline constexpr Vector3& Vector3::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};
    
    x *= reciprocal;
    y *= reciprocal;
    z *= reciprocal;

    return *this;
}


inline constexpr Vector3 Vector3::operator+(const Vector3& v) const noexcept
{ return {x + v.x, y + v.y, z + v.z}; }


inline constexpr Vector3 Vector3::operator+(const Vector3&& v) const noexcept
{ return {x + v.x, y + v.y, z + v.z}; }


inline constexpr Vector3 Vector3::operator-(const Vector3& v)	const noexcept
{ return {x - v.x, y - v.y, z - v.z}; }


inline constexpr Vector3 Vector3::operator-(const Vector3&& v) const noexcept
{ return {x - v.x, y - v.y, z - v.z}; }


inline constexpr Vector3 Vector3::operator-() const noexcept
{ return {-x, -y, -z}; }


inline constexpr Vector3 Vector3::operator*(const Vector3& v) const noexcept
{ return {x * v.x, y * v.y, z * v.z}; }


inline constexpr Vector3 Vector3::operator*(const Vector3&& v) const noexcept
{ return {x * v.x, y * v.y, z * v.z}; }


inline constexpr Vector3 Vector3::operator/(const Vector3& v) const noexcept
{ return {x / v.x, y / v.y, z / v.z}; }


inline constexpr Vector3 Vector3::operator/(const Vector3&& v) const noexcept
{ return {x / v.x, y / v.y, z / v.z}; }


inline constexpr Vector3 Vector3::operator*(const f32 k) const noexcept
{ return {x * k, y * k, z * k}; }


inline constexpr Vector3 Vector3::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};

    return {x * reciprocal, y * reciprocal, z * reciprocal};
}


#ifdef _DEBUG
inline std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept
{ return os << '[' << v.x << ", " << v.y << ", " << v.z << ']'; }
#endif