/**
 * @file TileGrass.h
 * @author Charles Owen
 *
 * Class that implements grass tiles
 */

#ifndef CITY_CITYLIB_TILEGRASS_H
#define CITY_CITYLIB_TILEGRASS_H

#include "TileLandable.h"

class TileVisitor;

/**
 * Class that implements grass tiles
 */
class TileGrass : public TileLandable
{
private:

public:
    TileGrass(City *city);

    ///  Default constructor (disabled)
    TileGrass() = delete;

    ///  Copy constructor (disabled)
    TileGrass(const TileGrass &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override;
};

#endif //CITY_CITYLIB_TILEGRASS_H
