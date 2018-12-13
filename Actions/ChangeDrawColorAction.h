#pragma once

#include "Action.h"

class ChangeDrawColorAction: public Action
{
private:
	color newDrawColor;

public:
	ChangeDrawColorAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~ChangeDrawColorAction();
};

