#pragma once

#include "CFigure.h"

class CRhombus: public CFigure
{
private:
	Point point;

public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void setID(int id);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* insideme(int x, int y);
	~CRhombus();
};

