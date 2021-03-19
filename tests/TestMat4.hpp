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

    const Mat4 m1{randomMatrix4(-1000.f, 100.f)};
    const Mat4 m2{randomTransformMatrix4(-100.f, 100.f)};

    TEST("Matrix4::det()",
         f32AreEqual(m1.det(), m1.transposed().det()) &&
         f32AreEqual(1.f / m1.det(), m1.inversed().det()) &&
         f32AreEqual(m2.det(), m2.transposed().det()) &&
         f32AreEqual(1.f / m2.det(), m2.inversed().det()));
    
    //pow(10.f, -6.f + round(log10f(fabs(1.f / m2.det())))))
}

} // End of namespace GPM