﻿/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */
 
#pragma once

#include "../Vector3.hpp"

#include <limits>
#include <utility>

namespace GPM
{
    enum class EIntersectionType
    {
        NoIntersection,
        OneIntersectiont,
        TwoIntersectiont,
        InfinyIntersection,
        UnknowIntersection
    };

    struct Intersection
    {
        EIntersectionType intersectionType = EIntersectionType::NoIntersection;
        Vec3 intersection1;
        Vec3 intersection2;
        Vec3 normalI1;
        Vec3 normalI2;

        void setNotIntersection ()
        {
            intersectionType = EIntersectionType::NoIntersection;
        }

        void setOneIntersection(const Vec3& intersectionPoint)
        {
            intersectionType = EIntersectionType::OneIntersectiont;
            intersection1 = intersectionPoint;
        }

        void setTwoIntersection(const Vec3& intersectionPoint1, const Vec3 intersectionPoint2)
        {
            intersectionType = EIntersectionType::TwoIntersectiont;
            intersection1 = intersectionPoint1;
            intersection2 = intersectionPoint2;
        }

        void setSecondIntersection(const Vec3& intersectionPoint2)
        {
            intersectionType = EIntersectionType::TwoIntersectiont;
            intersection2 = intersectionPoint2;
        }

        void setInifitIntersection()
        {
            intersectionType = EIntersectionType::InfinyIntersection;
        }

        void setUnKnowIntersection()
        {
            intersectionType = EIntersectionType::UnknowIntersection;
        }

        void removeFirstIntersection()
        {
            if (intersectionType == EIntersectionType::TwoIntersectiont)
            {
                intersectionType = EIntersectionType::OneIntersectiont;
                intersection1 = intersection2;
                normalI1 = normalI2;
            }
            else
            {
                intersectionType = EIntersectionType::NoIntersection;
            }
        }

        void removeSecondIntersection()
        {
            if (intersectionType == EIntersectionType::TwoIntersectiont)
            {
                intersectionType = EIntersectionType::OneIntersectiont;

            }
        }

        /*return true if intersection contenor is full (if there are 2 intersection)*/
        bool addIntersectionAndCheckIfSecond(const Vec3& intersection)
        {
            if (intersectionType != EIntersectionType::OneIntersectiont)
            {
                setOneIntersection(intersection);
                return false;
            }
            else
            {
                setSecondIntersection(intersection);
                return true;
            }
        }

        void swapIntersection()
        {
            /*swap intersection*/
            std::swap<Vec3>(intersection1, intersection2);

            /*swap normal*/
            std::swap<Vec3>(normalI1, normalI2);
        }

        void sortIntersection(const Vec3& pt1Seg)
        {
            if (intersectionType != EIntersectionType::TwoIntersectiont)
            {
                return;
            }

            if ((intersection1 - pt1Seg).length() > (intersection2 - pt1Seg).length())
            {
                swapIntersection();
            }
        }

        static bool computeDiscriminentAndSolveEquation(float a, float b, float c, const Vec3& segPt1, const Vec3& segPt2, Intersection& intersection);
    };
} /*!namespace GPM*/