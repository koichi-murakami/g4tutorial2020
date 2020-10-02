//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Application: Tutorial course for Hep/Medicine Users
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "UserActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

//-------------------------------------------------------------------------------
  int main( int argc, char** argv )
//-------------------------------------------------------------------------------
{
   G4UIExecutive* uiExec = 0;
  if( argc == 1){
    uiExec = new G4UIExecutive( argc, argv );
 }

// Construct the default run manager
   auto runManager = new G4RunManager;

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
// process macro or start UI session
   G4UImanager*  uiManager = G4UImanager::GetUIpointer();
   if( !uiExec){  // batch mode
	G4String command = "/control/execute ";
	G4String fileName = argv[1];
	uiManager->ApplyCommand(command + fileName);
}
else {  // interactive mode
// Start interactive session
   uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );
   uiExec->SessionStart();
   delete uiExec;
}
// Job termination
//   delete uiExec;
   delete visManager;
   delete runManager;

   return 0;
}
