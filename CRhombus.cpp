#include "CRhombus.h"

CRhombus::CRhombus() {}


CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRhombus(Center, FigGfxInfo, Selected);
}

bool CRhombus::IsOnFig(int x, int y) const {

	//Checks if the x & y coordinates lie inside/on the rectangle
	return (x >= ((Center.x) - 100) && x <= ((Center.x) + 100)) && ((y >= ((Center.y) - 100) && y <= ((Center.y) + 100)));
}

void CRhombus::PrintInfo(Output* pOut) const {
	//Forming the printed message string then passing it to PrintMessage
	string message = "Rhombus, ID: " + to_string(ID) + ", Center: (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), Length: 100, Width: 100";
	pOut->PrintMessage(message);
}
CFigure* CRhombus::copy()
{
	return new CRhombus(*this);

}
CFigure* CRhombus::paste(int transX, int transY)
{
	Center.x += transX;
	Center.y += transY;
	return new CRhombus(*this);
}
Point CRhombus::highestPoint()
{
	return GetHighestPoint(Center);
}

//Save function for Rectangle ,Read all the parameters 
void CRhombus::Save(ofstream &OutFile)
{
	//saving the parameters with a specific format
	string DrawClr = getColorName(FigGfxInfo.DrawClr);

	OutFile << rhom << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << DrawClr << '\t';
	//if filled save the fill clr
	if (FigGfxInfo.isFilled == true)
	{
		string FillClr = getColorName(FigGfxInfo.FillClr);
		OutFile << FillClr << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
//Load function for Rectangle ,Read all the parameters 
void CRhombus::Load(ifstream&InFile)
{
	//loading the parameters with a specific format
	string DrawClr;
	string FillClr;
	InFile >> ID >> Center.x >> Center.y;
	InFile >> DrawClr;
	FigGfxInfo.DrawClr = getColorObject(DrawClr);
	InFile >> FillClr;
	//if filled set the fill clr
	if (FillClr == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorObject(FillClr);
	}
	FigGfxInfo.BorderWdth = UI.PenWidth;
}
//Sets x and y to the center point coordinates
void CRhombus::getCenter(double &x, double& y)
{
	x = Center.x;
	y = Center.y;
}
//Rotates the figure 90 degrees clockwise
