#include "ChangeDrawColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager *pApp) : Action(pApp)
{
}

void ChangeDrawColorAction::ReadActionParameters()
{
	// Displaying avaiable colors.
	Output* pOut = pManager->GetOutput();
	pOut->CreateClrToolbar();
	pOut->PrintMessage("Select desired drawing color");

	// Reading which color clicked.
	Input* pIn = pManager->GetInput();
	ActionType selected_color = pIn->GetUserAction();

	switch (selected_color)
	{
		case TO_BLACK:
			newDrawColor = BLACK;
			break;

		case TO_WHITE:
			newDrawColor = WHITE;
			break;

		case TO_RED:
			newDrawColor = RED;
			break;

		case TO_GREEN:
			newDrawColor = GREEN;
			break;

		case TO_BLUE:
			newDrawColor = BLUE;
			break;

		default: 
			newDrawColor = pOut->getCrntDrawColor();
	}

	// Returning to drawing toolbar.
	pOut->CreateDrawToolBar();
	pOut->CreateStatusBar();
}

void ChangeDrawColorAction::Execute()
{
	CFigure* selected_figure = pManager->getSelected();

	if (selected_figure) {
		ReadActionParameters();

		// Setting color for figure
		selected_figure->ChngDrawClr(newDrawColor);
		// Setting color for next drawings.
		Output* pOut = pManager->GetOutput();
		pOut->setCrntDrawColor(newDrawColor);

		// Unselecting figure.
		pManager->unselect();
	}
	else {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure first!");
	}
}


ChangeDrawColorAction::~ChangeDrawColorAction()
{
}
