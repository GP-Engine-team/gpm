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


// Y * X * Z
inline Mat4 Transform::rotation(const Vec3& r) noexcept
{
    const f32 cx{cosf(r.x)}, sx{sinf(r.x)},
              cy{cosf(r.y)}, sy{sinf(r.y)},
              cz{cosf(r.z)}, sz{sinf(r.z)};

    return
    {
        cy * cz + sx * sy * sz, cx * sz, sx * cy * sz - sy * cz, .0f,
        sx * sy * cz - cy * sz, cx * cz, sy * sz + sx * cy * cz, .0f,
        cx * sy,                -sx,     cx * cy,                .0f,
        .0f,                    .0f,     .0f,                    1.f
    };
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


// With OpenGL, the camera looks towards negative z  
inline Mat4 Transform::lookAt(const Vec3& eyePos,
                              const Vec3& targetPos,
                              const Vec3& normalizedUp) noexcept
{
    const Vec4 forward{(eyePos - targetPos).normalized(), .0f},
               right  {normalizedUp.cross(forward.xyz),   .0f},
               up     {forward.xyz.cross(right.xyz),      .0f};

    return {right, up, forward, eyePos};
}


inline constexpr Mat4 Transform::symFrustrum(const f32 right, const f32 top,
                                             const f32 near,  const f32 far) noexcept
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


inline Mat4 Transform::perspective(const f32 fovY, const f32 aspect,
                                   const f32 near, const f32 far) noexcept
{
    const f32 top{near * tanf(fovY / 2.f)}, right{top * aspect};

    return symFrustrum(right, top, near, far);
}


inline constexpr Mat4 Transform::orthographic(const f32 right, const f32 top,
                                              const f32 near,  const f32 far) noexcept
{
    const f32 farMinNear{far - near};

    return
    {
        1.f / right, .0f,       .0f,                          .0f,
        .0f,         1.f / top, .0f,                          .0f,
        .0f,         .0f,       -2.f / (far - near),          .0f,
        .0f,         .0f,       (far + near) / (-farMinNear), 1.f
    };
}


inline constexpr Mat4 Transform::viewport(const f32 x,     const f32 y,
                                          const f32 width, const f32 height) noexcept
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




/* ================== Transform constructor ================== */
inline Transform::Transform(const Vec3& t, const Vec3& r, const Vec3& s) noexcept
{
    scale(s);
    rotate(r);
    translate(t);
}


inline constexpr Transform::Transform(const Mat4& m) noexcept
    : model{m}
{}




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
    return model.c[1].xyz;
}


inline constexpr Vec3 Transform::forward() const noexcept
{
    return model.c[2].xyz;
}


inline constexpr Vec3 Transform::translation() const noexcept
{
    return model.c[3].xyz;
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


inline Vec3 Transform::eulerAngles() const noexcept
{
    if (model.e[9] < 1.f)
    {
        if (model.e[9] > -1.f)
        {
            return
            {
                asinf(-model.e[9]),
                atan2f(model.e[8], model.e[10]),
                atan2f(model.e[1], model.e[5])
            };
        }

        return {HALF_PI, -atan2f(-model.e[4], model.e[0]), .0f};
    }

    return {-HALF_PI, atan2f(-model.e[4], model.e[0]), .0f};
}


inline Vec3 Transform::scaling() const noexcept
{
    return {right().length(), up().length(), forward().length()};
}



// Transformations
inline constexpr void Transform::translateX(const f32 shift) noexcept
{
    model.e[12] += shift * model.e[0];
    model.e[13] += shift * model.e[1];
    model.e[14] += shift * model.e[2];
}


inline constexpr void Transform::translateY(const f32 shift) noexcept
{
    model.e[12] += shift * model.e[4];
    model.e[13] += shift * model.e[5];
    model.e[14] += shift * model.e[6];
}


inline constexpr void Transform::translateZ(const f32 shift) noexcept
{
    model.e[12] += shift * model.e[8];
    model.e[13] += shift * model.e[9];
    model.e[14] += shift * model.e[10];
}


inline constexpr void Transform::translate(const Vec3& t) noexcept
{
    model.e[12] += t.x * model.e[0] + t.y * model.e[4] + t.z * model.e[8];
    model.e[13] += t.x * model.e[1] + t.y * model.e[5] + t.z * model.e[9];
    model.e[14] += t.x * model.e[2] + t.y * model.e[6] + t.z * model.e[10];
}


inline void Transform::rotateX(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    f32 tmp1{(model.e[1]  * cosAngle) - (model.e[2]  * sinAngle)},
        tmp2{(model.e[1]  * sinAngle) + (model.e[2]  * cosAngle)};
    model.e[1]  = tmp1;
    model.e[2]  = tmp2;

    tmp1 = (model.e[5]  * cosAngle) - (model.e[6]  * sinAngle);
    tmp2 = (model.e[5]  * sinAngle) + (model.e[6]  * cosAngle);
    model.e[5]  = tmp1;
    model.e[6]  = tmp2;

    tmp1 = (model.e[9]  * cosAngle) - (model.e[10] * sinAngle);
    tmp2 = (model.e[9]  * sinAngle) + (model.e[10] * cosAngle);
    model.e[9]  = tmp1;
    model.e[10] = tmp2;

    tmp1 = (model.e[13] * cosAngle) - (model.e[14] * sinAngle);
    tmp2 = (model.e[13] * sinAngle) + (model.e[14] * cosAngle);
    model.e[13] = tmp1;
    model.e[14] = tmp2;
}


inline void Transform::rotateY(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};

    f32 tmp1{(model.e[0]  * cosAngle) + (model.e[2]  * sinAngle)},
        tmp2{(model.e[2]  * cosAngle) - (model.e[0]  * sinAngle)};
    model.e[0]  = tmp1;
    model.e[2]  = tmp2;

    tmp1 = (model.e[4]  * cosAngle) + (model.e[6]  * sinAngle);
    tmp2 = (model.e[6]  * cosAngle) - (model.e[4]  * sinAngle);
    model.e[4]  = tmp1;
    model.e[6]  = tmp2;

    tmp1 = (model.e[8]  * cosAngle) + (model.e[10] * sinAngle);
    tmp2 = (model.e[10] * cosAngle) - (model.e[8]  * sinAngle);
    model.e[8]  = tmp1;
    model.e[10] = tmp2;

    tmp1 = (model.e[12] * cosAngle) + (model.e[14] * sinAngle);
    tmp2 = (model.e[14] * cosAngle) - (model.e[12] * sinAngle);
    model.e[12] = tmp1;
    model.e[14] = tmp2;
}


