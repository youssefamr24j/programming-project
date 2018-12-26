#pragma once
#include "../Phase2 - Project Framework/Actions/Action.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"

class DeleteAction : public Action {
	int DeletedID; //ID of the deleted figure (for use in RemoveFig())
	int selectedCount; //Number of selected figures
	CFigure* const* SelectedFigs; //Pointer to the selected figures
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads draw color parameters
	virtual void ReadActionParameters();

	//Changes current/selected figure draw color
	virtual void Execute();
};