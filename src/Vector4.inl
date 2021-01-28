/* =================== Constructors =================== */
inline constexpr Vector4::Vector4(const Vec3& v, const f32 w_) noexcept
    : xyz{v}, w{w_}
{}


inline constexpr Vector4::Vector4(const f32 x, const f32 y, const f32 z, const f32 w_) noexcept
    : xyz{x, y, z}, w{w_}
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
