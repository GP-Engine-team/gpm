#include "Matrix3.hpp"
#include "Matrix4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Quaternion.hpp"
#include "conversion.hpp"
#include "constants.hpp"

#include <iostream>

int main()
{
    GPM::Mat3 mat3 = GPM::Mat3::identity();
    GPM::Mat4 mat4 = GPM::Mat4::identity();
    GPM::Vec2 vec2{1.f, 2.f};
    GPM::Vec3 vec3{-3.f, -2.f, -1.f};
    GPM::Vec4 vec4{vec3, 1.f};
    GPM::Quat quat{GPM::Quat::angleAxis(HALF_PI, vec3)};
    GPM::Quat quatMat3{toQuaternion(mat3)};

    std::cerr << "mat3 = " << mat3 << '\n';
    std::cerr << "mat4 = " << mat4 << '\n';
    std::cerr << "vec2 = " << vec2 << '\n';
    std::cerr << "vec3 = " << vec3 << '\n';
    std::cerr << "vec4 = " << vec4 << '\n';
    std::cerr << "quat = " << quat << '\n';
    std::cerr << "quatMat3 = " << quatMat3 << '\n';
    std::cerr << "toMatrix3(quatMat3) = " << toMatrix3(quatMat3) << '\n';

    quatMat3 = toQuaternion(toMatrix3(quatMat3));

    std::cerr << "quatMat3 = toQuaternion(toMatrix3(quatMat3)) = " << quatMat3 << '\n';

    return 0;
}