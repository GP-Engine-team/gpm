/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "Vector3.hpp"
#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/Segment.hpp"
#include "Shape3D/Capsule.hpp"
#include "Shape3D/Cylinder.hpp"
#include "Shape3D/Sphere.hpp"

namespace GPM::SegmentCapsule
{
        bool isSegmentCapsuleCollided(const Segment& seg, const Capsule& capsule, Intersection& intersection);


        static void detectSegmentPointPosition(const Segment& seg, const Capsule& capsule, int& outCodePt1, int& outCodePt2);

        static void checkCapsuleInfinitCylinderCollisionPoint(const Capsule& capsule, Intersection& intersection);

        static void checkLeftCapsuleSphereCollision (const Segment& seg, const Capsule& capsule, Intersection& intersection);

        static void checkRightCapsuleSphereCollision(const Segment& seg, const Capsule& capsule, Intersection& intersection);

        static bool pointIsBetweenCapsuleSegLimit(const Capsule& capsule, const Vec3& pt);

        //OutCode for detect the position of a point with the capsule
        static const int INSIDE           = 0;  // 0000
        static const int LEFT_INTERNAL    = 9;  // 1001
        static const int LEFT_EXTERNAL    = 5;  // 0101
        static const int RIGHT_INTERNAL   = 10;  // 1010
        static const int RIGHT_EXTERNAL   = 6;  // 0110

        static const int ON_THE_LEFT_MASK  = 1;  // 0001
        static const int ON_THE_RIGHT_MASK = 2;  // 0010
        static const int ON_EXTERNAL_MASK  = 4;  // 0100
        static const int ON_INTERNAL_MASK  = 8;  // 1000

} /*namespace GPM*/