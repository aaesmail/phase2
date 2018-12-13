#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class SelectFigureAction: public Action
{
private:
	Point P;

public:

	SelectFigureAction(ApplicationManager *pApp);

	//Reads select figure
	virtual void ReadActionParameters();

	//selects figure
	virtual void Execute();

	void unselect();

	~SelectFigureAction();
};

