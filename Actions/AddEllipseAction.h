#pragma once

#include "Action.h"

class AddEllipseAction: public Action
{
private:
	Point P;
	GfxInfo EllipseGfxInfo;

public:
	AddEllipseAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

	~AddEllipseAction();
};
