#pragma once

#include "Action.h"

class AddTriangleAction: public Action
{
private:
	Point P1, P2, P3;
	GfxInfo TriangleGfxInfo;

public:
	AddTriangleAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();

	//Add line to the ApplicationManager
	virtual void Execute();

	~AddTriangleAction();
};

