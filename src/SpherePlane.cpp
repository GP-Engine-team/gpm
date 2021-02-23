#include "GPM/ShapeRelation/SpherePlane.hpp"
#include "GPM/Vector3.hpp"

using namespace GPM;

bool SpherePlane::isSphereOnOrForwardPlaneCollided(const Sphere& sphere, const Plane& plane)
{
    float distanceSphereToOrigin = Vec3::dot(sphere.getCenter(), plane.getNormal());
    return distanceSphereToOrigin > -sphere.getRadius() + plane.getDistance();
}