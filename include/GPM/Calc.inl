inline f32 clamp(const f32 k, const f32 lo, const f32 hi)
{
    return fmax(lo, fmin(k, hi)) ;
}


inline bool f32AreEqual(const f32 a, const f32 b)
{
    const f32 eps1{a * 1e-6f}, eps2{b * 1e-6f};
    return fabs(b - a) <= fmax(eps1, eps2);
}


inline bool f32AreEqual(const f32 a, const f32 b, const f32 eps)
{
    return fabs(b - a) <= eps;
}

template<typename T>
inline T lerp(const T& a, const T& b, const f32 alpha)
{
	return (a * (1.f - alpha)) + (b * alpha);
}