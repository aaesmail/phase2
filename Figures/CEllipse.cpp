#include "CEllipse.h"


CEllipse::CEllipse(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point = p;
}

void CEllipse::Draw(Output * pOut) const
{
	//Call Output::DrawEllipse to draw an ellipse on the screen	
	pOut->DrawEllipse(point, FigGfxInfo, Selected);
}

void CEllipse::setID(int id)
{
	ID = id;
}

void CEllipse::PrintInfo(Output * pOut)
{
	pOut->PrintMessage(std::string("Ellipse ") + std::string(" ID: ") + std::to_string(ID) + std::string("  Center: (")
						+ std::to_string(point.x) + std::string(", ") + std::to_string(point.y) + std::string(")"));
}

CFigure * CEllipse::insideme(int x, int y)
{
	float LHS = ((pow(x - point.x, 2) * 1.0) / pow(75, 2)) + ((pow(y - point.y, 2) * 1.0) / pow(50, 2));

	if (LHS <= 1.15)
		return this;

	return NULL;
}

CEllipse::~CEllipse()
{
}
