/**
 * @file TileLandable.h
 * @author Charles Owen
 *
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */

#ifndef CITY_CITYLIB_TILELANDABLE_H
#define CITY_CITYLIB_TILELANDABLE_H

#include "Tile.h"
#include "AirAmbulance.h"

/**
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */
class TileLandable : public Tile
{
private:

    /// Air Ambulance drawing offset. This is used to
    /// put the ambulance the correct x,y location on
    /// a hospital roof or a grass tile.
    wxRealPoint mAmbulanceOffset;

    /// Pointer to the one air ambulance object that will
    /// travelling between landable tiles
    std::shared_ptr<AirAmbulance> mAmbulance;

protected:
    TileLandable(City *city);

public:
    /// Default constructor (disabled)
    TileLandable() = delete;

    /// Copy constructor (disabled)
    TileLandable(const TileLandable &) = delete;

    /// Assignment operator
    void operator=(const TileLandable &) = delete;

    /**
     * Get the ambulance offset relative to this tile.
     * @return Ambulance offset
     */
    const wxRealPoint &GetAmbulanceOffset() const {return mAmbulanceOffset;}

    /**
     * Set the ambulance offset relative to this tile.
     * @param x Ambulance X offset
     * @param y Ambulance Y offset
     */
    void SetAmbulanceOffset(double x, double y) {mAmbulanceOffset.x = x; mAmbulanceOffset.y = y;}

    void AirAmbulanceIsGone();
    void AirAmbulanceHasLanded();
    bool PendingDelete() override;

    /**
     * Getter to retrieve mAmbulance pointer member variable
     * @return mAmbulance pointer
     */
    std::shared_ptr<AirAmbulance> GetAmbulance() { return mAmbulance; }
    /**
     * Setter to set mAmbulance pointer member variable
     * @param ambulance that gets set to mAmbulance
     */
    void SetAmbulance(std::shared_ptr<AirAmbulance> ambulance) { mAmbulance = ambulance; }
    /**
     * Function used to draw tile with upcall and the air ambulance
     * @param dc
     */
    void Draw(wxDC *dc);
    /**
     * Handles updates for animation
     * @param elapsed
     */
    void Update(double elapsed);

    /**
     * Accept function that covers all landable types
     * TileGrass and TileHospital
     * @param visitor
     */
    virtual void Accept(TileVisitor* visitor) override
    {
        visitor->VisitLandable(this);
    }
};

#endif //CITY_CITYLIB_TILELANDABLE_H
