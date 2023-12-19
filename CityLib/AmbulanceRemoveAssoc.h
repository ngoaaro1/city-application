/**
 * @file AmbulanceRemoveAssoc.h
 * @author Aaron Ngo
 *
 * Concrete Visitor class derived from TileVisitor to remove
 * all tile associations with ambulance except one associated
 * with ambulance
 */

#ifndef CITY_CITYLIB_AMBULANCEREMOVEASSOC_H
#define CITY_CITYLIB_AMBULANCEREMOVEASSOC_H

#include "TileVisitor.h"
#include "TileLandable.h"

/**
 * Concrete Visitor class derived from TileVisitor to remove
 * all tile associations with ambulance except one associated
 * with ambulance
 */
class AmbulanceRemoveAssoc : public TileVisitor
{
private:
    /// The only tile that should contain an association to ambulance
    TileLandable* mAmbulanceTile;
public:
    /**
     * Constructor AmbulanceRemoveAssoc to assign the ambulance
     * associated tile
     * @param newAmbulanceTile
     */
    AmbulanceRemoveAssoc(TileLandable* newAmbulanceTile)
    {
        mAmbulanceTile = newAmbulanceTile;
    }
    /**
     * Visit a TileLandable object
     * @param landable Landable we are visiting
     */
    void VisitLandable(TileLandable* landable) override
    {
        if (landable != mAmbulanceTile)
        {
            landable->SetAmbulance(nullptr);
        }
    }
};

#endif //CITY_CITYLIB_AMBULANCEREMOVEASSOC_H
