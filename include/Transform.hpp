#pragma once

#include "conversion.hpp"
#include "Matrix4.hpp"
#include "types.hpp"
#include "Vector3.hpp"

#include <cmath>

namespace GPM
{

struct SplitTransform
{
    Quat rotation;
    Vec3 position;
    Vec3 scale;

    friend std::ostream& operator<<(std::ostream& os, const SplitTransform& m) noexcept;
};


struct Transform
{
    Mat4 model{Mat4::identity()};

    // Static methods
    static constexpr Mat4 translation(const Vec3& t)                     noexcept;
    static Mat4           rotationX  (const f32 angle)                   noexcept;
    static Mat4           rotationY  (const f32 angle)                   noexcept;
    static Mat4           rotationZ  (const f32 angle)                   noexcept;
    static Mat4           rotation   (const Vec3& t)                     noexcept;
    static constexpr Mat4 scaling    (const Vec3& t)                     noexcept;
    static Mat4           TRS        (const Vec3& t, const Vec3& r,
                                      const Vec3& s)                     noexcept;
    static constexpr Mat4 symFrustrum(const f32 right, const f32 top,
                                      const f32 near,  const f32 far)    noexcept;
    static Mat4           perspective(const f32 fovY,  const f32 aspect,
                                      const f32 near,  const f32 far)    noexcept;
    static constexpr Mat4 viewport   (const f32 x,     const f32 y,
                                      const f32 width, const f32 height) noexcept;

    // Getters
    Mat4            normalMat        ()                                  const noexcept;
    constexpr Vec3  right            ()                                  const noexcept;
    constexpr Vec3  up               ()                                  const noexcept;
    constexpr Vec3  forward          ()                                  const noexcept;
    constexpr Vec3  translation      ()                                  const noexcept;
    Mat4            rotation         ()                                  const noexcept;
    Vec3            scaling          ()                                  const noexcept;

    // Transformations
    constexpr void  translate        (const Vec3& t)                     noexcept;
    void            rotateX          (const f32 angle)                   noexcept;
    void            rotateY          (const f32 angle)                   noexcept;
    void            rotateZ          (const f32 angle)                   noexcept;
    void            rotate           (const Vec3& r)                     noexcept;
    constexpr void  scale            (const Vec3& s)                     noexcept;
    constexpr void  apply            (const Mat4& m)                     noexcept;

    // Utility
    friend std::ostream& operator<<(std::ostream& os, const Transform& m) noexcept;
};


/*
struct Transform
{
    Quat rotation;
    Vec3 position;
    Vec3 scale;

    static constexpr Mat4 translation(const Vec3& t)   noexcept;
    static Mat4           rotationX  (const f32 angle) noexcept;
    static Mat4           rotationY  (const f32 angle) noexcept;
    static Mat4           rotationZ  (const f32 angle) noexcept;
    static Mat4           rotation   (const Vec3& t)   noexcept;
    static constexpr Mat4 scaling    (const Vec3& t)   noexcept;
    static Mat4           TRS        (const Vec3& t, const Vec3& r,
                                      const Vec3& s)   noexcept;

    // View
    static constexpr Mat4 symFrustrum(const f32 right, const f32 top,
                                      const f32 near,  const f32 far)    noexcept;
    static Mat4           perspective(const f32 fovY,  const f32 aspect,
                                      const f32 near,  const f32 far)    noexcept;
    static constexpr Mat4 viewport   (const f32 x,     const f32 y,
                                      const f32 width, const f32 height) noexcept;

    // Referential
    Mat4                  normalMat  ()   noexcept;
    constexpr Mat4        modelMat   ()   noexcept;
    constexpr Vec3        right      ()   noexcept;
    constexpr Vec3        up         ()   noexcept;
    constexpr Vec3        forward    ()   noexcept;
    constexpr Vec3        position   ()   noexcept;
};
*/

#include "../src/Transform.inl"

} // End of namespace GPM