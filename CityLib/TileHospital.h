/**
 * @file TileHospital.h
 *
 * @author Charles B. Owen
 *
 * Class that implements a hospital.
 *
 * A hospital is a landable tile for the air ambulance
 */

#pragma once

#include "TileLandable.h"

class TileVisitor;


/**
 * Class that implements a hospital.
 *
 * A hospital is a landable tile for the air ambulance
*/
class TileHospital : public TileLandable
{
private:

public:
    TileHospital(City* city);

    ///  Default constructor (disabled)
    TileHospital() = delete;

    ///  Copy constructor (disabled)
    TileHospital(const TileHospital&) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    virtual void Report(std::shared_ptr<MemberReport> report) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override;


};

