/* ======== Static methods, pseudo-constructors ======== */
inline constexpr Matrix4 Matrix4::zero() noexcept
{
    return
    {
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
        .0f, .0f, .0f, .0f,
    };
}


inline constexpr Matrix4 Matrix4::identity() noexcept
{
    return
    {
        1.f, .0f, .0f, .0f,
        .0f, 1.f, .0f, .0f,
        .0f, .0f, 1.f, .0f,
        .0f, .0f, .0f, 1.f,
    };
}




/* =================== Methods =================== */
inline Matrix4 Matrix4::cofactor() const noexcept
{
    // Repeated values
    const f32 a22a33{coef[5]  * coef[10]}, a23a34{coef[9]  * coef[14]}, a24a32{coef[13] * coef[6]},
              a24a33{coef[13] * coef[10]}, a23a32{coef[9]  * coef[6]},  a22a34{coef[5]  * coef[14]},
              a33a42{coef[10] * coef[7]},  a32a44{coef[6]  * coef[15]}, a34a43{coef[14] * coef[11]},
              a33a44{coef[10] * coef[15]}, a32a42{coef[14] * coef[7]},  a32a43{coef[6]  * coef[11]},
              a12a23{coef[4]  * coef[9]},  a13a24{coef[8]  * coef[13]}, a14a22{coef[12] * coef[5]},
              a14a23{coef[12] * coef[9]},  a13a22{coef[8]  * coef[5]},  a12a24{coef[4]  * coef[13]},
              a31a44{coef[2]  * coef[15]}, a31a43{coef[2]  * coef[11]}, a13a21{coef[8]  * coef[1]},
              a14a21{coef[12] * coef[1]},  a31a42{coef[2]  * coef[7]},  a11a24{coef[0] * coef[13]},
              a12a21{coef[4] * coef[1]},   a34a41{coef[14] * coef[3]},  a33a41{coef[10] * coef[3]},
              a32a41{coef[6] * coef[3]},   a11a23{coef[0] * coef[9]},   a11a22{coef[0] * coef[5]};

    return
    {
        (a22a33 * coef[15]) + (a23a34 * coef[7]) + (a24a32 * coef[11])
        - (a24a33 * coef[7])- (a23a32 * coef[15]) - (a22a34 * coef[11]),
        (coef[12] * a33a42) + (coef[8] * a32a44) + (coef[4] * a34a43)
        - (coef[4] * a33a44) - (coef[8] * a32a42) - (coef[12] * a32a43),
        (a12a23 * coef[15]) + (a13a24 * coef[7]) + (a14a22 * coef[11])
        - (a14a23 * coef[7]) - (a13a22 * coef[15]) - (a12a24 * coef[11]),
        (coef[12] * a23a32) + (coef[8] * a22a34) + (coef[4] * a24a33)
        - (coef[4] * a23a34) - (coef[8] * a24a32) - (coef[12] * a22a33),
        (a24a33 * coef[3]) + (coef[9] * a31a44) + (coef[1] * a34a43)
        - (coef[1] * a33a44) - (a23a34 * coef[3]) - (coef[13] * a31a43),
        (coef[0] * a33a44) + (coef[8] * a34a41) + (coef[12] * a31a43)
        - (coef[12] * a33a41) - (coef[8] * a31a44) - (coef[0] * a34a43),
        (a14a23 * coef[3]) + (a13a21 * coef[15]) + (a11a24 * coef[11])
        - (a11a23 * coef[15]) - (a13a24 * coef[3]) - (a14a21 * coef[11]),
        (coef[0] * a23a34) + (a13a24 * coef[2]) + (a14a21 * coef[10])
        - (a14a23 * coef[2]) - (a13a21 * coef[14]) - (coef[0] * a24a33),
        (coef[1] * a32a44) + (a22a34 * coef[3]) + (coef[13] * a31a42)
        - (a24a32 * coef[3]) - (coef[5] * a31a44) - (coef[1] * a32a42),
        (coef[12] * a32a41) + (coef[4] * a31a44) + (coef[0] * a32a42)
        - (coef[0] * a32a44) - (coef[4] * a34a41) - (coef[12] * a31a42),
        (a11a22 * coef[15]) + (a12a24 * coef[3]) + (a14a21 * coef[7])
        - (a14a22 * coef[3]) - (a12a21 * coef[15]) - (a11a24 * coef[7]),
        (a14a22 * coef[2]) + (a12a21 * coef[14]) + (coef[0] * a24a32)
        - (coef[0] * a22a34) - (a12a24 * coef[2]) - (a14a21 * coef[6]),
        (a23a32 * coef[3]) + (coef[5] * a31a43) + (coef[1] * a33a42)
        - (coef[1] * a32a43) - (a22a33 * coef[3]) - (coef[9] * a31a42),
        (coef[0] * a32a43) + (coef[4] * a33a41) + (coef[8] * a31a42)
        - (coef[8] * a32a41) - (coef[4] * a31a43) - (coef[0] * a33a42),
        (a13a22 * coef[3]) + (a12a21 * coef[11]) + (a11a23 * coef[7])
        - (a11a22 * coef[11]) - (a12a23 * coef[3]) - (a13a21 * coef[7]),
        (coef[0] * a22a33) + (a12a23 * coef[2]) + (a13a21 * coef[6])
        - (a13a22 * coef[2]) - (a12a21 * coef[10]) - (coef[0] * a23a32)
    };
}


