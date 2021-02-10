/* ================== SplitTransform static methods ================== */
inline std::ostream& operator<<(std::ostream& os, const SplitTransform& st) noexcept
{
    return os << "rotation: "   << st.rotation
              << "\nposition: " << st.position
              << "\nscale: "    << st.scale;
}




/* ================== Transform static methods ================== */
inline constexpr Mat4 Transform::translation(const Vec3& t) noexcept
{
    return
    {
        1.f, .0f, .0f, .0f,
        .0f, 1.f, .0f, .0f,
        .0f, .0f, 1.f, .0f,
        t.x, t.y, t.z, 1.f
    };
}


inline Mat4 Transform::rotationX(const f32 angle) noexcept
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


inline Mat4 Transform::rotationY(const f32 angle) noexcept
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


inline Mat4 Transform::rotationZ(const f32 angle) noexcept
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


inline Mat4 Transform::rotation(const Vec3& r) noexcept
{
    return rotationY(r.z) * rotationX(r.y) * rotationZ(r.x);
}


inline constexpr Mat4 Transform::scaling(const Vec3& s) noexcept
{
    return
    {
        s.x, .0f, .0f, .0f,
        .0f, s.y, .0f, .0f,
        .0f, .0f, s.z, .0f,
        .0f, .0f, .0f, 1.f,
    };
}


inline Mat4 Transform::TRS(const Vec3& t, const Vec3& r, const Vec3& s) noexcept
{
    return translation(t) * rotation(r) * scaling(s);
}


inline constexpr Mat4 Transform::symFrustrum(const f32 right,
                                             const f32 top,
                                             const f32 near,
                                             const f32 far) noexcept
{
    const f32 depthInv{1.f / (far - near)};

    return
    {
        near / right, .0f,        .0f,                          .0f,
        .0f,          near / top, .0f,                          .0f,
        .0f,          .0f,        -(far + near) * depthInv,    -1.f,
        .0f,          .0f,        -2.f * far * near * depthInv, .0f
    };
}


inline Mat4 Transform::perspective(const f32 fovY,
                                   const f32 aspect,
                                   const f32 near,
                                   const f32 far) noexcept
{
    const f32 top{near * tanf(fovY / 2.f)}, right{top * aspect};

    return symFrustrum(right, top, near, far);
}


inline constexpr Mat4 Transform::viewport(const f32 x,
                                          const f32 y,
                                          const f32 width,
                                          const f32 height) noexcept
{
    const f32 halfWidth{width * .5f}, halfHeight{height * .5f};

    return
    {
        halfWidth,     .0f,            .0f, .0f,
        .0f,           halfHeight,     .0f, .0f,
        .0f,           .0f,            .5f, .0f,
        x + halfWidth, y + halfHeight, .5f, 1.f
    };
}




/* ================== Transform non-static methods ================== */
inline Mat4 Transform::normalMat() const noexcept
{
    return model.cofactor();
}


inline constexpr Vec3 Transform::right() const noexcept
{
    return model.c[0].xyz;
}


inline constexpr Vec3 Transform::up() const noexcept
{
    return  model.c[1].xyz;
}


inline constexpr Vec3 Transform::forward() const noexcept
{
    return  model.c[2].xyz;
}


inline constexpr Vec3 Transform::translation() const noexcept
{
    return  model.c[3].xyz;
}


inline Mat4 Transform::rotation() const noexcept
{
    const Vec3 invScale{1.f / right().length(), 1.f / up().length(), 1.f / forward().length()};

    return
    {
        {model.c[0].xyz * invScale.x, .0f},
        {model.c[1].xyz * invScale.y, .0f},
        {model.c[2].xyz * invScale.x, .0f},
        {Vec3::zero(),                .0f}
    };
}


inline Vec3 Transform::scaling() const noexcept
{
    return {right().length(), up().length(), forward().length()};
}



