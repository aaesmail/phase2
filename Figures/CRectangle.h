#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;

public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void setID(int id);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* insideme(int x, int y);
};

#endif