inline constexpr Matrix4 Matrix4::transposed() const noexcept
{
    return
    {
        coef[0], coef[4], coef[8] , coef[12],
        coef[1], coef[5], coef[9] , coef[13],
        coef[2], coef[6], coef[10], coef[14],
        coef[3], coef[7], coef[11], coef[15],
    };
}


inline constexpr Matrix4 Matrix4::adjugate() const noexcept
{ return cofactor().transposed(); }


inline constexpr f32 Matrix4::det() const noexcept
{
    const f32 det1{(coef[10] * coef[15]) - (coef[14] * coef[11])},
              det2{(coef[2]  * coef[15]) - (coef[14] * coef[3])},
              det3{(coef[6]  * coef[15]) - (coef[14] * coef[7])},
              det4{(coef[6]  * coef[11]) - (coef[10] * coef[7])},
              det5{(coef[2]  * coef[11]) - (coef[10] * coef[3])},
              det6{(coef[2]  * coef[7])  - (coef[6]  * coef[3])};

    return *coef      * ((coef[5] * det1) - (coef[9] * det3) + (coef[13] * det4))
           - coef[4]  * ((coef[1] * det1) - (coef[9] * det2) + (coef[13] * det5))
           + coef[8]  * ((coef[1] * det3) - (coef[5] * det2) + (coef[13] * det6))
           - coef[12] * ((coef[1] * det4) - (coef[5] * det5) + (coef[9]  * det6));
}


inline Matrix4 Matrix4::inversed() const noexcept
{ return adjugate() / det(); }


inline constexpr f32 Matrix4::trace() const noexcept
{ return coef[0] + coef[5] + coef[10] + coef[15]; }



