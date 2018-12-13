#include "CRhombus.h"



CRhombus::CRhombus(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point = p;
}

void CRhombus::Draw(Output * pOut) const
{
	//Call Output::DrawRhombus to draw an rhombus on the screen	
	pOut->DrawRhombus(point, FigGfxInfo, Selected);
}

void CRhombus::setID(int id)
{
	ID = id;
}

void CRhombus::PrintInfo(Output * pOut)
{
	pOut->PrintMessage(std::string("Rhombus ") + std::string(" ID: ") + std::to_string(ID) + std::string("  Center: (")
		+ std::to_string(point.x) + std::string(", ") + std::to_string(point.y) + std::string(")"));
}

CFigure * CRhombus::insideme(int x, int y)
{
	Point p1, p2, p3, p4;

	p1.x = point.x - 60;
	p1.y = point.y;
	p2.x = point.x;
	p2.y = point.y - 80;
	p3.x = point.x + 60;
	p3.y = point.y;
	p4.x = point.x;
	p4.y = point.y + 80;

	int LINE1_m = ((p2.y - p1.y) * 1.0) / (p2.x - p1.x);
	int LINE1_c = p1.y - (LINE1_m * p1.x);
	int LINE1_LHS = y;													// m -ve
	int LINE1_RHS = (LINE1_m * x) + LINE1_c;

	int LINE2_m = ((p3.y - p2.y) * 1.0) / (p3.x - p2.x);
	int LINE2_c = p2.y - (LINE2_m * p2.x);
	int LINE2_LHS = y;													// m +ve
	int LINE2_RHS = (LINE2_m * x) + LINE2_c;

	int LINE3_m = ((p4.y - p3.y) * 1.0) / (p4.x - p3.x);
	int LINE3_c = p3.y - (LINE3_m * p3.x);
	int LINE3_LHS = y;													// m -ve
	int LINE3_RHS = (LINE3_m * x) + LINE3_c;

	int LINE4_m = ((p4.y - p1.y) * 1.0) / (p4.x - p1.x);
	int LINE4_c = p4.y - (LINE4_m * p4.x);
	int LINE4_LHS = y;													// m +ve
	int LINE4_RHS = (LINE4_m * x) + LINE4_c;

	if (LINE1_LHS >= LINE1_RHS - 15 && LINE2_LHS >= LINE2_RHS + 5 && LINE3_LHS <= LINE3_RHS + 15 && LINE4_LHS <= LINE4_RHS - 5)
		return this;

	return NULL;
}

CRhombus::~CRhombus()
{
}
