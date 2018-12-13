#include "SelectFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


SelectFigureAction::SelectFigureAction(ApplicationManager *pApp) : Action(pApp)
{
}

void SelectFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Figure: Click on any figure");

	//Read a point and store in point P
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

void SelectFigureAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	CFigure* previously_selected = pManager->getSelected();

	if (previously_selected) {
		pIn->GetCurrentCoor(P.x, P.y);
		CFigure* try_to_select = pManager->GetFigure(P.x, P.y);

		if (try_to_select == NULL) {
			
			// If user clicks on select figure icon again.
			int location = 50 * 6;
			if (P.x >= location && P.x <= location + 50 && P.y <= 50) {
				pOut->PrintMessage("Select Figure: Click on any figure. Again!");
				return;
			}

			pManager->setSelected(try_to_select, false);
			previously_selected->SetSelected(false);
			pOut->ClearStatusBar();
		}
		else if (try_to_select == previously_selected) {
			pManager->setSelected(NULL, false);
			previously_selected->SetSelected(false);
			pOut->ClearStatusBar();
		}
		else {		// User clicked on another figure
			previously_selected->SetSelected(false);
			pManager->setSelected(try_to_select, true);

			try_to_select->SetSelected(true);
			try_to_select->PrintInfo(pOut);
		}
	}
	else {
		ReadActionParameters();

		CFigure* try_to_select = pManager->GetFigure(P.x, P.y);

		if (try_to_select) {
			pManager->setSelected(try_to_select, true);

			try_to_select->SetSelected(true);
			try_to_select->PrintInfo(pOut);
		}
	}
}

void SelectFigureAction::unselect()
{
	CFigure* previously_selected = pManager->getSelected();
	if (previously_selected) {
		pManager->setSelected(NULL, false);
		previously_selected->SetSelected(false);
	}
}

SelectFigureAction::~SelectFigureAction()
{
}