/* ================ Operator overloads ================= */
// This actually does m * *this
inline constexpr Matrix4& Matrix4::operator*=(const Matrix4& m) noexcept
{
    coef[0]  = (coef[0] * m.coef[0]) + (coef[4] * m.coef[4]) + (coef[8]  * m.coef[8])  + (coef[12] * m.coef[12]);
    coef[1]  = (coef[1] * m.coef[0]) + (coef[5] * m.coef[4]) + (coef[9]  * m.coef[8])  + (coef[13] * m.coef[12]);
    coef[2]  = (coef[2] * m.coef[0]) + (coef[6] * m.coef[4]) + (coef[10] * m.coef[8])  + (coef[14] * m.coef[12]);
    coef[3]  = (coef[3] * m.coef[0]) + (coef[7] * m.coef[4]) + (coef[11] * m.coef[8])  + (coef[15] * m.coef[12]);
    coef[4]  = (coef[0] * m.coef[1]) + (coef[4] * m.coef[5]) + (coef[8]  * m.coef[9])  + (coef[12] * m.coef[13]);
    coef[5]  = (coef[1] * m.coef[1]) + (coef[5] * m.coef[5]) + (coef[9]  * m.coef[9])  + (coef[13] * m.coef[13]);
    coef[6]  = (coef[2] * m.coef[1]) + (coef[6] * m.coef[5]) + (coef[10] * m.coef[9])  + (coef[14] * m.coef[13]);
    coef[7]  = (coef[3] * m.coef[1]) + (coef[7] * m.coef[5]) + (coef[11] * m.coef[9])  + (coef[15] * m.coef[13]);
    coef[8]  = (coef[0] * m.coef[2]) + (coef[4] * m.coef[6]) + (coef[8]  * m.coef[10]) + (coef[12] * m.coef[14]);
    coef[9]  = (coef[1] * m.coef[2]) + (coef[5] * m.coef[6]) + (coef[9]  * m.coef[10]) + (coef[13] * m.coef[14]);
    coef[10] = (coef[2] * m.coef[2]) + (coef[6] * m.coef[6]) + (coef[10] * m.coef[10]) + (coef[14] * m.coef[14]);
    coef[11] = (coef[3] * m.coef[2]) + (coef[7] * m.coef[6]) + (coef[11] * m.coef[10]) + (coef[15] * m.coef[14]);
    coef[12] = (coef[0] * m.coef[3]) + (coef[4] * m.coef[7]) + (coef[8]  * m.coef[11]) + (coef[12] * m.coef[15]);
    coef[13] = (coef[1] * m.coef[3]) + (coef[5] * m.coef[7]) + (coef[9]  * m.coef[11]) + (coef[13] * m.coef[15]);
    coef[14] = (coef[2] * m.coef[3]) + (coef[6] * m.coef[7]) + (coef[10] * m.coef[11]) + (coef[14] * m.coef[15]);
    coef[15] = (coef[3] * m.coef[3]) + (coef[7] * m.coef[7]) + (coef[11] * m.coef[11]) + (coef[15] * m.coef[15]);

    return *this;
}


inline constexpr Matrix4& Matrix4::operator/=(const f32 k) noexcept
{
    const f32 reciprocal{1.f / k};

    coef[0]  *= reciprocal;
    coef[1]  *= reciprocal;
    coef[2]  *= reciprocal;
    coef[3]  *= reciprocal;
    coef[4]  *= reciprocal;
    coef[5]  *= reciprocal;
    coef[6]  *= reciprocal;
    coef[7]  *= reciprocal;
    coef[8]  *= reciprocal;
    coef[9]  *= reciprocal;
    coef[10] *= reciprocal;
    coef[11] *= reciprocal;
    coef[12] *= reciprocal;
    coef[13] *= reciprocal;
    coef[14] *= reciprocal;
    coef[15] *= reciprocal;

    return *this;
}


inline constexpr Vec4 Matrix4::operator*(const Vec4& v) const noexcept
{
    return
    {
        (coef[0] * v.xyz.x) + (coef[4] * v.xyz.y) + (coef[8] * v.xyz.z) + (coef[12] * v.w),
        (coef[1] * v.xyz.x) + (coef[5] * v.xyz.y) + (coef[9] * v.xyz.z) + (coef[13] * v.w),
        (coef[2] * v.xyz.x) + (coef[6] * v.xyz.y) + (coef[10] * v.xyz.z) + (coef[14] * v.w),
        (coef[3] * v.xyz.x) + (coef[7] * v.xyz.y) + (coef[11] * v.xyz.z) + (coef[15] * v.w)
    };
}


