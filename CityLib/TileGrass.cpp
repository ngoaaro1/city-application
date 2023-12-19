/**
 * @file TileGrass.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "TileGrass.h"
#include "City.h"
#include "MemberReport.h"


/// AirAmbulance offset to draw in the x dimension in pixels
const double GrassAmbulanceOffsetX = -35;

/// AirAmbulance offset to draw in the y dimension in pixels
const double GrassAmbulanceOffsetY = -25;


/** Constructor
* @param city The city this is a member of
*/
TileGrass::TileGrass(City *city) : TileLandable(city)
{
    SetAmbulanceOffset(GrassAmbulanceOffsetX, GrassAmbulanceOffsetY);
}


/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileGrass::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"grass");
    itemNode->AddAttribute(L"file", GetFile());

    return itemNode;
}


/**
* Load the attributes for an item node.
* @param node The Xml node we are loading the item from
*/
void TileGrass::XmlLoad(wxXmlNode* node)
{
    TileLandable::XmlLoad(node);
    SetImage(node->GetAttribute(L"file").ToStdWstring());
}

/**
 * Generate a report for this Grass tile.
 * @param report 
*/
void TileGrass::Report(std::shared_ptr<MemberReport> report)
{
    report->SetReport(L"Grass");
}

/**
 * Accept a visitor
 * @param visitor The visitor we accept
 */
void TileGrass::Accept(TileVisitor *visitor)
{
    TileLandable::Accept(visitor);
    visitor->VisitGrass(this);
}
