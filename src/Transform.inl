inline constexpr Mat4 translation(const Vec3& t) noexcept
{
    return
    {
        1.f, .0f, .0f, .0f,
        .0f, 1.f, .0f, .0f,
        .0f, .0f, 1.f, .0f,
        t.x, t.y, t.z, 1.f
    };
}


inline Mat4 rotationX(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    return
    {
        1.f,    .0f,        .0f,       .0f,
        .0f,    cosAngle,   sinAngle,  .0f,
        .0f,    -sinAngle,  cosAngle,  .0f,
        .0f,    .0f,        .0f,       1.f
    };
}


inline Mat4 rotationY(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    return
    {
        cosAngle,   .0f,    -sinAngle,  .0f,
        .0f,        1.f,    .0f,        .0f,
        sinAngle,   .0f,    cosAngle,   .0f,
        .0f,        .0f,    .0f,        1.f
    };
}


inline Mat4 rotationZ(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    return
    {
        cosAngle,   sinAngle,   .0f,    .0f,
        -sinAngle,  cosAngle,   .0f,    .0f,
        .0f,        .0f,        1.f,    .0f,
        .0f,        .0f,        .0f,    1.f
    };
}


inline Mat4 rotation(const Vec3& r) noexcept
{
    return rotationY(r.z) * rotationX(r.y) * rotationZ(r.x);
}


inline constexpr Mat4 scaling(const Vec3& s) noexcept
{
    return
    {
        s.x, .0f, .0f, .0f,
        .0f, s.y, .0f, .0f,
        .0f, .0f, s.z, .0f,
        .0f, .0f, .0f, 1.f,
    };
}


inline Mat4 TRS(const Vec3& t, const Vec3& r, const Vec3& s) noexcept
{
    return translation(t) * rotation(r) * scaling(s);
}


inline Mat4 normalMat(const Mat4& m) noexcept
{
    return m.cofactor();
}


inline constexpr Vec3 right(const Mat4& m) noexcept
{
    return {m.coef[0], m.coef[1], m.coef[2]};
}


inline constexpr Vec3 up(const Mat4& m) noexcept
{
    return {m.coef[4], m.coef[5], m.coef[6]};
}


inline constexpr Vec3 forward(const Mat4& m) noexcept
{
    return {m.coef[8], m.coef[9], m.coef[10]};
}


inline constexpr Vec3 position(const Mat4& m) noexcept
{
    return {m.coef[12], m.coef[13], m.coef[14]};
}


inline constexpr Mat4 symFrustrum(const f32 right,
                                  const f32 top,
                                  const f32 near,
                                  const f32 far) noexcept
{
    const f32 depthInv{1.f / (far - near)};

    return
    {
        near / right,        .0f, .0f,                          .0f,
        .0f,          near / top, .0f,                          .0f,
        .0f,                 .0f, -(far + near) * depthInv,    -1.f,
        .0f,                 .0f, -2.f * far * near * depthInv, .0f
    };
}


inline Mat4 perspective(const f32 fovY,
                                  const f32 aspect,
                                  const f32 near,
                                  const f32 far) noexcept
{
    const f32 top{near * tanf(fovY / 2.f)}, right{top * aspect};

    return symFrustrum(right, top, near, far);
}


inline constexpr Mat4 viewport(const f32 x,
                               const f32 y,
                               const f32 width,
                               const f32 height) noexcept
{
    const f32 halfWidth{width * .5f}, halfHeight{height * .5f};

    return
    {
        halfWidth    , .0f           , .0f, .0f,
        .0f          , halfHeight    , .0f, .0f,
        .0f          , .0f           , .5f, .0f,
        x + halfWidth, y + halfHeight, .5f, 1.f
    };
}