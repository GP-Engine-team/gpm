/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "ShapeRelation/Intersection.hpp"
#include "Shape3D/Segment.hpp"
#include "Shape3D/Quad.hpp"

namespace GPM::SegmentQuad
{
    bool isSegmentQuadCollided(const Segment& seg, const Quad& quad, Intersection& intersection);

            /*using the Cohen–Sutherland algorithm to detect the emplacement of the point*/
        static int detectPointEmplacement (const Vec2& point, const Vec2& min, const Vec2& max);

        static bool detectCollisionOn2DQuad(const Quad& quad, const Segment& seg, Intersection& intersection);

        //OutCode for detect the position of a point with the capsule
        static const int INSIDE  = 0;   // 0000
        static const int LEFT    = 1;   // 0001
        static const int RIGHT   = 2;   // 0010
        static const int BOTTOM  = 4;   // 0100
        static const int TOP     = 8;   // 1000

        static const int CENTRAL_COLMN_MASK  = 2;  // 0011
        static const int CENTRAL_LINE_MASK   = 12; // 1100

} /*namespace GPM*/