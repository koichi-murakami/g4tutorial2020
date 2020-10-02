//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Geometry_h
#define Geometry_h 1

#include "G4VUserDetectorConstruction.hh"
class G4VPhysicalVolume;

//------------------------------------------------------------------------------
  class Geometry : public G4VUserDetectorConstruction
//------------------------------------------------------------------------------
{
  public:
    Geometry();
   ~Geometry();

    G4VPhysicalVolume* Construct();
};
#endif
