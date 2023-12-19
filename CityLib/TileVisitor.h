/**
 * @file TileVisitor.h
 * @author Aaron Ngo
 *
 * Tile visitor base class.
 */

#ifndef CITY_CITYLIB_TILEVISITOR_H
#define CITY_CITYLIB_TILEVISITOR_H

// Forward references to all tile types
class TileBuilding;
class TileLandscape;
class TileGrass;
class TileHospital;
class TileLandable;

/**
 * Tile visitor base class
 */
class TileVisitor
{
protected:
    /**
     * Constructor
     * Ensures this is an abstract class
     */
    TileVisitor() {}

public:
    virtual ~TileVisitor() {}

    /**
     * Visit a TileBuilding object
     * @param building Building we are visiting
     */
    virtual void VisitBuilding(TileBuilding* building) {}

    /**
     * Visit a TileLandscape object
     * @param landscape Landscape tile we are visiting
     */
    virtual void VisitLandscape(TileLandscape* landscape) {}

    /**
     * Visit a TileGrass object
     * @param grass Grass tile we are visiting
     */
    virtual void VisitGrass(TileGrass* grass) {}

    /**
     * Visit a TileHospital tile
     * @param hospital Tile object we are visiting
     */
    virtual void VisitHospital(TileHospital* hospital) {}

    /**
     * Visit a TileLandable tile
     * @param landable TileLandable tile we are visiting
     */
    virtual void VisitLandable(TileLandable* landable) {}
};


#endif //CITY_CITYLIB_TILEVISITOR_H
