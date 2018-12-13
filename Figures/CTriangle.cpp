#include "CTriangle.h"



CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	point3 = P3;
}

void CTriangle::Draw(Output * pOut) const
{
	//Call Output::DrawTriangle to draw a line on the screen	
	pOut->DrawTriangle(point1, point2, point3, FigGfxInfo, Selected);
}

void CTriangle::setID(int id)
{
	ID = id;
}

void CTriangle::PrintInfo(Output * pOut)
{
	pOut->PrintMessage(std::string("Triangle ") + std::string(" ID: ") + std::to_string(ID) + std::string("  Corners:  (")
		+ std::to_string(point1.x) + std::string(", ") + std::to_string(point1.y) + std::string(")")
		+ std::string("  (") + std::to_string(point2.x) + std::string(", ") + std::to_string(point2.y) + std::string(")")
		+ std::string("  (") + std::to_string(point3.x) + std::string(", ") + std::to_string(point3.y) + std::string(")"));
}

CFigure * CTriangle::insideme(int x, int y)
{
	float plane1, plane2, plane3;
	bool hasNegative, hasPositive;

	plane1 = (x - point2.x) * (point1.y - point2.y) - (point1.x - point2.x) * (y - point2.y);
	plane2 = (x - point3.x) * (point2.y - point3.y) - (point2.x - point3.x) * (y - point3.y);
	plane3 = (x - point1.x) * (point3.y - point1.y) - (point3.x - point1.x) * (y - point1.y);

	hasNegative = (plane1 < 0) || (plane2 < 0) || (plane3 < 0);
	hasPositive = (plane1 > 0) || (plane2 > 0) || (plane3 > 0);

	if (!(hasNegative && hasPositive))
		return this;

	return NULL;
}

CTriangle::~CTriangle()
{
}
