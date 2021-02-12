#include "GPM/Matrix3.hpp"
#include "GPM/Matrix4.hpp"
#include "GPM/Vector2.hpp"
#include "GPM/Vector3.hpp"
#include "GPM/Vector4.hpp"
#include "GPM/Quaternion.hpp"
#include "GPM/conversion.hpp"
#include "GPM/constants.hpp"
#include "GPM/Transform.hpp"

#include <iostream>

using namespace GPM;

int main()
{
    const Vec3 eyePos   {1.f, .0f, 1.f},
               targetPos{.0f, .0f, .0f};
    Transform  transform{eyePos};

    std::cerr << "- transform:\n" << transform << '\n';

#if 0
    transform.translate({.0f, 1.f, .0f});
    std::cerr << "- transform after y=y+1:\n" << transform << '\n';
#endif
#if 0
    transform.scaleY(5.f);
    std::cerr << "- transform after scale yx5:\n" << transform << '\n';
#endif
#if 0
    transform.rotateX(HALF_PI);
    std::cerr << "- transform after rotX(90):\n" << transform << '\n'; 
#endif
    //transform.scale({.5f});
    //std::cerr << "- transform after scaling:\n" << transform << '\n';

    std::cerr << "eyePos: " << eyePos << '\n';
    transform.lookAt(targetPos);
    std::cerr << "transform.lookAt(" << targetPos << "):\n" << transform << '\n';

    return 0;
}