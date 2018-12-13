#include "DeleteFigureAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteFigureAction::DeleteFigureAction(ApplicationManager *pApp) : Action(pApp)
{
}

void DeleteFigureAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Figure deleted");

	pOut->ClearDrawArea();
}

void DeleteFigureAction::Execute()
{
	CFigure* selected_figure = pManager->getSelected();

	if (selected_figure) {

		ReadActionParameters();

		int index = pManager->findFigure(selected_figure);

		pManager->unselect();

		pManager->decFigCount(index);

		delete selected_figure;
	}
	else {
		Output* pOut = pManager->GetOutput();

		pOut->PrintMessage("Please select a figure first!");
	}
}


DeleteFigureAction::~DeleteFigureAction()
{
}
