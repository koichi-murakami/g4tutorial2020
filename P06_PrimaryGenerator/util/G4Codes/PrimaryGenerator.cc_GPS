//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PrimaryGenerator.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "PrimaryGenerator.hh"
#include "G4GeneralParticleSource.hh"

//------------------------------------------------------------------------------
  PrimaryGenerator::PrimaryGenerator()
  : fpParticleGPS{nullptr}
//------------------------------------------------------------------------------
{
  fpParticleGPS = new G4GeneralParticleSource{};
}

//------------------------------------------------------------------------------
  PrimaryGenerator::~PrimaryGenerator()
//------------------------------------------------------------------------------
{
  delete fpParticleGPS;
}

//------------------------------------------------------------------------------
  void PrimaryGenerator::GeneratePrimaries( G4Event* anEvent )
//------------------------------------------------------------------------------
{
  fpParticleGPS->GeneratePrimaryVertex( anEvent );
}
