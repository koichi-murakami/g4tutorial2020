
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Application: Tutorial course for Hep/Medicine Users
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "UserActionInitialization.hh"
#include "G4ScoringManager.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

//-------------------------------------------------------------------------------
  int main( int argc, char** argv )
//-------------------------------------------------------------------------------
{
// Construct the default run manager
   auto runManager = new G4RunManager;
// Activate UI-command base scorer
    G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
    scManager->SetVerboseLevel(1);

// Set up mandatory user initialization: Geometry
   runManager->SetUserInitialization( new Geometry );

// Set up mandatory user initialization: Physics-List
   runManager->SetUserInitialization( new FTFP_BERT );

// Set up user initialization: User Actions
   runManager->SetUserInitialization( new UserActionInitialization );

// Initialize G4 kernel
   runManager->Initialize();

// Create visualization environment
   auto visManager = new G4VisExecutive;
   visManager->Initialize();

// Start interactive session
   auto uiExec = new G4UIExecutive( argc, argv );
   G4UImanager*  uiManager = G4UImanager::GetUIpointer();
   uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );
   uiExec->SessionStart();

// Job termination
   delete uiExec;
   delete visManager;
   delete runManager;

   return 0;
}
