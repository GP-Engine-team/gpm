#pragma once

#include "TestingTools.hpp"
#include "../include/GPM/Vector3.hpp"
#include "../include/GPM/Calc.hpp"

namespace GPM
{

void testVec3Constructors()
{
    fprintf(stderr, "\nVector3's constructors unit tests:\n");

    const f32  val    {randomf32()};
    const Vec2 vec2   {val, val};
    const f32  coef[3]{val, val, val};

    const Vec3 v1{val};
    const Vec3 v2{val, val, val};
    const Vec3 v3{val, val};
    const Vec3 v4{vec2, val};
    const Vec3 v5{vec2};
    const Vec3 v6{coef};

    TEST("Vector3(const f32 k)",
         v1.x == val && v1.y == val && v1.z == val);

    TEST("Vector3(const f32 x, const f32 y, const f32 z = .0f)",
         v2.x == val && v2.y == val && v2.z == val &&
         v3.x == val && v3.y == val && v3.z == .0f);

    TEST("Vector3(Vec2 v, const f32 z)",
         v4.x == val && v4.y == val && v4.z == val &&
         v5.x == val && v5.y == val && v5.z == .0f);

    TEST("Vector3(const f32 coef[3])",
         v6.x == coef[0] && v6.y == coef[1] && v6.z == coef[2]);
}

void testVec3StaticMethods()
{
     fprintf(stderr, "\nVector3's static methods unit tests:\n");

     const Vec3 zero   {Vec3::zero()};
     const Vec3 one    {Vec3::one()};
     const Vec3 right  {Vec3::right()};
     const Vec3 up     {Vec3::up()};
     const Vec3 forward{Vec3::forward()};

     TEST("Vector3::zero()",    zero.x == .0f && zero.y == .0f && zero.z == .0f);
     TEST("Vector3::one()",     one.x == 1.f && one.y == 1.f && one.z == 1.f);
     TEST("Vector3::right()",   right.x == 1.f && right.y == .0f && right.z == .0f);
     TEST("Vector3::up()",      up.x == .0f && up.y == 1.f && up.z == .0f);
     TEST("Vector3::forward()", forward.x == .0f && forward.y == .0f && forward.z == 1.f);
}


void testVec3SpecificMethods()
{
     fprintf(stderr, "\nVector3's specific methods unit tests:\n");

     const Vec3 val       {randomVector3()}, val2{randomVector3()};
     const Vec3 normalized{val.normalized()};
     const Vec3 rotated   {val2.rotatedAroundUnitary(normalized, randomf32())};

     TEST("Vector3::normalized()", f32AreEqual(normalized.sqrLength(), 1.f, 1e-6));
     TEST("Vector3::rotatedAroundUnitary(const Vector3& v, const f32 angle)",
          f32AreEqual(val2.angleWithUnitary(normalized), rotated.angleWithUnitary(normalized), 1e-3));
     TEST("Vector::lerp(const Vector3& v)",
           val.lerp(normalized, 1.f).isEqualTo(normalized) &&
           val.lerp(normalized, .0f).isEqualTo(val) &&
           val.lerp(normalized, .5f).isEqualTo((val * .5f) + (normalized * .5f)));
}


void testVec3()
{
    testVec3Constructors();
    testVec3StaticMethods();
    testVec3SpecificMethods();
}

}