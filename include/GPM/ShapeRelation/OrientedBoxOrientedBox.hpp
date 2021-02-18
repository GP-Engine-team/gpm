/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/OrientedBox.hpp"

namespace GPM::OrientedBoxOrientedBox
{
    static bool isBothOrientedBoxCollided(const OrientedBox& box1, const OrientedBox& box2);

} /*namespace GPM*/