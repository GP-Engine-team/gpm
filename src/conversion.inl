/* ================= Inlined conversion methods ================= */
inline constexpr Mat3 toMatrix3(const Mat4& m) noexcept
{
    return
    {
        m.coef[0], m.coef[1], m.coef[2],
        m.coef[4], m.coef[5], m.coef[6],
        m.coef[8], m.coef[9], m.coef[10]
    };
}


inline constexpr Mat4 toMatrix4(const Mat3& m) noexcept
{
    return
    {
        m.coef[0], m.coef[1], m.coef[2], .0f,
        m.coef[3], m.coef[4], m.coef[5], .0f,
        m.coef[6], m.coef[7], m.coef[8], .0f,
               .0f,      .0f,       .0f, 1.f
    };
}


inline constexpr Mat3 toMatrix3(const Quat& q) noexcept
{
    const float x2{q.x() * q.x()}, y2{q.y() * q.y()}, z2{q.z() * q.z()},
                xy{q.x() * q.y()}, yz{q.y() * q.z()}, xz{q.x() * q.z()},
                wx{q.s * q.x()},   wy{q.s * q.y()},   wz{q.s * q.z()},
                s_2{2.f / q.length2()};

    // Column-major
    return
    {
        1.f - s_2 * (y2 + z2),  s_2 * (xy - wz),        s_2 * (xz + wy),
        s_2 * (xy + wz),        1.f - s_2 * (x2 + z2),  s_2 * (yz - wx),
        s_2 * (xz - wy),        s_2 * (yz + wx),        1.f - s_2 * (x2 + y2)
    };
}


inline constexpr Mat4 toMatrix4(const Quat& q) noexcept
{
    return toMatrix4(toMatrix3(q));
}


inline Quat toQuaternion(const Mat3& m) noexcept
{
    Quat ret;
    const f32 trace = m.trace();

    if (trace > .0f)
    {
        f32 tmp = sqrtf(trace + 1.f);

        ret.s = tmp * .5f;

        tmp = .5f / tmp;

        ret.v.x = (m[5] - m[7]) * tmp;
        ret.v.y = (m[6] - m[2]) * tmp;
        ret.v.z = (m[1] - m[3]) * tmp;
    }

    else
    {
        u8 i = 0;
        if (m[4] > m[0])      i = 1u;
        if (m[8] > m[4u * i]) i = 2u;

        const u8 next[3]    = {1u, 2u, 0u},
                 j          = next[i],
                 k          = next[j];

        f32 tmp = sqrtf((m(i, j) - (m(j, j) + m(k, k))) + 1.f);

        ret[i] = tmp * .5f;

        if (tmp != .0f)
            tmp = .5f / tmp;

        ret.v.z = (m(k, j) - m(j, k)) * tmp;
        ret[j]  = (m(j, i) + m(i, j)) * tmp;
        ret[k]  = (m(k, i) + m(i, k)) * tmp;
    }

    return ret;
}


inline Quat toQuaternion(const Mat4& m) noexcept
{
    return toQuaternion(toMatrix3(m));
}
