#include "ShapeRelation/SegmentOrientedBox.hpp"

#include "Vector3.hpp"
#include "Shape3D/AABB.hpp"
#include "ShapeRelation/SegmentAABB.hpp"
#include "Referential.hpp"

using namespace GPM;



bool SegmentOrientedBox::isSegmentOrientedBoxCollided(const Segment& seg, const OrientedBox& orientedBox, Intersection& intersection)
{
    /*Transform the segment from global referential to the local referential of the oriented box*/
    Segment localSegment {  Referential::globalToLocalPosition(orientedBox.getReferential(), seg.getPt1()),
                            Referential::globalToLocalPosition(orientedBox.getReferential(), seg.getPt2())};
                            

    AABB orientedBoxAxisAligned {Referential::globalToLocalPosition(orientedBox.getReferential(), orientedBox.getReferential().origin), orientedBox.getExtI(), orientedBox.getExtJ(), orientedBox.getExtK()};

    if(SegmentAABB::isSegmentAABBCollided(localSegment, orientedBoxAxisAligned, intersection))
    {
        intersection.intersection1 = Referential::localToGlobalPosition(orientedBox.getReferential(), intersection.intersection1);
        
        if (intersection.intersectionType == EIntersectionType::TwoIntersectiont)
            intersection.intersection2 = Referential::localToGlobalPosition(orientedBox.getReferential(), intersection.intersection2);

        intersection.normalI1 = Referential::localToGlobalVector(orientedBox.getReferential(), intersection.normalI1);

        if (intersection.intersectionType == EIntersectionType::TwoIntersectiont)
        {
            intersection.normalI2 = Referential::localToGlobalVector(orientedBox.getReferential(), intersection.normalI2);
        }

        return true;
    }

    return intersection.intersectionType != EIntersectionType::NoIntersection;
}