/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/AABB.hpp"

namespace GPM::AabbAabb
{
    bool isBothAABBCollided(const AABB& aabb1, const AABB& aabb2, Intersection& intersection);
    bool isBothAABBCollided(const AABB& aabb1, const AABB& aabb2);

} /*!namespace GPM*/