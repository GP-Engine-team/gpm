/* =================== Constructors =================== */
inline constexpr Vector4::Vector4(const f32 k) noexcept
    : x{k}, y{k}, z{k}, w{k}
{}


inline constexpr Vector4::Vector4(const f32 x, const f32 y, const f32 z, const f32 w_) noexcept
    : xyz{x, y, z}, w{w_}
{}


inline constexpr Vector4::Vector4(const Vec2& v, const f32 z_, const f32 w_) noexcept
    : xy{v}, z{z_}, w{w_}
{}


inline constexpr Vector4::Vector4(const Vec3& v, const f32 w_) noexcept
    : xyz{v}, w{w_}
{}


inline constexpr Vector4::Vector4(const f32 coef[4]) noexcept
    : e{coef[0], coef[1], coef[2], coef[3]}
{}




/* =================== Methods =================== */
inline constexpr Vector4 Vector4::homogenized() const noexcept
{ return {xyz / w}; }


inline constexpr void Vector4::homogenize() noexcept
{
    xyz /= w;
    w = 1.f;
}




/* =================== Operator overloads =================== */
inline constexpr Vector4& Vector4::operator*=(const Vector4& v) noexcept
{
    xyz = xyz * v.xyz;
    w  *= v.w;

    return *this;
}


inline constexpr Vector4 Vector4::operator*(const Vector4& v) const noexcept
{ return {xyz * v.xyz, w * v.w}; }


inline constexpr Vector4 Vector4::operator/(const Vector4& v) const noexcept
{ return {xyz / v.xyz, w / v.w}; }


inline constexpr Vector4 Vector4::operator*(const f32 k) const noexcept
{ return {xyz * k, w * k}; }


inline constexpr Vector4 Vector4::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};
    return {xyz * reciprocal, w * reciprocal};
}


inline std::ostream& operator<<(std::ostream& os, const Vector4& v) noexcept
{ return os << '[' << v.xyz.x << ", " << v.xyz.y << ", " << v.xyz.z << ", " << v.w << ']'; }