//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"
#include "SensitiveVolume.hh"
#include "G4SDManager.hh"
//------------------------------------------------------------------------------
  Geometry::Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  Geometry::~Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  G4VPhysicalVolume* Geometry::Construct()
//------------------------------------------------------------------------------
{
// Get pointer to 'Material Manager'
   G4NistManager* materi_Man = G4NistManager::Instance();

// Define 'World Volume'
   // Define the shape of solid
   G4double leng_X_World = 2.0*m;           // X-full-length of world
   G4double leng_Y_World = 2.0*m;           // Y-full-length of world
   G4double leng_Z_World = 2.0*m;           // Z-full-length of world
   auto solid_World =
     new G4Box( "Solid_World", leng_X_World/2.0, leng_Y_World/2.0, leng_Z_World/2.0 );

   // Define logical volume
   G4Material* materi_World = materi_Man->FindOrBuildMaterial( "G4_AIR" );
   auto logVol_World = new G4LogicalVolume( solid_World, materi_World, "LogVol_World" );
   logVol_World->SetVisAttributes ( G4VisAttributes::Invisible );

// Placement of 'World Volume'
   G4int copyNum_World = 0;                 // Set ID number of world
   auto physVol_World  = new G4PVPlacement( G4Transform3D(), "PhysVol_World",
                                           logVol_World, 0, false, copyNum_World );

// Define 'BGO Detector'
   // Define the shape of solid
   G4double radius_BGO = 2.5*cm;
   G4double leng_Z_BGO = 2.5*cm;
   auto solid_BGO = new G4Tubs( "Solid_BGO", 0., radius_BGO, leng_Z_BGO/2.0, 0.,
                                360.*deg );

   // Define logical volume
   G4Material* materi_BGO = materi_Man->FindOrBuildMaterial( "G4_BGO" );
   auto logVol_BGO = new G4LogicalVolume( solid_BGO, materi_BGO, "LogVol_BGO",
                                          0, 0, 0 );

// Placement of two 'BGO Detectors' into 'World Volume'
   // Create G4Transform3D to define rotation/translation
   G4double pos_X_LogV = 0.0*cm;            // X-location LogV
   G4double pos_Y_LogV = 0.0*cm;            // Y-location LogV
   G4double pos_Z_LogV =-2.0*cm;            // Z-location LogV
   auto threeVect_LogV = G4ThreeVector( pos_X_LogV, pos_Y_LogV, pos_Z_LogV );
   auto rotMtrx_LogV   = G4RotationMatrix();
   auto trans3D_LogV   = G4Transform3D( rotMtrx_LogV, threeVect_LogV );

   // Install 1st 'BGO Detector'
   G4int copyNum_LogV = 1000;               // Set ID number of LogV
   new G4PVPlacement( trans3D_LogV, "PhysVol_BGO", logVol_BGO,
                      physVol_World, false, copyNum_LogV, true );

   // Install 2nd 'BGO Detector'
   copyNum_LogV = 2000;                     // Set ID number of LogV
   pos_Z_LogV = +2.0*cm;                    // Z-location LogV
   threeVect_LogV = G4ThreeVector( pos_X_LogV, pos_Y_LogV, pos_Z_LogV );
   trans3D_LogV = G4Transform3D( rotMtrx_LogV, threeVect_LogV );

   new G4PVPlacement( trans3D_LogV, "PhysVol_BGO", logVol_BGO,
                      physVol_World, false, copyNum_LogV, true );

// Sensitive volume
    auto aSV = new SensitiveVolume("SensitiveVolume");
    logVol_BGO->SetSensitiveDetector(aSV);         // Add sensitivity to the logical volume
    auto SDman = G4SDManager::GetSDMpointer();
    SDman->AddNewDetector(aSV);

// Return the physical volume of 'World'
   return physVol_World;
}
