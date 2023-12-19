/**
 * @file AmbulanceLaunch.h
 * @author Aaron Ngo
 *
 * Concrete visitor class derived from TileVisitor to
 * launch ambulance by locating valid landing and launching tiles
 */

#ifndef CITY_CITYLIB_AMBULANCELAUNCH_H
#define CITY_CITYLIB_AMBULANCELAUNCH_H

#include "TileVisitor.h"
#include "TileLandable.h"

/**
 * Concrete visitor class derived from TileVisitor to
 * launch ambulance by locating valid landing and launching tiles
 */
class AmbulanceLaunch : public TileVisitor
{
private:
    /// The tile that was clicked on
    Tile* mClickedTile;
    /// The tile that the ambulance will move to/land on
    TileLandable* mDestination = nullptr;
    /// The tile that contains the ambulance association
    TileLandable* mAmbulanceLocation = nullptr;

public:
    /**
     * Constructor for AmbulanceLaunch visitor
     * @param tile Tile that was double clicked on
     */
    AmbulanceLaunch(Tile* tile)
    {
        mClickedTile = tile;
    }
    /**
     * Visit TileLandable object
     * @param landable tile we are visiting
     */
    void VisitLandable(TileLandable* landable) override
    {
        if (landable->GetAmbulance() != nullptr)
        {
            mAmbulanceLocation = landable;
        }
        if (landable == mClickedTile) {
            mDestination = landable;
        }
    }

    /**
     * Get the destination landable tile
     * @return mDestination
     */
    TileLandable* GetDestination() const { return mDestination; }
    /**
     * Get the ambulance landable tile location
     * @return mAmbulanceLocation
     */
    TileLandable* GetAmbulanceLocation() const { return mAmbulanceLocation; }
};

#endif //CITY_CITYLIB_AMBULANCELAUNCH_H