// Transformations
inline constexpr void Transform::translate(const Vec3& t) noexcept
{
    model.e[12] = t.x * model.e[0] + t.y * model.e[4] + t.z * model.e[8]  + model.e[12];
    model.e[13] = t.x * model.e[1] + t.y * model.e[5] + t.z * model.e[9]  + model.e[13];
    model.e[14] = t.x * model.e[2] + t.y * model.e[6] + t.z * model.e[10] + model.e[14];
}


inline void Transform::rotateX(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    model.e[4]  = (model.e[4]  * cosAngle) + (model.e[8]  * sinAngle);
    model.e[5]  = (model.e[5]  * cosAngle) + (model.e[9]  * sinAngle);
    model.e[6]  = (model.e[6]  * cosAngle) + (model.e[10] * sinAngle);
    model.e[8]  = (model.e[8]  * cosAngle) - (model.e[4]  * sinAngle);
    model.e[9]  = (model.e[9]  * cosAngle) - (model.e[5]  * sinAngle);
    model.e[10] = (model.e[10] * cosAngle) - (model.e[6]  * sinAngle);
}

inline void Transform::rotateY(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    model.e[0]  = (model.e[0]  * cosAngle) - (model.e[8]  * sinAngle);
    model.e[1]  = (model.e[1]  * cosAngle) - (model.e[9]  * sinAngle);
    model.e[2]  = (model.e[2]  * cosAngle) - (model.e[10] * sinAngle);
    model.e[8]  = (model.e[8]  * cosAngle) + (model.e[0]  * sinAngle);
    model.e[9]  = (model.e[9]  * cosAngle) + (model.e[1]  * sinAngle);
    model.e[10] = (model.e[10] * cosAngle) + (model.e[2]  * sinAngle);
}


inline void Transform::rotateZ(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    model.e[0] = (model.e[0] * cosAngle) + (model.e[4] * sinAngle);
    model.e[1] = (model.e[1] * cosAngle) + (model.e[5] * sinAngle);
    model.e[2] = (model.e[2] * cosAngle) + (model.e[6] * sinAngle);
    model.e[4] = (model.e[4] * cosAngle) - (model.e[0] * sinAngle);
    model.e[5] = (model.e[5] * cosAngle) - (model.e[1] * sinAngle);
    model.e[6] = (model.e[6] * cosAngle) - (model.e[2] * sinAngle);
}


inline void Transform::rotate(const Vec3& r) noexcept
{
    const Mat4 rot{rotation(r)};

    model.e[0]  = (model.e[0] * rot.e[0]) + (model.e[4] * rot.e[1]) + (model.e[8]  * rot.e[2]);
    model.e[1]  = (model.e[1] * rot.e[0]) + (model.e[5] * rot.e[1]) + (model.e[9]  * rot.e[2]);
    model.e[2]  = (model.e[2] * rot.e[0]) + (model.e[6] * rot.e[1]) + (model.e[10] * rot.e[2]);
    model.e[4]  = (model.e[0] * rot.e[4]) + (model.e[4] * rot.e[5]) + (model.e[8]  * rot.e[6]);
    model.e[5]  = (model.e[1] * rot.e[4]) + (model.e[5] * rot.e[5]) + (model.e[9]  * rot.e[6]);
    model.e[6]  = (model.e[2] * rot.e[4]) + (model.e[6] * rot.e[5]) + (model.e[10] * rot.e[6]);
    model.e[8]  = (model.e[0] * rot.e[8]) + (model.e[4] * rot.e[9]) + (model.e[8]  * rot.e[10]);
    model.e[9]  = (model.e[1] * rot.e[8]) + (model.e[5] * rot.e[9]) + (model.e[9]  * rot.e[10]);
    model.e[10] = (model.e[2] * rot.e[8]) + (model.e[6] * rot.e[9]) + (model.e[10] * rot.e[10]);
}


inline constexpr void Transform::scale(const Vec3& s) noexcept
{
    model.e[0]  *= s.x;
    model.e[5]  *= s.y;
    model.e[10] *= s.z;
}


inline constexpr void Transform::apply(const Mat4& m) noexcept
{
    model *= m;
}




// Utility
inline std::ostream& operator<<(std::ostream& os, const Transform& t) noexcept
{ return os << t.model; }