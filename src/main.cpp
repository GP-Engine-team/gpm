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

    std::cerr << "- transform:\n" << transform << '\n';

#if 1
    transform.translate({.0f, 1.f, .0f});
    std::cerr << "- transform after y=y+1:\n" << transform << '\n';
#endif
#if 1
    transform.scaleY(5.f);
    std::cerr << "- transform after scale yx5:\n" << transform << '\n';
#endif
#if 0
    transform.rotateX(HALF_PI);
    std::cerr << "- transform after rotX(90):\n" << transform << '\n'; 
#endif
    //transform.scale({.5f});
    //std::cerr << "- transform after scaling:\n" << transform << '\n';

    return 0;
}