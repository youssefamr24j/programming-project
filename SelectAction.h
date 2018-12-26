#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "../Phase2 - Project Framework/Actions/Action.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"

class SelectAction : public Action {
private:
	Point P;  //Clicked point
	CFigure* SelectedFig; //Clicked figure (NULL if no figure is clicked)
public:
	SelectAction(ApplicationManager *pApp);

	//Reads select parameters
	virtual void ReadActionParameters();

	//Executes the select action
	virtual void Execute();
	void Select();
	void Unselect();


};


#endif