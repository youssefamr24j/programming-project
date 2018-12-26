#include"../Phase2 - Project Framework/LoadAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"
#include"../Phase2 - Project Framework/Figures/CRectangle.h"
#include"../Phase2 - Project Framework/CTrig.h"
#include"../Phase2 - Project Framework/CRhombus.h"
#include"../Phase2 - Project Framework/CEllipse.h"
#include"../Phase2 - Project Framework/CLine.h"



LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp)
{
}



//Read Parameters for the load action
void LoadAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file you want to load");


	fileName = pIn->GetSrting(pOut) + ".txt";
	//Clear the status bar
	InputFile.open(fileName);
	pOut->ClearDrawArea();
	//check if the file doesnot exists
	if (InputFile.is_open())
	{
		pOut->PrintMessage("Your file has been successfully loaded");
	}
	else { pOut->PrintMessage("No file found with name: " + fileName); }
}

//Execute action Load Action
void LoadAction::Execute()
{
	ReadActionParameters();
	//check if the file is opened first
	if (InputFile.is_open())
	{
		//read from the file the current draw clr & fill clr &number of figuers 
		CFigure*pFig = NULL;
		int numberOfFiguers;
		string DrawClr;
		InputFile >> DrawClr;
		UI.DrawColor = getColorObject(DrawClr);
		string FillClr;
		InputFile >> FillClr;
		UI.FillColor = getColorObject(FillClr);
		InputFile >> numberOfFiguers;
		//cleaning the figlist before loading the file
		pManager->ClearFigList();
		// Loop all figures ,identify the type ,then create an obj of the specified type,add to the figlist  after the loading it
		for (int i = 0; i < numberOfFiguers; i++)
		{
			int shapeType;
			InputFile >> shapeType;
			switch (shapeType)
			{
			case line:
				pFig = new CLine;
				break;

			case rect:
				pFig = new CRectangle;
				break;

			case trig:
				pFig = new CTrig;
				break;

			case rhom:
				pFig = new CRhombus;
				break;

			case elli:
				pFig = new CEllipse;
				break;

		

			default:
				pFig = NULL;
				break;
			}
			//loading the parameters of each figure 
			pFig->Load(InputFile);
			if (pFig != NULL)
			{
				//seneding it to the application manager to add them
				pManager->AddFigure(pFig);
			}
		}
		//close the file after looping 
		InputFile.close();
	}
}
//function that get a string clr name returning a clr obj
color LoadAction::getColorObject(string name)const
{
	if (name == "RED")
	{
		return RED;
	}

	if (name == "BLACK")
	{
		return BLACK;
	}

	if (name == "BLUE")
	{
		return BLUE;
	}

	if (name == "GREEN")
	{
		return GREEN;
	}

	if (name == "WHITE")
	{
		return WHITE;
	}

}
