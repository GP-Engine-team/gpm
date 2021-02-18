#include "ShapeRelation/SpherePlane.hpp"
#include "Vector3.hpp"

using namespace GPM;

bool SpherePlane::isSphereOnOrForwardPlanCollided(const Sphere& sphere, const Plane& plane)
{
    float distanceSphereToOrigin = Vec3::dot(sphere.getCenter(), plane.getNormal());
    return distanceSphereToOrigin > -sphere.getRadius() + plane.getDistance();
}