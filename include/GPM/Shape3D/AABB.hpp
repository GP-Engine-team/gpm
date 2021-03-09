/*
 * Copyright (C) 2021 Amara Sami, Dallard Thomas, Nardone William, Six Jonathan
 * This file is subject to the LGNU license terms in the LICENSE file
 * found in the top-level directory of this distribution.
 */

#pragma once

#include "../Tools.hpp"
#include "../Vector3.hpp"
#include "Volume.hpp"

namespace GPM
{
class AABB : public Volume
{
protected:
    Vec3  m_center;
    float m_iI, m_iJ, m_iK;

public:
    AABB()                  = default;
    AABB(const AABB& other) = default;
    AABB(AABB&& other)      = default;
    virtual ~AABB()         = default;
    AABB& operator=(AABB const& other) = default;
    AABB& operator=(AABB&& other) = default;

    AABB(const Vec3& center, float iI, float iJ, float iK) : Volume{}, m_center{center}, m_iI{iI}, m_iJ{iJ}, m_iK{iK}
    {
    }

    AABB(const Vec3& min, const Vec3& max)
        : Volume{}, m_center{(max + min) * 0.5f}, m_iI{max.x - m_center.x}, m_iJ{max.y - m_center.y}, m_iK{max.z -
                                                                                                           m_center.z}
    {
    }

    bool isInside(Vec3 pt) const noexcept
    {
        Vec3        localPt = pt - m_center;
        const float espilon =
            0.0001f; /*The standard float espsilone his enought in this case. The float value has chang to much*/

        return isBetween(localPt.x, -m_iI - espilon, m_iI + espilon) &&
               isBetween(localPt.y, -m_iJ - espilon, m_iJ + espilon) &&
               isBetween(localPt.z, -m_iK - espilon, m_iK + espilon);
    }

    Vec3 getCenter() const noexcept
    {
        return m_center;
    }

    float getExtI() const noexcept
    {
        return m_iI;
    }

    float getExtJ() const noexcept
    {
        return m_iJ;
    }

    float getExtK() const noexcept
    {
        return m_iK;
    }

    void setCenter(const Vec3& center) noexcept
    {
        m_center = center;
    }

    void setExtI(const float& i) noexcept
    {
        m_iI = i;
    }

    void setExtJ(const float& j) noexcept
    {
        m_iJ = j;
    }

    void setExtK(const float& k) noexcept
    {
        m_iK = k;
    }
};

} // namespace GPM
