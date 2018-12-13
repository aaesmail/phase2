#include "CLine.h"



CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
}


void CLine::Draw(Output * pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(point1, point2, FigGfxInfo, Selected);
}

void CLine::setID(int id)
{
	ID = id;
}

void CLine::PrintInfo(Output * pOut)
{
	pOut->PrintMessage(std::string("Line ") + std::string(" ID: ") + std::to_string(ID) + std::string("  Start point: (") + std::to_string(point1.x)
						+ std::string(", ") + std::to_string(point1.y) + std::string(")") + std::string("  End point: (") + std::to_string(point2.x)
						+ std::string(", ") + std::to_string(point2.y) + std::string(")"));
}

CFigure * CLine::insideme(int x, int y)
{
	float m = ((point2.y - point1.y) * 1.0) / (point2.x - point1.x);
	float c = point1.y - (m * point1.x);

	float LHS = y;
	float RHS = (m * x) + c;

	if (m > 35 || m < -35) {
		Point p1, p2, p3, p4, center;

		center.x = (point1.x + point2.x) / 2;
		center.y = (point1.y + point2.y) / 2;

		p1.x = center.x - (abs(point1.x - point2.x) / 2);
		p1.y = center.y - (abs(point1.y - point2.y) / 2);

		p2.x = center.x + (abs(point1.x - point2.x) / 2);
		p2.y = center.y - (abs(point1.y - point2.y) / 2);

		p3.x = center.x + (abs(point1.x - point2.x) / 2);
		p3.y = center.y + (abs(point1.y - point2.y) / 2);

		p4.x = center.x - (abs(point1.x - point2.x) / 2);
		p4.y = center.y + (abs(point1.y - point2.y) / 2);

		if (x >= p1.x - 5 && x <= p2.x + 5 && x <= p3.x + 5 && x >= p4.x - 5 && y >= p1.y - 5 && y >= p2.y - 5 && y <= p3.y + 5 && y <= p4.y + 5)
			return this;
	}

	int maxX, leastX;
	if (point1.x > point2.x) {
		maxX = point1.x;
		leastX = point2.x;
	}
	else {
		maxX = point2.x;
		leastX = point1.x;
	}

	int maxY, leastY;
	if (point1.y > point2.y) {
		maxY = point1.y;
		leastY = point2.y;
	}
	else {
		maxY = point2.y;
		leastY = point1.y;
	}

	if (LHS <= RHS + 5 && LHS >= RHS - 5 && x <= maxX && x >= leastX && y <= maxY && y >= leastY)
		return this;

	return NULL;
}

CLine::~CLine()
{
}
