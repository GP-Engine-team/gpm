﻿#include "ShapeRelation/SegmentSphere.hpp"

#include "Vector3.hpp"

using namespace GPM;

bool SegmentSphere::isSegmentSphereCollided(const Segment& seg, const Sphere& sphere, Intersection& intersection)
{
    Vec3 AOmega         = sphere.getCenter() - seg.getPt1();
    float AOmegaLength  = AOmega.length();
    Vec3 AB             = seg.getPt2() - seg.getPt1();
    float ABLength      = AB.length();

    /*AOmega² - R + 2AB. OmegaA * t + AB² * t² = 0*/
    float a = ABLength * ABLength;
    float b = 2.f * Vec3::dot(AB, -AOmega);
    float c = AOmegaLength * AOmegaLength - sphere.getRadius() * sphere.getRadius();

    /*We comput the discriminent*/
    if (Intersection::computeDiscriminentAndSolveEquation(a, b, c, seg.getPt1(), seg.getPt2(), intersection))
    {
        if (intersection.intersectionType == EIntersectionType::TwoIntersectiont)
        {
            intersection.normalI2 = (intersection.intersection2 - sphere.getCenter()).normalized();
        }

        intersection.normalI1 = (intersection.intersection1 - sphere.getCenter()).normalized();

        return true;
    }
    else
    {
        return false;
    }
}
