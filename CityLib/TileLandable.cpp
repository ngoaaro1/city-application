/**
 * @file TileLandable.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "TileLandable.h"
#include "City.h"
#include "AmbulanceNewHosp.h"
#include "AmbulanceRemoveAssoc.h"

/**
 * Constructor
 * @param city City this tile belongs to
 */
TileLandable::TileLandable(City *city) : Tile(city)
{

}


/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool TileLandable::PendingDelete()
{
    if (mAmbulance != nullptr)
    {
        AmbulanceNewHosp visitor1;
        City* city = GetCity();
        city->Accept(&visitor1);
        TileHospital* newHospital = visitor1.GetNewHospital();

        if (newHospital)
        {
            newHospital->SetAmbulance(mAmbulance);
            mAmbulance->SetLaunchingTile(newHospital);
        }

        AmbulanceRemoveAssoc visitor2(newHospital);
        city->Accept(&visitor2);

    }
    return true;

}

/**
 * This function is called when the AirAmbulance has
 * landed on some other tile. It is no longer accessible to
 * this tile.
*/
void TileLandable::AirAmbulanceIsGone()
{
    mAmbulance = nullptr;
}

/**
 * This function is called when the AirAmbulance has landed on this
 * tile. This tile should now become the launching tile.
*/
void TileLandable::AirAmbulanceHasLanded()
{
    mAmbulance->SetLaunchingTile(this);
}

void TileLandable::Draw(wxDC *dc)
{
    Tile::Draw(dc);
    if (mAmbulance != nullptr)
    {
        mAmbulance->Draw(this, dc);
    }
}

void TileLandable::Update(double elapsed)
{
    Tile::Update(elapsed);
    if (mAmbulance != nullptr)
    {
        mAmbulance->Update(this, elapsed);
    }
}