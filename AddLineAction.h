#pragma once
#include"../Phase2 - Project Framework/Actions/Action.h"
class AddLineAction :public Action
{
private:
	Point P1, P2;
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();

	//Add line to the ApplicationManager
	virtual void Execute();
};