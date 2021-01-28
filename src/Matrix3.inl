/* ======== Static methods, pseudo-constructors ======== */
inline constexpr Matrix3 Matrix3::zero() noexcept
{
    return
    {
        .0f, .0f, .0f,
        .0f, .0f, .0f,
        .0f, .0f, .0f
    };
}


inline constexpr Matrix3 Matrix3::identity() noexcept
{
    return
    {
        1.f, .0f, .0f,
        .0f, 1.f, .0f,
        .0f, .0f, 1.f
    };
}




/* =================== Methods =================== */
inline constexpr Matrix3 Matrix3::cofactor() const noexcept
{
    // Repeated values
    return
    {
        (coef[4] * coef[8]) - (coef[7] * coef[5]), (coef[7] * coef[2]) - (coef[1] * coef[8]), (coef[1] * coef[5]) - (coef[4] * coef[2]),
        (coef[6] * coef[5]) - (coef[3] * coef[8]), (coef[0] * coef[8]) - (coef[6] * coef[2]), (coef[3] * coef[2]) - (coef[0] * coef[5]),
        (coef[0] * coef[7]) - (coef[6] * coef[4]), (coef[6] * coef[1]) - (coef[0] * coef[7]), (coef[0] * coef[4]) - (coef[3] * coef[1])
    };
}


inline constexpr Matrix3 Matrix3::transposed() const noexcept
{
    return
    {
        coef[0], coef[3], coef[6],
        coef[1], coef[4], coef[7],
        coef[2], coef[5], coef[8]
    };
}


inline constexpr Matrix3 Matrix3::adjugate() const noexcept
{ return cofactor().transposed(); }


inline constexpr f32 Matrix3::det() const noexcept
{
    return   coef[0] * (coef[4] * coef[8] - coef[7] * coef[5])
           - coef[1] * (coef[3] * coef[8] - coef[6] * coef[5])
           + coef[2] * (coef[3] * coef[7] + coef[6] * coef[4]);
}


inline Matrix3 Matrix3::inversed() const noexcept
{ return adjugate() / det(); }



inline constexpr f32 Matrix3::trace() const noexcept
{ return coef[0] + coef[4] + coef[8]; }



/* ================ Operator overloads ================= */
// This actually does m * *this
inline constexpr Matrix3& Matrix3::operator*=(const Matrix3& m) noexcept
{
    coef[0] = (m.coef[0] * coef[0]) + (m.coef[3] * coef[1]) + (m.coef[6] * coef[2]);
    coef[1] = (m.coef[0] * coef[3]) + (m.coef[3] * coef[4]) + (m.coef[6] * coef[5]);
    coef[2] = (m.coef[0] * coef[6]) + (m.coef[3] * coef[7]) + (m.coef[6] * coef[8]);
    coef[3] = (m.coef[0] * coef[0]) + (m.coef[3] * coef[1]) + (m.coef[6] * coef[2]);
    coef[4] = (m.coef[0] * coef[3]) + (m.coef[3] * coef[4]) + (m.coef[6] * coef[5]);
    coef[5] = (m.coef[0] * coef[6]) + (m.coef[3] * coef[7]) + (m.coef[6] * coef[8]);
    coef[6] = (m.coef[0] * coef[0]) + (m.coef[3] * coef[1]) + (m.coef[6] * coef[2]);
    coef[7] = (m.coef[0] * coef[3]) + (m.coef[3] * coef[4]) + (m.coef[6] * coef[5]);
    coef[8] = (m.coef[0] * coef[6]) + (m.coef[3] * coef[7]) + (m.coef[6] * coef[8]);

    return *this;
}


inline constexpr Matrix3& Matrix3::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};

    coef[0] *= reciprocal;
    coef[1] *= reciprocal;
    coef[2] *= reciprocal;
    coef[3] *= reciprocal;
    coef[4] *= reciprocal;
    coef[5] *= reciprocal;
    coef[6] *= reciprocal;
    coef[7] *= reciprocal;
    coef[8] *= reciprocal;

    return *this;
}


inline constexpr Vec3 Matrix3::operator*(const Vec3& v) const noexcept
{
    return
    {
        (coef[0] * v.x) + (coef[3] * v.y) + (coef[6] * v.z),
        (coef[1] * v.x) + (coef[4] * v.y) + (coef[7] * v.z),
        (coef[2] * v.x) + (coef[5] * v.y) + (coef[8] * v.z)
    };
}


inline Matrix3 Matrix3::operator*(const Matrix3& m) const noexcept
{
    return
    {
        (coef[0] * m.coef[0]) + (coef[3] * m.coef[1]) + (coef[6] * m.coef[2]),
        (coef[0] * m.coef[3]) + (coef[3] * m.coef[4]) + (coef[6] * m.coef[5]),
        (coef[0] * m.coef[6]) + (coef[3] * m.coef[7]) + (coef[6] * m.coef[8]),
        (coef[1] * m.coef[0]) + (coef[4] * m.coef[1]) + (coef[7] * m.coef[2]),
        (coef[1] * m.coef[3]) + (coef[4] * m.coef[4]) + (coef[7] * m.coef[5]),
        (coef[1] * m.coef[6]) + (coef[4] * m.coef[7]) + (coef[7] * m.coef[8]),
        (coef[2] * m.coef[0]) + (coef[5] * m.coef[1]) + (coef[8] * m.coef[2]),
        (coef[2] * m.coef[3]) + (coef[5] * m.coef[4]) + (coef[8] * m.coef[5]),
        (coef[2] * m.coef[6]) + (coef[5] * m.coef[7]) + (coef[8] * m.coef[8])
    };
}


inline Matrix3 Matrix3::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};
    
    return
    {
        coef[0] * reciprocal, coef[1] * reciprocal, coef[2] * reciprocal,
        coef[3] * reciprocal, coef[4] * reciprocal, coef[5] * reciprocal,
        coef[6] * reciprocal, coef[7] * reciprocal, coef[8] * reciprocal
    };
}


inline constexpr f32 Matrix3::operator[](const u8 i) const noexcept
{ return coef[i]; }


inline constexpr f32 Matrix3::operator()(const u8 i, const u8 j) const noexcept
{ return coef[j * MAT3_COL + i]; }


#ifdef _DEBUG
inline std::ostream& operator<<(std::ostream& os, const Matrix3& mat) noexcept
{
    std::streamsize original = std::cout.precision();
    os << std::setprecision(2);

    for (u8 i{0u}; i < MAT3_COL; ++i)
    {
        u8 induction{i};
        
        os << "\n| ";
        for (u8 j{MAT3_COL}; j--; induction += MAT3_COL)
            os << std::setw(6) << mat.coef[induction] << ' ';

        os << " |";
    }

    os << std::setprecision(original);

    return os;
}
#endif