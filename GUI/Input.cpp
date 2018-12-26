#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT:return DRAW_RECT;
			case ITM_LINE:return DRAW_LINE;
			case ITM_TRIG:return DRAW_TRIG;
			case ITM_RHOMBUS:return DRAW_RHOMBUS;
			case ITM_ELLIPSE:return DRAW_ELLIPSE;
			case ITM_CHNG_DRAW_CLR:return CHNG_DRAW_CLR;
			case ITM_CHNG_FILL_CLR:return CHNG_FILL_CLR;
			case ITM_SELECT:return SELECT;
			case ITM_DELETE:return DEL;
			case ITM_COPY:return COPY;
			case ITM_CUT:return CUT;
			case ITM_PASTE:return PASTE;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_TO_PLAY:return TO_PLAY;
			case ITM_EXIT:return EXIT;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_P_H_TYPE:return P_H_TYPE;
		case ITM_P_H_COLOR:return P_H_COLOR;
		case ITM_P_H_BOTH:return P_H_BOTH;
		case ITM_TO_DRAW:return TO_DRAW;
		case ITM_EXIT2: return EXIT;
		default: return EMPTY;
		}
	}
	else if (UI.InterfaceMode == MODE_COLOR)
	{
		int ClickedItemOrder = (x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_BLACK:return SET_BLACK;
		case ITM_WHITE:return SET_WHITE;
		case ITM_RED:return SET_RED;
		case ITM_GREEN:return SET_GREEN;
		case ITM_BLUE:return SET_BLUE;
		default: return EMPTY;
		}
	}
}

void Input::GetDrawPoint(int &x, int &y, Output* pO) const {
	GetPointClicked(x, y);
	while ((y < UI.ToolBarHeight + 4) || y > (UI.height - UI.StatusBarHeight)) {
		pO->PrintMessage("Please click a point in the drawing area");
		GetPointClicked(x, y);
	}
}


/////////////////////////////////
	
Input::~Input()
{
}
