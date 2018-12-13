#pragma once

#include "Action.h"

class ChangeFillColorAction: public Action
{
private:
	color newFillColor;

public:
	ChangeFillColorAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~ChangeFillColorAction();
};

