#include "ChangeFillColorAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager *pApp) : Action(pApp)
{
}

void ChangeFillColorAction::ReadActionParameters()
{
	// Displaying avaiable colors.
	Output* pOut = pManager->GetOutput();
	pOut->CreateClrToolbar();
	pOut->PrintMessage("Select desired fill color");

	// Reading which color clicked.
	Input* pIn = pManager->GetInput();
	ActionType selected_color = pIn->GetUserAction();

	switch (selected_color)
	{
	case TO_BLACK:
		newFillColor = BLACK;
		break;

	case TO_WHITE:
		newFillColor = WHITE;
		break;

	case TO_RED:
		newFillColor = RED;
		break;

	case TO_GREEN:
		newFillColor = GREEN;
		break;

	case TO_BLUE:
		newFillColor = BLUE;
		break;

	default:
		newFillColor = NAVY;
	}

	// Returning to drawing toolbar.
	pOut->CreateDrawToolBar();
	pOut->CreateStatusBar();
}

void ChangeFillColorAction::Execute()
{
	CFigure* selected_figure = pManager->getSelected();

	if (selected_figure) {
		ReadActionParameters();

		if (newFillColor != NAVY) {
			// Setting color for figure
			selected_figure->ChngFillClr(newFillColor);
			// Setting color for next drawings.
			Output* pOut = pManager->GetOutput();
			pOut->setCrntFillColor(newFillColor);
			pManager->setFill(true);
		}

		// Unselecting figure.
		pManager->unselect();
	}
	else {
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure first!");
	}
}

ChangeFillColorAction::~ChangeFillColorAction()
{
}
