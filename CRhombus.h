#ifndef CRHOM_H
#define CRHOM_H

#include "../Phase2 - Project Framework/Figures/CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
public:
	CRhombus();
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsOnFig(int, int) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	virtual CFigure* copy();
	virtual CFigure* paste(int, int);
	virtual Point highestPoint();
	virtual void getCenter(double&, double&);
};

#endif
