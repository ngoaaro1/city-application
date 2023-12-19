/**
 * @file BuildingCounter.h
 * @author Aaron Ngo
 *
 * Concrete visitor class derived from TileVisitor to
 * count all building tiles
 */

#ifndef CITY_CITYLIB_BUILDINGCOUNTER_H
#define CITY_CITYLIB_BUILDINGCOUNTER_H

#include "TileVisitor.h"

/**
 * Concrete visitor class derived from TileVisitor to
 * count all building tiles
 */
class BuildingCounter : public TileVisitor
{
private:
    /// Buildings counter
    int mNumBuildings = 0;

public:
    /**
     * Get the number of buildings
     * @return Number of buildings
     */
    int GetNumBuildings() const { return mNumBuildings; }

    /**
     * Visit a TileBuilding object
     * @param building Building we are visiting
     */
    void VisitBuilding(TileBuilding* building) override
    {
        mNumBuildings++;
    }

};

#endif //CITY_CITYLIB_BUILDINGCOUNTER_H
