/**
 * @file AmbulanceDisplay.h
 * @author Aaron Ngo
 *
 * Concrete visitor class derived from TileVisitor to display the
 * ambulance on the first hospital
 */

#ifndef CITY_CITYLIB_AMBULANCEDISPLAY_H
#define CITY_CITYLIB_AMBULANCEDISPLAY_H

#include "TileVisitor.h"
#include "TileLandable.h"

/**
 * Concrete visitor class derived from TileVisitor to display the
 * ambulance on the first hospital
 */
class AmbulanceDisplay : public TileVisitor
{
private:
    /// bool to determine whether or not there is an ambulance present
    bool mAmbulancePresent = false;
public:
    /**
     * Get the bool of the ambulance's presence
     * @return Bool of ambulance's presence
     */
    bool GetAmbulancePresence () const { return mAmbulancePresent; }
    /**
     * Visit TileLandable object
     * @param landable tile we are visiting
     */
    void VisitLandable(TileLandable* landable) override
    {
        if (landable->GetAmbulance() != nullptr)
        {
            mAmbulancePresent = true;
        }
    }

};

#endif //CITY_CITYLIB_AMBULANCEDISPLAY_H
