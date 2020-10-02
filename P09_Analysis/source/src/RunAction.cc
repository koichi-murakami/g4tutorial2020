#include "RunAction.hh"
#include "Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
 : G4UserRunAction()
{
    // Get analysis manager
    auto analysisManager = G4AnalysisManager::Instance();
    //G4cout << "Using " << analysisManager->GetType() << G4endl;
    analysisManager->SetActivation(true);

    analysisManager->SetVerboseLevel(1);
    analysisManager->SetFileName("");
    
	// creating a Ntuple for all

     analysisManager-> CreateNtuple( "P09",  "eDep and stepLength");
     analysisManager->CreateNtupleDColumn( "sum_eDep");
     analysisManager->CreateNtupleDColumn( "sum_stepLength");
//     analysisManager->CreateNtupleDColumn( "sum_eDep_2");
//     analysisManager->CreateNtupleDColumn( "sum_stepLength_2");

     analysisManager->FinishNtuple();

/* no use of H1s
    // Creating H1 histograms


     G4int id = analysisManager->CreateH1("h1:0","sum_eDep_1", 100, 0., 5.*MeV);
	analysisManager->SetH1Activation(id, false);
           id = analysisManager->CreateH1("h1:1","sum_stepLength_1", 100, 0., 5.*mm);
	analysisManager->SetH1Activation(id, false);
           id = analysisManager->CreateH1("h1:2","sum_eDep_2", 100, 0., 5.*MeV);
	analysisManager->SetH1Activation(id, false);
           id = analysisManager->CreateH1("h1:3","sum_stepLength_2", 100, 0., 5.*mm);
	analysisManager->SetH1Activation(id, false);
*/

  }

RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();  
}

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 
  // Get analysis manager
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  analysisManager->OpenFile();
    //G4cout << "File " << fileName << " Open" <<G4endl;
}

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  // save the file and close
  analysisManager->Write();
  analysisManager->CloseFile();
}
