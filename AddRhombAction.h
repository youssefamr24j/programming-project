#ifndef ADD_RHOM_ACTION_H
#define ADD_RHOM_ACTION_H

#include "../Phase2 - Project Framework/Actions/Action.h"


class AddRhomAction : public Action
{
private:
	Point P1;
	GfxInfo RectGfxInfo;
public:
	AddRhomAction(ApplicationManager *pApp);


	virtual void ReadActionParameters();


	virtual void Execute();

};

#endif
