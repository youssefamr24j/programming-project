#pragma once
#include "../Phase2 - Project Framework/Actions/Action.h"
#include "../Phase2 - Project Framework/Figures/CFigure.h"
class PickByBoth :
	public Action

{
	CFigure* Fig;
	Point P;
	int  no_combs, rand_fig_no, picked_comb_no, rigSel, wrgSel;
	int combinations[29];
	void PrntScore(int);

public:
	PickByBoth(ApplicationManager*);
	~PickByBoth();
	void ReadActionParameters();
	void Execute();
};

