#ifndef ADD_ELLI_ACTION_H
#define ADD_ELLI_ACTION_H

#include "../Phase2 - Project Framework/Actions/Action.h"

//Add Rectangle Action class
class AddElliAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddElliAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
