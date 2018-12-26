#include "../Phase2 - Project Framework/AddElliAction.h"
#include "../Phase2 - Project Framework/CEllipse.h"

#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"

AddElliAction::AddElliAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddElliAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at first point");

	//Read 1st corner and store in point P1
	pIn->GetDrawPoint(P1.x, P1.y, pOut);

	pOut->PrintMessage("New Ellipse: Click at second point");

	//Read 2nd corner and store in point P2
	pIn->GetDrawPoint(P2.x, P2.y, pOut);

	RectGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth(); //Yosry
	pOut->ClearStatusBar();

}

//Execute the action
void AddElliAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CEllipse *R = new CEllipse(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}