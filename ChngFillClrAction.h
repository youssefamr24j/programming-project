#pragma once
#include "../Phase2 - Project Framework/Actions/Action.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"

class ChngFillClrAction : public Action {
	ActionType inputColorAction;
	color FillClr;
	int selectedCount; //number of selected figures
	CFigure* const* SelectedFigs; //pointer to selected figures
	//If a figure is selected
	bool IsSelectedFig;
	//If a color was picked in the color toolbar
	bool IsColor;
public:
	ChngFillClrAction(ApplicationManager *pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();
};
