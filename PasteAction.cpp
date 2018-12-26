#include "../Phase2 - Project Framework/PasteAction.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"


PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp)
{
}
void PasteAction::ReadActionParameters()
{
	//if (pManager->IsPasted())
	//	pManager->recreateClipboard();
	toBePasted = pManager->GetClipboard();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (toBePasted[0] != NULL)
	{
		//Read clicked point and store in P
		pOut->PrintMessage("Paste figure : Click any where");
		pIn->GetDrawPoint(P.x, P.y, pOut);
		clipboardCount = pManager->getClipboardCount();
	}
	if (toBePasted[0] == NULL)
		pOut->PrintMessage("Paste figure : Clipboard is empty, copy or cut a figure first");
}
void PasteAction::Execute()
{



	ReadActionParameters();
	if (toBePasted[0] != NULL)
	{
		Pp = toBePasted[0]->highestPoint();
		for (int i = 0; i < clipboardCount; i++)
		{
			Pp = (toBePasted[i]->highestPoint().y < Pp.y) ? toBePasted[i]->highestPoint() : Pp;
		}
		transX = P.x - Pp.x;
		transY = P.y - Pp.y;
	}

	;
	for (int i = 0; i < clipboardCount; i++)
	{


		pManager->AddFigure(toBePasted[i]->paste(transX, transY));
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Figures pasted!");

	}
}



