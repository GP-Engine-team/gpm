/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/Segment.hpp"
#include "Shape3D/OrientedBox.hpp"

namespace GPM::SegmentOrientedBox
{
        static bool isSegmentOrientedBoxCollided(const Segment& seg, const OrientedBox& orientedBox, Intersection& intersection);

} /*namespace GPM*/