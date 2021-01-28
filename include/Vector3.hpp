#pragma once

#include <cfloat>
#include <cmath>

#ifdef _DEBUG
#include <iostream>
#endif

namespace GPM
{

struct Vector3
{
    // Data members
    f32 x;
    f32 y;
    f32 z;

    // Static methods (pseudo-constructors)
    static constexpr Vector3 zero           ()                              noexcept;
    static constexpr Vector3 one            ()                              noexcept;
    static constexpr Vector3 left           ()                              noexcept;
    static constexpr Vector3 up             ()                              noexcept;
    static constexpr Vector3 forward        ()                              noexcept;

    // Member methods
    constexpr f32       length2             ()                              const noexcept;
    f32                 length              ()                              const noexcept;
    constexpr f32       dot                 (const Vector3& v)              const noexcept;
    constexpr Vector3   cross               (const Vector3& v)              const noexcept;
    constexpr bool      isNull              ()                              const noexcept;
    constexpr bool      isOrthogonalTo      (const Vector3& v)              const noexcept;
    constexpr bool      isNormalized        ()                              const noexcept;
    constexpr  bool     isOrthonormalTo     (const Vector3& v)              const noexcept;
    constexpr  bool     isColinearTo        (const Vector3& v)              const noexcept;
    bool                isEqualTo           (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    bool                isNotEqualTo        (const Vector3& v,
                                             const f32 eps = FLT_EPSILON)   const noexcept;
    void                normalize           ()                              noexcept;
    constexpr f32       distance2To         (const Vector3& v)              const noexcept;
    f32     	        distanceTo		    (const Vector3& v)              const noexcept;
    f32     	        angleWithUnitary    (const Vector3& v)              const noexcept;
    f32                 angleWith		    (const Vector3& v)              const noexcept;
    f32                 triangleArea	    (const Vector3& v)              const noexcept;
    Vector3             normalized          ()                              const noexcept;
    constexpr Vector3   projectedOnUnitary  (const Vector3& v)              const noexcept;
    constexpr Vector3   projectedOn         (const Vector3& v)              const noexcept;
    Vector3             rotatedAroundUnitary(const Vector3& v,
                                             const f32 angle)               const noexcept;
    Vector3             rotatedAround       (const Vector3& v,
                                             const f32 angle)               const noexcept;
    constexpr Vector3   lerp                (const Vector3& v,
                                             const f32 t)                   const noexcept;

    // Operator overloads
    constexpr Vector3&	operator+=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator+=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator-=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator-=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator*=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator*=          (const Vector3&& v)             noexcept;
    constexpr Vector3&	operator/=          (const Vector3& v)              noexcept;
    constexpr Vector3&	operator/=          (const Vector3&& v)             noexcept;
    constexpr Vector3&  operator*=          (const f32 k)                   noexcept;
    constexpr Vector3&  operator/=          (const f32 k)                   noexcept;
    constexpr Vector3   operator+           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator+           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           (const Vector3& v)              const noexcept;
    constexpr Vector3   operator-           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator*           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator*           (const Vector3&& v)             const noexcept;
    constexpr Vector3	operator/           (const Vector3& v)              const noexcept;
    constexpr Vector3	operator/           (const Vector3&& v)             const noexcept;
    constexpr Vector3   operator-           ()                              const noexcept;
    constexpr Vector3	operator*           (const f32 k)                   const noexcept;
    constexpr Vector3	operator/           (const f32 k)                   const noexcept;

    #ifdef _DEBUG
    friend std::ostream& operator<<(std::ostream& os, const Vector3& v) noexcept;
    #endif
};

using Vec3 = Vector3;
using vec3 = Vector3;

#include "Vector3.inl"

} // End of namespace Math