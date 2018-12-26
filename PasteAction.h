#pragma once
#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "../Phase2 - Project Framework/Actions/Action.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"
class PasteAction :
	public Action
{
private:
	CFigure*const* toBePasted;
	Point P, Pp;
	int clipboardCount;
	int transX, transY;


public:
	PasteAction(ApplicationManager*pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif

