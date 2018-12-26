#pragma once
#ifndef CUT_ACTION_H
#define CUT_ACTION_H
#include "../Phase2 - Project Framework/Actions/Action.h"
#include "SelectAction.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"
class CutAction :
	public Action
{
private:
	CFigure*const* SelectedFigs;
	int selectedCount;

public:
	CutAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CutAction();
};
#endif

