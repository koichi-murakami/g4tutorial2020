//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// MyPhysicsList.cc
//  [Note] Based on "G4 Basic Example: B3"
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "MyPhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"

//------------------------------------------------------------------------------
  MyPhysicsList::MyPhysicsList()
  : G4VModularPhysicsList{}
//------------------------------------------------------------------------------
{
// Default physics
   RegisterPhysics( new G4DecayPhysics{} );

// Radioactive decay
   RegisterPhysics( new G4RadioactiveDecayPhysics{} );

// EM physics
   RegisterPhysics( new G4EmStandardPhysics{} );
}

//------------------------------------------------------------------------------
  MyPhysicsList::~MyPhysicsList()
//------------------------------------------------------------------------------
{}

//------------------------------------------------------------------------------
  void MyPhysicsList::SetCuts()
//------------------------------------------------------------------------------
{
    G4VUserPhysicsList::SetCuts();
}
