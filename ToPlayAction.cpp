#include "../Phase2 - Project Framework/ToPlayAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"
#include "../Phase2 - Project Framework/GUI/Output.h"


ToPlayAction::ToPlayAction(ApplicationManager *pApp) :Action(pApp)
{}

void ToPlayAction::Execute() {
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Switched to Play Mode! Let's Play!");
}