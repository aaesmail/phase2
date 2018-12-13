#pragma once

#include "Action.h"

class DeleteFigureAction: public Action
{
public:
	DeleteFigureAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~DeleteFigureAction();
};

