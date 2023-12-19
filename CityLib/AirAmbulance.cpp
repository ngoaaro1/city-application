/**
 * @file AirAmbulance.cpp
 * @author Charles B. Owen
 */
#include "pch.h"
#include <string>
#include "AirAmbulance.h"
#include "TileLandable.h"


/// The Air AirAmbulance image
const std::wstring AirAmbulanceImage = L"images/airambulance.png";

/// Bezier speed in the Y direction for curve slopw
const double AmbulanceBezierY = 100;

/// Default AirAmbulance speed in t values per second
const double AmbulanceSpeed = 0.5;

/**
 * Constructor
 * @param city City this AirAmbulance is associated with.
*/
AirAmbulance::AirAmbulance(City* city)
{
    mImage = std::make_unique<wxBitmap>(AirAmbulanceImage, wxBITMAP_TYPE_ANY);
}

/**
 * Set the ambulance launching tile.
 * 
 * Whenever the launching tile is set, the ambulance is reset
 * to a ready-to-launch condition on the tile.
 * @param tile New ambulance launching tile
*/
void AirAmbulance::SetLaunchingTile(TileLandable* tile)
{
    mLandingTile = nullptr;
    mLaunchingTile = tile;
    mSpeed = 0;
    mT = 0;
}

/**
 * Set the ambulance landing tile.
 * This initiates the ambulance flight from launch tile to landing tile.
 * @param tile New ambulance landing tile.
*/
void AirAmbulance::SetLandingTile(TileLandable* tile)
{
    mLandingTile = tile;
    mSpeed = AmbulanceSpeed;
    mT = 0;
}

/**
 * Update the AirAmbulance in time. This allows the ambulance to fly.
 * 
 * If the AirAmbulance is pointed to by both a launching and landing
 * tile, the update will only be done when called from the
 * tile that is the lower on the screen (maximum Y value)
 * 
 * @param tile Tile this function is called from.
 * @param elapsed Elasped time in seconds.
*/
void AirAmbulance::Update(TileLandable* tile, double elapsed)
{
    if (!IsLowerOwner(tile))
    {
        return;
    }

    mT += elapsed * mSpeed;

    if (mT > 1)
    {
        mT = 1;
        mSpeed = 0;

        // We have landed
        if (mLandingTile != mLaunchingTile)
        {
            mLaunchingTile->AirAmbulanceIsGone();
        }

        mLandingTile->AirAmbulanceHasLanded();
    }

}

/**
 * Draw the AirAmbulance
 * 
 * If the AirAmbulance is pointed to by both a launching and landing
 * tile, the drawing will only be done when called from the
 * tile that is the lower on the screen (maximum Y value)
 * 
 * @param tile The tile object that called the draw.
 * @param dc Device context to draw the AirAmbulance on.
*/
void AirAmbulance::Draw(TileLandable *tile, wxDC* dc)
{
    if (!IsLowerOwner(tile))
    {
        return;
    }

    if (mImage != nullptr)
    {
        auto position = ComputePosition();

        int wid = mImage->GetWidth();
        int hit = mImage->GetHeight();

        dc->DrawBitmap(*mImage, position.x, position.y);
    }
}

/**
 * Determine if this tile is the lower (int Y) of two tiles owning
 * the AirAmbulance. If only owned by one, return true.
 * @param tile Tile to test
 * @return True if tile is the lower tile or AirAmbulance has only one owner.
*/
bool AirAmbulance::IsLowerOwner(TileLandable *tile)
{
    // Smart drawing and updating. We only draw 
    // or update when called by the lowest tile
    // when we are pointed to by more than one tile.
    if (mLaunchingTile != nullptr && mLandingTile != nullptr)
    {
        if (mLaunchingTile->GetY() > mLandingTile->GetY())
        {
            // Only draw if called by the launching tile
            if (tile != mLaunchingTile)
            {
                return false;
            }
        }
        else
        {
            // Only draw if called by the landing tile
            if (tile != mLandingTile)
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * Is this AirAmbulance in flight right now?
 * @return true if AirAmbulance is inflight
*/
bool AirAmbulance::InFlight()
{
    return mSpeed > 0;
}


/**
 * Compute a position for the AirAmbulance.
 * @return Position as a PointF object.
*/
wxRealPoint AirAmbulance::ComputePosition()
{
    if (mLaunchingTile != nullptr)
    {
        if (mLandingTile == nullptr)
        {
            // We have a launching tile, but no landing
            // tile. Just return the launching tile location
            return wxRealPoint(mLaunchingTile->GetX(), mLaunchingTile->GetY())
                            + mLaunchingTile->GetAmbulanceOffset();
        }

        // We are in flight
        auto launchingTileOffset = mLaunchingTile->GetAmbulanceOffset();
        auto landingTileOffset = mLandingTile->GetAmbulanceOffset();

        double x1 = mLaunchingTile->GetX() + launchingTileOffset.x;
        double y1 = mLaunchingTile->GetY() + launchingTileOffset.y;
        double x4 = mLandingTile->GetX() + landingTileOffset.x;
        double y4 = mLandingTile->GetY() + landingTileOffset.y;

        double x2 = x1;
        double y2 = y1 - AmbulanceBezierY;
        double x3 = x4;
        double y3 = y4 - AmbulanceBezierY;

        double t = mT;

        // Compute Bezier curve basis functions
        double b1 = (1 - t) * (1 - t) * (1 - t);
        double b2 = 3 * (1 - t) * (1 - t) * t;
        double b3 = 3 * (1 - t) * t * t;
        double b4 = t * t * t;

        return wxRealPoint(
            (x1 * b1 + x2 * b2 + x3 * b3 + x4 * b4),
            (y1 * b1 + y2 * b2 + y3 * b3 + y4 * b4)
        );

    }
    else
    {
        return wxRealPoint(0, 0);
    }
}
