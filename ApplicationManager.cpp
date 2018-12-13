#include "AppManagerIncludes.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedFig = NULL;
	isfilled = false;
	ID = 1;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_ELLIPSE:
		pAct = new AddEllipseAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;

	case DRAW_RHOMBUS:
		pAct = new AddRhombusAction(this);
		break;

	case SELECT_FIGURE:
		pAct = new SelectFigureAction(this);
		break;

	case DRAWING_AREA:
		if (SelectedFig)
			pAct = new SelectFigureAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChangeDrawColorAction(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChangeFillColorAction(this);
		break;

	case DEL:
		pAct = new DeleteFigureAction(this);
		break;

	case EXIT:
		///create ExitAction here

		break;

	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	CFigure* try_to_select = NULL;

	for (int i = FigCount - 1; i >= 0; i--) {
		try_to_select = FigList[i]->insideme(x, y);
		if (try_to_select)
			break;
	}

	return try_to_select;
}

void ApplicationManager::setSelected(CFigure* try_to_select, bool ifselected)
{
	if (ifselected) {
		SelectedFig = try_to_select;
	}
	else {
		SelectedFig = NULL;
	}
}

CFigure *ApplicationManager::getSelected()
{
	return SelectedFig;
}
int ApplicationManager::getfigcount()
{
	return FigCount;
}
int ApplicationManager::findFigure(CFigure * figure)
{
	int index = 0;
	for (int i = 0; i < FigCount; i++) {
		if (figure == FigList[i]) {
			index = i;
			break;
		}
	}
	return index;
}

void ApplicationManager::decFigCount(int index)
{
	FigList[index] = FigList[--FigCount];
	FigList[FigCount] = NULL;
}

int ApplicationManager::getID()
{
	return ID;
}

void ApplicationManager::incID()
{
	ID++;
}

void ApplicationManager::unselect()
{
	SelectFigureAction unSelectObject(this);
	unSelectObject.unselect();
}
void ApplicationManager::setFill(bool s)
{
	isfilled = s;
}
bool ApplicationManager::getFill()
{
	return isfilled;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
