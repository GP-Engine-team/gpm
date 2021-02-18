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
#include "Shape3D/Quad.hpp"
#include "Shape3D/OrientedBox.hpp"

namespace GPM::MovingSphereOrientedBox
{

        /*get the first collision point between moving sphere and static box*/
        bool isMovingSphereOrientedBoxCollided(const Sphere& sphere, const OrientedBox& box, const Vec3& sphereVelocity, Intersection& intersection);



        static OrientedBox getMinkowskiSumOBB (const OrientedBox& box, float sphereRadius);

        static void applyVeronoiRegionCorrection(const OrientedBox& box, Intersection& intersection, const Segment& seg, float sphereRadius);

        static bool applyVeronoiRegionCorrectionWithOutCode(const OrientedBox& box, Intersection& intersection, const Segment& seg, float sphereRadius, int topOutCode, int rightOutCode, int forwardOutCode, bool checkFirstIntersection);

        static bool applyCapsuleCorrection(const Segment& seg, const Capsule& _capsule, Intersection& intersection, bool checkFirstIntersection);

        /*Sub component of minkowski sum*/
        static Capsule getTopLeftVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getTopRightVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getTopForwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getTopBackwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getBottomLeftVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getBottomRightVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getBottomForwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getBottomBackwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getLeftForwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getLeftBackwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getRightForwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Capsule getRightBackwardVeronoiCapsule(const OrientedBox& box, float sphereRadius);

        static Quad getTopVeronoiFace (const OrientedBox& box, float sphereRadius);

        static Quad getBottomVeronoiFace(const OrientedBox& box, float sphereRadius);

        static Quad getRightVeronoiFace(const OrientedBox& box, float sphereRadius);

        static Quad getLeftVeronoiFace(const OrientedBox& box, float sphereRadius);

        static Quad getFowardVeronoiFace(const OrientedBox& box, float sphereRadius);

        static Quad getBackwardVeronoiFace(const OrientedBox& box, float sphereRadius);

        //OutCode for detect the position of a point with the capsule
        static const int BOTTOM_LEFT_BACKWARD  = 0;    // 0000
        static const int TOP_LEFT_BACKWARD     = 1;    // 0001
        static const int BOTTOM_RIGHT_BACKWARD = 2;    // 0010
        static const int TOP_RIGHT_BACKWARD    = 3;    // 0011
        static const int BOTTOM_LEFT_FORWARD   = 4;    // 0100
        static const int TOP_LEFT_FORWARD      = 5;    // 0101
        static const int BOTTOM_RIGHT_FORWARD  = 6;    // 0110
        static const int TOP_RIGHT_FORWARD     = 7;    // 0111
        static const int INSIDE                = 8;    // 1000
    
        static const int ON_TOP_MASK           = 0;    // 0001
        static const int ON_RIGHT_MASK         = 1;    // 0010
        static const int ON_FORWARD_MASK       = 2;    // 0100

} /*!namespace GPM*/