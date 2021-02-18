/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "Vector/Vector.hpp"
#include "GE/Core/Maths/ShapeRelation/Intersection.hpp"
#include "Shape3D/Segment.hpp"

namespace GPM::SegmentSegment
{
    bool isSegmentSegmentCollided(const Vec3& a1, const Vec3& a2, const Vec3& b1, const Vec3& b2, Intersection& intersection);

} /*namespace GPM*/