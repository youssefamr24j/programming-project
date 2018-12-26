#pragma once
#include "../Phase2 - Project Framework/Actions/Action.h"

class ExitAction :public Action
{
public:
	ExitAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	//Execute action (Exit action)
	virtual void Execute();


};
