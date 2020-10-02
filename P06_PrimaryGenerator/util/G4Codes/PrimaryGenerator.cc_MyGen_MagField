//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PrimaryGenerator.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "PrimaryGenerator.hh"
#include "G4Event.hh"
#include "G4PrimaryVertex.hh"
#include "G4PrimaryParticle.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//------------------------------------------------------------------------------
  PrimaryGenerator::PrimaryGenerator()
//------------------------------------------------------------------------------
{}

//------------------------------------------------------------------------------
  PrimaryGenerator::~PrimaryGenerator()
//------------------------------------------------------------------------------
{}

//------------------------------------------------------------------------------
  void PrimaryGenerator::GeneratePrimaries( G4Event* anEvent )
//------------------------------------------------------------------------------
{
// Particle table
   G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();

// Create a primary particle - need to create for every event
   G4String particleName = "e-";
   G4double momentum = 50.0*MeV;
   G4ThreeVector momentumDirection = G4ThreeVector{ 0.0, 0.0, 1.0 };
   G4ThreeVector momVect = momentumDirection*momentum;
   auto primaryParticle =
     new G4PrimaryParticle{ particleTable->FindParticle( particleName ),
                              momVect.x(), momVect.y(), momVect.z() };

// Create a 2nd primary particle - need to create for every event
   particleName = "e+";
   auto primaryParticle_2nd =
     new G4PrimaryParticle{ particleTable->FindParticle( particleName ),
                              momVect.x(), momVect.y(), momVect.z() };

// Create a primary vertex - need to create for every event
   G4double pos_X = 2.0*mm*( G4UniformRand()-0.5 );
   G4double pos_Y = 2.0*mm*( G4UniformRand()-0.5 );
   G4double pos_Z = -2.0*cm;
   auto vertex = G4ThreeVector{ pos_X, pos_Y, pos_Z };
   G4double time_Zero = 0.0*ns;
   auto primaryVertex = new G4PrimaryVertex{ vertex, time_Zero };

// Add the primary particles to the primary vertex
   primaryVertex->SetPrimary( primaryParticle );
   primaryVertex->SetPrimary( primaryParticle_2nd );

// Add the vertex to the event
   anEvent->AddPrimaryVertex( primaryVertex );
}
