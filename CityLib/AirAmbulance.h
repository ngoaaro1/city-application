/**
 * @file AirAmbulance.h
 *
 * @author Charles B. Owen
 *
 * Class the implements an air ambulance
 */

#pragma once

#include <memory>

class City;
class TileLandable;

/**
 * Class the implements an air ambulance
*/
class AirAmbulance
{
private:
    wxRealPoint ComputePosition();
    bool IsLowerOwner(TileLandable* tile);

    /// The image of the air ambulance
    std::unique_ptr<wxBitmap> mImage;

    /// The launching tile for the air ambulance
    TileLandable* mLaunchingTile = nullptr;

    /// The landing tile for the air ambulance
    TileLandable* mLandingTile = nullptr;

    /// Current position of the ambulance in flight
    /// as a T value from 0 to 1.
    double mT = 0;

    /// Speed of the ambulance in t units per second
    double mSpeed = 0;

public:
    AirAmbulance(City* city);

    void SetLaunchingTile(TileLandable* tile);
    void SetLandingTile(TileLandable* tile);

    void Update(TileLandable* tile, double elapsed);

    void Draw(TileLandable* tile, wxDC* dc);

    bool InFlight();
};

