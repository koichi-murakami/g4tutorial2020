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
  Geometry::Geometry(){}
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
   G4double leng_X_World = 2.0*m;         // X-full-length of world 
   G4double leng_Y_World = 2.0*m;         // Y-full-length of world 
   G4double leng_Z_World = 2.0*m;         // Z-full-length of world 
   G4Box* solid_World = 
     new G4Box("Solid_World", leng_X_World/2.0, leng_Y_World/2.0, leng_Z_World/2.0);

   // Define logical volume
   G4Material* materi_World = materi_Man->FindOrBuildMaterial("G4_AIR");
   G4LogicalVolume* logVol_World = 
     new G4LogicalVolume(solid_World, materi_World, "LogVol_World");
   logVol_World->SetVisAttributes (G4VisAttributes::Invisible);

   // Placement of logical volume
   G4int copyNum_World = 0;               // Set ID number of world
   G4PVPlacement* physVol_World  = 
     new G4PVPlacement(G4Transform3D(), "PhysVol_World", logVol_World, 0, 
                       false, copyNum_World);

// Define 'BGO Detector'
   // Define the shape of solid
   G4double radius_BGO = 4.8 *cm;
   G4double leng_Z_BGO = 1.12 *cm;
   G4Tubs* solid_BGO = new G4Tubs("Solid_BGO", 0., radius_BGO, leng_Z_BGO/2.0, 0., 360.*deg); 

   // Define logical volume
   G4Material* materi_BGO = materi_Man->FindOrBuildMaterial("G4_BGO");
   G4LogicalVolume* logVol_BGO = 
     new G4LogicalVolume( solid_BGO, materi_BGO, "LogVol_BGO", 0, 0, 0 );


// Placement of logical volume - i-th BGO
    G4int noBGO = 20;

   G4double pos_X_LogV = 0.0*cm;           // X-location LogV
   G4double pos_Y_LogV = 0.0*cm;           // Y-location LogV

  for(G4int i=0; i<noBGO; i++){
      G4double pos_Z_LogV =  (i+1)*leng_Z_BGO;          // Z-location LogV
      G4ThreeVector threeVect_LogV = G4ThreeVector(pos_X_LogV, pos_Y_LogV, pos_Z_LogV);
      G4RotationMatrix rotMtrx_LogV = G4RotationMatrix();
      G4Transform3D trans3D_LogV = G4Transform3D(rotMtrx_LogV, threeVect_LogV);
  
      G4int copyNum_LogV = 1000+i;                // Set ID number of LogV
      new G4PVPlacement(trans3D_LogV, "PhysVol_BGO", logVol_BGO, physVol_World,
                     false, copyNum_LogV);
  }

// Sensitive volume
    auto aSV = new SensitiveVolume("SensitiveVolume");
    logVol_BGO->SetSensitiveDetector(aSV);         // Add sensitivity to the logical volume
    auto SDman = G4SDManager::GetSDMpointer();
    SDman->AddNewDetector(aSV);

// Return the physical world
   return physVol_World;
}
