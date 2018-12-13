#pragma once

#include "CFigure.h"

class CEllipse: public CFigure
{
private:
	Point point;

public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void setID(int id);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* insideme(int x, int y);
	~CEllipse();
};

