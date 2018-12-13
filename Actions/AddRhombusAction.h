#pragma once

#include "Action.h"

class AddRhombusAction: public Action
{
private:
	Point P;
	GfxInfo RhombusGfxInfo;

public:
	AddRhombusAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();

	~AddRhombusAction();
};

