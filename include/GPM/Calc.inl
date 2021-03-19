inline f32 clamp(const f32 k, const f32 lo, const f32 hi)
{
    return fmax(lo, fmin(k, hi)) ;
}


inline bool f32AreEqual(const f32 a, const f32 b)
{
    const f32 eps1{pow(10.f, -6.f + round(log10f(fabs(a))))},
              eps2{pow(10.f, -6.f + round(log10f(fabs(b))))};
    return fabs(b - a) <= fmin(eps1, eps2);
}


inline bool f32AreEqual(const f32 a, const f32 b, const f32 eps)
{
    return fabs(b - a) < eps;
}