inline void Transform::rotateZ(const f32 angle) noexcept
{
    const f32 cosAngle{cosf(angle)}, sinAngle{sinf(angle)};
    f32 tmp1{(model.e[0]  * cosAngle) - (model.e[1]  * sinAngle)},
        tmp2{(model.e[0]  * sinAngle) + (model.e[1]  * cosAngle)};
    model.e[0]  = tmp1;
    model.e[1]  = tmp2;

    tmp1 = (model.e[4]  * cosAngle) - (model.e[5]  * sinAngle);
    tmp2 = (model.e[4]  * sinAngle) + (model.e[5]  * cosAngle);
    model.e[4]  = tmp1;
    model.e[5]  = tmp2;

    tmp1 = (model.e[8]  * cosAngle) - (model.e[9]  * sinAngle);
    tmp2 = (model.e[8]  * sinAngle) + (model.e[9]  * cosAngle);
    model.e[8]  = tmp1;
    model.e[9]  = tmp2;

    tmp1 = (model.e[12] * cosAngle) - (model.e[13] * sinAngle);
    tmp2 = (model.e[12] * sinAngle) + (model.e[13] * cosAngle);
    model.e[12] = tmp1;
    model.e[13] = tmp2;
}


inline void Transform::rotate(const Vec3& r) noexcept
{
    const Mat4 rot{rotation(r)};

    f32 tmp1{model.e[0]}, tmp2{model.e[1]};
    model.e[0]  = (tmp1 * rot.e[0]) + (tmp2 * rot.e[4]) + (model.e[2]  * rot.e[8]);
    model.e[1]  = (tmp1 * rot.e[1]) + (tmp2 * rot.e[5]) + (model.e[2]  * rot.e[9]);
    model.e[2]  = (tmp1 * rot.e[2]) + (tmp2 * rot.e[6]) + (model.e[2]  * rot.e[10]);

    tmp1 = model.e[4];
    tmp2 = model.e[5];
    model.e[4]  = (tmp1 * rot.e[0]) + (tmp2 * rot.e[4]) + (model.e[6]  * rot.e[8]);
    model.e[5]  = (tmp1 * rot.e[1]) + (tmp2 * rot.e[5]) + (model.e[6]  * rot.e[9]);
    model.e[6]  = (tmp1 * rot.e[2]) + (tmp2 * rot.e[6]) + (model.e[6]  * rot.e[10]);
    
    tmp1 = model.e[8];
    tmp2 = model.e[9];
    model.e[8]  = (tmp1 * rot.e[0]) + (tmp2 * rot.e[4]) + (model.e[10] * rot.e[8]);
    model.e[9]  = (tmp1 * rot.e[1]) + (tmp2 * rot.e[5]) + (model.e[10] * rot.e[9]);
    model.e[10] = (tmp1 * rot.e[2]) + (tmp2 * rot.e[6]) + (model.e[10] * rot.e[10]);
}


inline constexpr void Transform::scaleX(const f32 coef) noexcept
{
    model.e[0]  *= coef;
    model.e[4]  *= coef;
    model.e[8]  *= coef;
    model.e[12] *= coef;
}


inline constexpr void Transform::scaleY(const f32 coef) noexcept
{
    model.e[1]  *= coef;
    model.e[5]  *= coef;
    model.e[9]  *= coef;
    model.e[13] *= coef;
}


inline constexpr void Transform::scaleZ(const f32 coef) noexcept
{
    model.e[2]  *= coef;
    model.e[6]  *= coef;
    model.e[10] *= coef;
    model.e[14] *= coef;
}


inline constexpr void Transform::scale(const Vec3& s) noexcept
{
    model.c[0].xyz *= s;
    model.c[1].xyz *= s;
    model.c[2].xyz *= s;
    model.c[3].xyz *= s;
}


inline void Transform::lookAt(const Vec3& targetPos) noexcept
{
    const Vec3 s{scaling()};

    model.c[2] = {(model.c[3].xyz - targetPos).normalized() * s, .0f};
    model.c[0] = {model.c[1].xyz.cross(model.c[2].xyz) * s,      .0f};
    model.c[1] = {model.c[2].xyz.cross(model.c[0].xyz) * s,      .0f};
}


inline void Transform::apply(const Vec3& t, const Vec3& r, const Vec3& s) noexcept
{
    scale(s);
    rotate(r);
    translate(t);
}


inline constexpr void Transform::apply(const Mat4& m) noexcept
{
    model *= m;
}




// Utility
inline std::ostream& operator<<(std::ostream& os, const Transform& t) noexcept
{ return os << t.model; }