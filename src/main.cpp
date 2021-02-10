#include "Matrix3.hpp"
#include "Matrix4.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "Quaternion.hpp"
#include "conversion.hpp"
#include "constants.hpp"
#include "Transform.hpp"

#include <iostream>

using namespace GPM;

int main()
{
    Transform transform;
    SplitTransform split{toSplitTransform(transform)};

    std::cerr << "- transform:\n" << transform << '\n';

    transform.rotate({-PI * .5f, .0f, .0f});
    std::cerr << "- transform after rotation:\n" << transform << '\n'; 
    transform.translate({1.f, .0f, .0f});
    std::cerr << "- transform after translation:\n" << transform << '\n'; 
    transform.scale({.5f});
    std::cerr << "- transform after scaling:\n" << transform << '\n';

    Mat4 m{Transform::rotationX(-PI * .25f)};
    std::cerr << "m before:\n" << m << '\n';
    m = m.inversed();
    std::cerr << "m after:\n" << m.inversed() << '\n';

    return 0;
}