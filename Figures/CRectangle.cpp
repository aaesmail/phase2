#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::setID(int id)
{
	ID = id;
}

void CRectangle::PrintInfo(Output * pOut)
{
	pOut->PrintMessage(std::string("Rectangle ") + std::string(" ID: ") + std::to_string(ID) + std::string("  Start point: (") + std::to_string(Corner1.x)
		+ std::string(", ") + std::to_string(Corner1.y) + std::string(")") + std::string("  End point: (") + std::to_string(Corner2.x)
		+ std::string(", ") + std::to_string(Corner2.y) + std::string(")") + std::string("  Width = " + std::to_string(abs(Corner1.x - Corner2.x)))
		+ std::string("  Height = " + std::to_string(abs(Corner1.y - Corner2.y))));
}

CFigure * CRectangle::insideme(int x, int y)
{
	Point p1, p2, p3, p4, center;

	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;

	p1.x = center.x - (abs(Corner1.x - Corner2.x) / 2);
	p1.y = center.y - (abs(Corner1.y - Corner2.y) / 2);

	p2.x = center.x + (abs(Corner1.x - Corner2.x) / 2);
	p2.y = center.y - (abs(Corner1.y - Corner2.y) / 2);

	p3.x = center.x + (abs(Corner1.x - Corner2.x) / 2);
	p3.y = center.y + (abs(Corner1.y - Corner2.y) / 2);

	p4.x = center.x - (abs(Corner1.x - Corner2.x) / 2);
	p4.y = center.y + (abs(Corner1.y - Corner2.y) / 2);

	if (x >= p1.x - 5 && x <= p2.x + 5 && x <= p3.x + 5 && x >= p4.x - 5 && y >= p1.y - 5 && y >= p2.y - 5 && y <= p3.y + 5 && y <= p4.y + 5)
		return this;

	return NULL;
}
