#pragma once
#include "../Phase2 - Project Framework/Figures/CFigure.h"
#include "../Phase2 - Project Framework/Actions/Action.h"

class PickByColor :
	public Action
{
	CFigure* Fig;
	int  no_colors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[6];
	Point P;
	color AssignColor(CFigure*);
	void PrntScore(int);
public:
	PickByColor(ApplicationManager*);
	~PickByColor();
	void ReadActionParameters();
	void Execute();

};

