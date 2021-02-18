/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "Vector3.hpp"
#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/Segment.hpp"
#include "Shape3D/AABB.hpp"

namespace GPM::SegmentAABB
{
    bool isSegmentAABBCollided(const Segment& seg, const AABB& AABB, Intersection& intersection);

    /*memorise with temporal float the value of T. Compare this value to the new T and compute the nearest point af seg.pt1*/
    static bool addIntersectionWithScalerIfOnAABBAndReturnIfFull(const Segment& seg, const AABB& AABB, Intersection& intersection, float scaler, float& tempT, Vec3 faceNormal);

} /*namespace GPM*/