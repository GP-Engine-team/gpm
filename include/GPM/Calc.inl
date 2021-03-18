inline f32 clamp(const f32 k, const f32 lo, const f32 hi)
{
    return fmax(lo, fmin(k, hi)) ;
}