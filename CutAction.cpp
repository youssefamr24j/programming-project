#include "../Phase2 - Project Framework/CutAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"



CutAction::CutAction(ApplicationManager*pApp) :Action(pApp)
{
}
void CutAction::ReadActionParameters()
{
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();
	Output* pOut = pManager->GetOutput();


	if (SelectedFigs[0] != NULL)
		pOut->PrintMessage("Cut figure : Selected figures moved into clipboard");

	if (SelectedFigs[0] == NULL)
		pOut->PrintMessage("Cut figure : Select a figure first");
}
void CutAction::Execute()
{
	ReadActionParameters();
	if (SelectedFigs[0] != NULL)
	{
		for (int i = 0; i < selectedCount; i++)
			SelectedFigs[i]->SetSelected(false);
		pManager->SetClipboard(SelectedFigs);

		for (int i = 0; i < selectedCount; i++)
			pManager->RemoveFig(SelectedFigs[i]->GetID());
		pManager->ClearSelectedFigs();
	}
}



CutAction::~CutAction()
{
}