// Quite often, m is a static-built temporary matrix
inline Matrix4 Matrix4::operator*(const Matrix4& m) const noexcept
{
    return
    {
        (coef[0] * m.coef[0]) + (coef[4] * m.coef[1]) + (coef[8] * m.coef[2]) + (coef[12] * m.coef[3]),
        (coef[1] * m.coef[0]) + (coef[5] * m.coef[1]) + (coef[9] * m.coef[2]) + (coef[13] * m.coef[3]),
        (coef[2] * m.coef[0]) + (coef[6] * m.coef[1]) + (coef[10] * m.coef[2]) + (coef[14] * m.coef[3]),
        (coef[3] * m.coef[0]) + (coef[7] * m.coef[1]) + (coef[11] * m.coef[2]) + (coef[15] * m.coef[3]),
        (coef[0] * m.coef[4]) + (coef[4] * m.coef[5]) + (coef[8] * m.coef[6]) + (coef[12] * m.coef[7]),
        (coef[1] * m.coef[4]) + (coef[5] * m.coef[5]) + (coef[9] * m.coef[6]) + (coef[13] * m.coef[7]),
        (coef[2] * m.coef[4]) + (coef[6] * m.coef[5]) + (coef[10] * m.coef[6]) + (coef[14] * m.coef[7]),
        (coef[3] * m.coef[4]) + (coef[7] * m.coef[5]) + (coef[11] * m.coef[6]) + (coef[15] * m.coef[7]),
        (coef[0] * m.coef[8]) + (coef[4] * m.coef[9]) + (coef[8] * m.coef[10]) + (coef[12] * m.coef[11]),
        (coef[1] * m.coef[8]) + (coef[5] * m.coef[9]) + (coef[9] * m.coef[10]) + (coef[13] * m.coef[11]),
        (coef[2] * m.coef[8]) + (coef[6] * m.coef[9]) + (coef[10] * m.coef[10]) + (coef[14] * m.coef[11]),
        (coef[3] * m.coef[8]) + (coef[7] * m.coef[9]) + (coef[11] * m.coef[10]) + (coef[15] * m.coef[11]),
        (coef[0] * m.coef[12]) + (coef[4] * m.coef[13]) + (coef[8] * m.coef[14]) + (coef[12] * m.coef[15]),
        (coef[1] * m.coef[12]) + (coef[5] * m.coef[13]) + (coef[9] * m.coef[14]) + (coef[13] * m.coef[15]),
        (coef[2] * m.coef[12]) + (coef[6] * m.coef[13]) + (coef[10] * m.coef[14]) + (coef[14] * m.coef[15]),
        (coef[3] * m.coef[12]) + (coef[7] * m.coef[13]) + (coef[11] * m.coef[14]) + (coef[15] * m.coef[15])
    };
}

 
inline Matrix4 Matrix4::operator/(const f32 k) const noexcept
{
    const f32 reciprocal{1.f / k};

    return
    {
        coef[0]  * reciprocal, coef[1]  * reciprocal, coef[2]  * reciprocal, coef[3]  * reciprocal,
        coef[4]  * reciprocal, coef[5]  * reciprocal, coef[6]  * reciprocal, coef[7]  * reciprocal,
        coef[8]  * reciprocal, coef[9]  * reciprocal, coef[10] * reciprocal, coef[11] * reciprocal,
        coef[12] * reciprocal, coef[13] * reciprocal, coef[14] * reciprocal, coef[15] * reciprocal,
    };
}


inline constexpr f32 Matrix4::operator[](const u8 i) const noexcept
{ return coef[i]; }


inline constexpr f32 Matrix4::operator()(const u8 i, const u8 j) const noexcept
{ return coef[j * MAT4_COL + i]; }


#ifdef _DEBUG
inline std::ostream& operator<<(std::ostream& os, const Matrix4& mat) noexcept
{
    std::streamsize original = std::cout.precision();
    os << std::setprecision(2);

    for (u8 i{0u}; i < MAT4_COL; ++i)
    {
        u8 induction{i};
        
        os << "\n| ";
        for (u8 j{MAT4_COL}; j--; induction += MAT4_COL)
            os << std::setw(6) << mat.coef[induction] << ' ';

        os << " |";
    }

    os << std::setprecision(original);

    return os;
}
#endif