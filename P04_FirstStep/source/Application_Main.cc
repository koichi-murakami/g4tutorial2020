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
// Construct the default run manager
   auto runManager = new G4RunManager{};

// Set up mandatory user initialization: Geometry
   runManager->SetUserInitialization( new Geometry{} );

// Set up mandatory user initialization: Physics-List
   runManager->SetUserInitialization( new FTFP_BERT{} );

// Set up user initialization: User Actions
   runManager->SetUserInitialization( new UserActionInitialization{} );

// Initialize G4 kernel
   runManager->Initialize();

// Create visualization environment
   auto visManager = new G4VisExecutive{};
   visManager->Initialize();

// Get UI (User Interface) manager
   G4UImanager* uiManager = G4UImanager::GetUIpointer();

// Switch batch or interactive mode
   if ( argc == 1 ) {  // Interactive mode - no command argument
     auto uiExec = new G4UIExecutive{ argc, argv };
     uiExec->SessionStart();
     delete uiExec;
   } else {            // Batch mode - 1st command argument is a macro-filename
     G4String macroName = argv[1];
     uiManager->ApplyCommand( "/control/execute " + macroName );
   }

// Job termination
   delete visManager;
   delete runManager;

   return 0;
}
