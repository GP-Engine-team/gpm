#pragma once

#include "TestingTools.hpp"
#include "../include/GPM/Quaternion.hpp"
#include "../include/GPM/Calc.hpp"

namespace GPM
{

void testQuatStaticMethods()
{
    fprintf(stderr, "\nQuaternion's static methods unit tests:\n");

    const Vec3 v1   {randomVector3(-100.f, 100.f)};
    const f32  angle{randomf32(-PI, PI)};
    const Quat q1   {Quat::angleAxis(angle, v1)};
    const Quat q2   {Quat::fromEuler(v1)};

    TEST("Quaternion::angleAxis(const f32 angle, const Vec3& axis)",
         f32AreEqual(q1.w, cosf(angle * .5f), 1e-6) &&
         q1.v.isEqualTo(v1.normalized() * sinf(angle * .5f), 1e-6));

    TEST("Quaternion::fromEuler(const Vector3& angles)",
         q2.rotate(v1).isEqualTo(v1.rotatedAround(q2.axis(), q2.angle()), 1e-3));
}


void testQuatMethods()
{
    fprintf(stderr, "\nQuaternion's methods unit tests:\n");

    const f32  angle{fmod(randomf32(), PI)};
    const Vec3 v1   {randomVector3()},
               v2   {randomVector3()};
    const Quat q1   {Quat::angleAxis(angle, v1)};
    const Quat q2   {Quat::angleAxis(angle, v2)};

    /*
    const Quat la{Quat::lookAt(v1, v2)};
    TEST("Quaternion::lookAt(const Vec3& sourcePoint, const Vec3& destPoint)",
         (la * Vec3::forward()).isColinearTo(v2 - v1));
    */

    const bool inversed{q1.unitAxis().isEqualTo(-v1.normalized())};

    TEST("Quaternion::axis() and Quaternion::unitAxis()",
         q1.unitAxis().isEqualTo(v1.normalized()) || inversed);

    TEST("Quaternion::angle()", f32AreEqual(q1.angle(), inversed ? -angle : angle, 1e-4));
    TEST("Quaternion::slerp(const Quaternion& target, const f32 t)",
         q1.slerp(q2, 1.f).isEqualTo(q2) && q1.slerp(q2, .0f).isEqualTo(q1));
    
    TEST("Quaternion::rotate(const Vector3& v)",
         f32AreEqual(v1.angleWith(q1.rotate(v2)), v1.angleWith(v2), 1e-5));
}


void testQuatOperators()
{
    fprintf(stderr, "\nQuaternion's operators unit tests:\n");
    
    const f32  angle{fmod(randomf32(), PI)};
    const Vec3 v1   {randomVector3()},
               v2   {randomVector3()};
    const Quat q1   {Quat::angleAxis(angle, v1)};
    const Quat q2   {Quat::angleAxis(angle, v2)};

    TEST("Quaternion::operator*(const Quaternion& q)",
         f32AreEqual((q1 * q2).angleWith(q1), q2.angle(), 1e-4));
}


void testQuat()
{
    testQuatStaticMethods();
    testQuatMethods();
    testQuatOperators();
}

} // End of namespace GPE