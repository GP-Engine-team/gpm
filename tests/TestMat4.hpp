#pragma once

#include "TestingTools.hpp"
#include "../include/GPM/Matrix4.hpp"
#include "../include/GPM/Calc.hpp"
#include "../include/GPM/DebugOutput.hpp"

namespace GPM
{

void testMat4Methods()
{
    fprintf(stderr, "\nMatrix4's methods unit tests:\n");

    const Mat4 m1{randomMatrix4(-10.f, 10.f)};
    const Mat4 m2{randomTransformMatrix4(-10.f, 10.f)};

    TEST("Matrix4::det()",
         f32AreEqual(m1.det(), m1.transposed().det(), 1e-3) &&
         f32AreEqual(1.f / m1.det(), m1.inversed().det(), 1e-3) &&
         f32AreEqual(m2.det(), m2.transposed().det(), 1e-3) &&
         f32AreEqual(1.f / m2.det(), m2.inversed().det(), 1e-3));
    
    TEST("Matrix4::inversed() and Matrix4::operator*(const Matrix4& m)",
         (m1.inversed() * m1).isEqualTo(m1 * m1.inversed(), 1e-3));
}

} // End of namespace GPM