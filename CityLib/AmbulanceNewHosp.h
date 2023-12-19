/**
 * @file AmbulanceNewHosp.h
 * @author Aaron Ngo
 *
 * Concrete visitor class derived from TileVisitor to locate
 * a new valid hospital landing tile when deletion occurs
 */

#ifndef CITY_CITYLIB_AMBULANCENEWHOSP_H
#define CITY_CITYLIB_AMBULANCENEWHOSP_H

#include "TileVisitor.h"
#include "TileHospital.h"

/**
 * Concrete visitor class derived from TileVisitor to locate
 * a new valid hospital landing tile when deletion occurs
 */
class AmbulanceNewHosp : public TileVisitor
{
private:
    /// The tile of the new hospital found after deletion
    TileHospital* mNewHospital = nullptr;
public:
    /**
     * Visit a TileHospital object
     * @param hospital Building we are visiting
     */
    void VisitHospital(TileHospital* hospital) override
    {
        if (hospital->GetAmbulance() == nullptr)
        {
            mNewHospital = hospital;
        }
    }

    /**
     * Get the destination hospital tile
     * @return mNewHospital
     */
    TileHospital* GetNewHospital() const { return mNewHospital; }
};

#endif //CITY_CITYLIB_AMBULANCENEWHOSP_H
