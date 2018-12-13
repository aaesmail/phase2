#include "AddRhombusAction.h"
#include "..\Figures\CRhombus.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddRhombusAction::AddRhombusAction(ApplicationManager *pApp):Action(pApp)
{
}

void AddRhombusAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at center");

	//Read point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	RhombusGfxInfo.isFilled = pManager->getFill();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombusGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}


void AddRhombusAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *R = new CRhombus(P, RhombusGfxInfo);

	R->setID(pManager->getID());
	pManager->incID();

	//Add the rhombus to the list of figures
	pManager->AddFigure(R);
}

AddRhombusAction::~AddRhombusAction()
{
}
