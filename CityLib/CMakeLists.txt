project(CityLib)

set(SOURCE_FILES
        pch.h
        City.h City.cpp
        Tile.h Tile.cpp
        CityReport.h CityReport.cpp
        MemberReport.h MemberReport.cpp
        TileBuilding.h TileBuilding.cpp
        TileLandscape.h TileLandscape.cpp
        MainFrame.cpp MainFrame.h
        CityReport.cpp CityView.cpp CityView.h ids.h
        AirAmbulance.cpp AirAmbulance.h
        TileHospital.cpp TileHospital.h
        TileLandable.cpp
        TileLandable.h
        TileGrass.cpp
        TileGrass.h
        TileVisitor.cpp
        TileVisitor.h
        BuildingCounter.cpp
        BuildingCounter.h
        AmbulanceDisplay.cpp
        AmbulanceDisplay.h
        AmbulanceLaunch.cpp
        AmbulanceLaunch.h
        AmbulanceNewHosp.cpp
        AmbulanceNewHosp.h
        AmbulanceRemoveAssoc.cpp
        AmbulanceRemoveAssoc.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)