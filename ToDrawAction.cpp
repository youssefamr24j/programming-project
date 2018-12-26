#include "../Phase2 - Project Framework/ToDrawAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"


ToDrawAction::ToDrawAction(ApplicationManager *pApp) :Action(pApp)
{
}

void ToDrawAction::Execute()
{
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();

	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Switched to Draw Mode! Let's Draw! ");
}

