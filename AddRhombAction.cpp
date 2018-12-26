#include "../Phase2 - Project Framework/AddRhombAction.h"
#include "../Phase2 - Project Framework/CRhombus.h"

#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhomAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click to draw a Rhombus");

	//Read 1st corner and store in point P1
	pIn->GetDrawPoint(P1.x, P1.y, pOut);

	RectGfxInfo.isFilled = pOut->getIsFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();
	RectGfxInfo.BorderWdth = pOut->getCrntPenWidth(); //Yosry
	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRhombus *R = new CRhombus(P1, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}