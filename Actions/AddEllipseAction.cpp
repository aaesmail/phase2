#include "AddEllipseAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddEllipseAction::AddEllipseAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddEllipseAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at center");

	//Read point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	EllipseGfxInfo.isFilled = pManager->getFill();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}


void AddEllipseAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create an ellipse with the parameters read from the user
	CEllipse *E = new CEllipse(P, EllipseGfxInfo);

	E->setID(pManager->getID());
	pManager->incID();

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}

AddEllipseAction::~AddEllipseAction()
{
}
