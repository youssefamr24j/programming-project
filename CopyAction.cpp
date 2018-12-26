#include "../Phase2 - Project Framework/CopyAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"
#include "PasteAction.h"



CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < 200; i++)
		newSelectedFigures[i] = NULL;
}
void CopyAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	SelectedFigs = pManager->GetSelectedFigures();
	selectedCount = pManager->GetSelectedCount();

	if (SelectedFigs[0] != NULL)
		pOut->PrintMessage("Copy figure : Selected figures copied into clipboard");

	if (SelectedFigs[0] == NULL)
		pOut->PrintMessage("Copy figure : Select a figure first");
}
void CopyAction::Execute()
{
	ReadActionParameters();
	if (SelectedFigs[0] != NULL)
	{
		for (int i = 0; i < selectedCount; i++)
		{
			newSelectedFigures[i] = SelectedFigs[i]->copy();
			newSelectedFigures[i]->SetSelected(false);

		}
		pManager->SetClipboard(newSelectedFigures);
	}

}


CopyAction::~CopyAction()
{
}
