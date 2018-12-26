
#ifndef COPY_ACTION_H
#define COPY_ACTION_H
#include "../Phase2 - Project Framework/Actions/Action.h"
#include "SelectAction.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"
class CopyAction :
	public Action
{
private:
	int selectedCount;
	CFigure* const* SelectedFigs;
	CFigure* newSelectedFigures[200];
public:
	CopyAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyAction();
};
#endif

