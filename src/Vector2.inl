/* =================== Static methods (pseudo-constructors) =================== */
inline constexpr Vector2 Vector2::zero() noexcept
{ return {.0f, .0f}; }


inline constexpr Vector2 Vector2::right() noexcept
{ return {1.f, .0f}; }


inline constexpr Vector2 Vector2::up() noexcept
{ return {.0f, 1.f}; }




/* =================== Methods =================== */
inline constexpr f32 Vector2::length2() const noexcept
{ return (x * x) + (y * y); }


inline f32 Vector2::length() const noexcept
{ return sqrtf(length2()); }


inline constexpr f32 Vector2::dot(const Vector2& v) const noexcept
{ return (x * v.x) + (y * v.y); }


inline constexpr f32 Vector2::cross(const Vector2& v) const noexcept
{ return (x * v.y) - (y * v.x); }


inline constexpr bool Vector2::isNull() const noexcept
{ return !x && !y; }


inline constexpr bool Vector2::isOrthogonalTo(const Vector2& v) const noexcept
{ return !dot(v); }


inline constexpr bool Vector2::isNormalized() const noexcept
{ return !(length2() - 1.f); }


inline constexpr bool Vector2::isOrthonormalTo(const Vector2& v) const noexcept
{ return !dot(v) && isNormalized() && v.isNormalized(); }


inline constexpr bool Vector2::isColinearTo(const Vector2& v) const noexcept
{ return !cross(v); }


inline bool Vector2::isEqualTo(const Vector2& v, const f32 eps) const noexcept
{ return fabs(x - v.x) <= eps && fabs(y - v.y) <= eps; }


inline bool Vector2::isNotEqualTo(const Vector2& v, const f32 eps) const noexcept
{ return fabs(x - v.x) > eps || fabs(y - v.y) > eps; }


inline void Vector2::normalize() noexcept
{
	const f32 reciprocal{1.f / length()};
	x *= reciprocal;
	y *= reciprocal;
}


inline constexpr f32 Vector2::distance2To(const Vector2& v) const noexcept
{ return (*this - v).length2(); }


inline f32 Vector2::distanceTo(const Vector2& v) const noexcept
{ return (*this - v).length(); }


inline f32 Vector2::angleWithUnitary(const Vector2& v) const noexcept
{ return acosf(dot(v) / length()); }


inline f32 Vector2::angleWith(const Vector2& v) const noexcept
{ return acosf(dot(v) / sqrtf(length2() * v.length2())); }


inline constexpr f32 Vector2::triangleArea(const Vector2& v) const noexcept
{ return cross(v) * .5f; }


inline constexpr Vector2 Vector2::projectedOnUnitary(const Vector2& v) const noexcept
{ return v * dot(v); }


inline constexpr Vector2 Vector2::projectedOn(const Vector2& v) const noexcept
{ return v * (dot(v) / v.length2()); }


inline Vector2 Vector2::normalized() const noexcept
{ return *this / length(); }


inline Vector2 Vector2::rotated(const f32 angle) const noexcept
{
	const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

	return {(cosAngle * x) - (sinAngle * y), (sinAngle * x) + (cosAngle * y)};
}


inline constexpr Vector2 Vector2::rotated90() const noexcept
{ return {y, -x}; }


inline constexpr Vector2 Vector2::lerp(const Vector2& v, const f32 t) const noexcept
{
	const f32 tmp{1.f - t};

    return {(x * tmp) + (v.x * t), (y * tmp) + (v.y * t)};
}


inline constexpr Vector2& Vector2::operator+=(const Vector2& v) noexcept
{
	x += v.x;
	y += v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator+=(const Vector2&& v) noexcept
{
	x += v.x;
	y += v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator-=(const Vector2& v) noexcept
{
	x -= v.x;
	y -= v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator-=(const Vector2&& v) noexcept
{
	x -= v.x;
	y -= v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator*=(const Vector2& v) noexcept
{
	x *= v.x;
	y *= v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator*=(const Vector2&& v) noexcept
{
	x *= v.x;
	y *= v.y;

	return *this;
}


inline constexpr Vector2& Vector2::operator/=(const Vector2& v) noexcept
{
	const f32 reciprocal{1.f / (v.x * v.y)};

	x *= v.y * reciprocal;
	y *= v.x * reciprocal;

	return *this;
}


inline constexpr Vector2& Vector2::operator/=(const Vector2&& v) noexcept
{
	const f32 reciprocal{1.f / (v.x * v.y)};
	x *= v.y * reciprocal;
	y *= v.x * reciprocal;

	return *this;
}


inline constexpr Vector2& Vector2::operator*=(const f32 k) noexcept
{
	x *= k;
	y *= k;

	return *this;
}


inline constexpr Vector2& Vector2::operator/=(const f32 k) noexcept
{
	const f32 reciprocal{1.f / k};

	x *= reciprocal;
	y *= reciprocal;

	return *this;
}


inline constexpr Vector2 Vector2::operator+(const Vector2& v) const noexcept
{ return {x + v.x, y + v.y}; }


inline constexpr Vector2 Vector2::operator+(const Vector2&& v) const noexcept
{ return {x + v.x, y + v.y}; }


inline constexpr Vector2 Vector2::operator*(const Vector2& v) const noexcept
{ return {x * v.x, y * v.y}; }


inline constexpr Vector2 Vector2::operator*(const Vector2&& v) const noexcept
{ return {x * v.x, y * v.y}; }


inline constexpr Vector2 Vector2::operator/(const Vector2& v) const noexcept
{
	const f32 reciprocal{1.f / (v.x * v.y)};

	return {x * v.y * reciprocal, y * v.x * reciprocal};
}


inline constexpr Vector2 Vector2::operator/(const Vector2&& v) const noexcept
{
	const f32 reciprocal{1.f / (v.x * v.y)};

	return {x * v.y * reciprocal, y * v.x * reciprocal};
}


inline constexpr Vector2 Vector2::operator-() const noexcept
{ return {-x, -y}; }


inline constexpr Vector2 Vector2::operator-(const Vector2& v) const noexcept
{ return {x - v.x, y - v.y}; }


inline constexpr Vector2 Vector2::operator-(const Vector2&& v) const noexcept
{ return {x - v.x, y - v.y}; }


inline constexpr Vector2 Vector2::operator*(const f32 k) const noexcept
{ return {x * k, y * k}; }


inline constexpr Vector2 Vector2::operator/(const f32 k) const noexcept
{
	const f32 reciprocal{1.f / k};

	return {x * reciprocal, y * reciprocal};
}

#ifdef _DEBUG
inline std::ostream& operator<<(std::ostream& os, const Vector2& v) noexcept
{ return os << '[' << v.x << ", " << v.y << ']'; }
#endif