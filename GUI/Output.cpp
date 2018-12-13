#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1010;
	UI.height = 650;
	UI.wx = 200;
	UI.wy = 100;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	ClearDrawBar();


	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//------------------------------------------------------------------
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_line.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_trian.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_rhom.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_ellipse.jpg";
	MenuItemImages[ITM_PLAYMODE] = "images\\MenuItems\\Menu_PlayMode.jpg";
	MenuItemImages[ITM_SELECTFIG] = "images\\MenuItems\\Menu_select.jpg";
	MenuItemImages[ITM_CHANGEDRAWCOL] = "images\\MenuItems\\Menu_DrawClr.jpg";
	MenuItemImages[ITM_CHANGEFILLCOL] = "images\\MenuItems\\Menu_fill.jpg";
	MenuItemImages[ITM_DELETEFIG] = "images\\MenuItems\\Menu_Del.jpg";
	MenuItemImages[ITM_COPYFIG] = "images\\MenuItems\\Menu_copy.jpg";
	MenuItemImages[ITM_CUTFIG] = "images\\MenuItems\\Menu_cut.jpg";
	MenuItemImages[ITM_SAVEGRAPH] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\Menu_SaveType.jpg";
	MenuItemImages[ITM_LOADGRAPH] = "images\\MenuItems\\Menu_Load.jpg";
	//------------------------------------------------------------------
	MenuItemImages[ITM_VOICE] = "images\\MenuItems\\Menu_sound.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_resize.jpg";
	MenuItemImages[ITM_SNDFRNT] = "images\\MenuItems\\Menu_SNDFRNT.jpg";
	MenuItemImages[ITM_SNDBK] = "images\\MenuItems\\Menu_SNDBK.jpg";
	//------------------------------------------------------------------

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	ClearDrawBar();
	///TODO: write code to create Play mode menu

	//-------------------------------------------------------------------------------------
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICKPROP] = "images\\MenuItems\\Menu_PickProp.jpg";
	MenuItemImages[ITM_PICKCLR] = "images\\MenuItems\\Menu_PickColor.jpg";
	MenuItemImages[ITM_SWITCHDRAW] = "images\\MenuItems\\Menu_DrawMode.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//-------------------------------------------------------------------------------------
}

void Output::CreateClrToolbar() const
{
	UI.InterfaceMode = MODE_CLR;
	ClearDrawBar();
	///TODO: write code to create Color mode menu

	//-------------------------------------------------------------------------------------
	string MenuItemImages[CLR_ITM_COUNT];
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\white.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\blue.jpg";


	for (int i = 0; i < CLR_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	//-------------------------------------------------------------------------------------
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}

void Output::ClearDrawBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

void Output::setCrntDrawColor(color changeColor)
{
	UI.DrawColor = changeColor;
}

void Output::setCrntFillColor(color changeColor)
{
	UI.FillColor = changeColor;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	if (P1.y <= UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight + 5;
	if (P2.y <= UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight + 5;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

// -------------------------------------------------------------------------------------------
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const {

	if (P1.y <= UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight + 5;
	if (P2.y <= UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight + 5;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}

void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const {

	if (P1.y <= UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight + 5;
	if (P2.y <= UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight + 5;
	if (P3.y <= UI.ToolBarHeight)
		P3.y = UI.ToolBarHeight + 5;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawRhombus(Point P1, GfxInfo RhombusGfxInfo, bool selected) const {

	if (P1.y - 80 <= UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight + 85;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = RhombusGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhombusGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(RhombusGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int Px[4];
	int Py[4];
	Px[0] = P1.x - 60; //leftpt
	Py[0] = P1.y;
	Px[1] = P1.x;   //toppt
	Py[1] = P1.y + 80;
	Px[2] = P1.x + 60; //rightpt
	Py[2] = P1.y;
	Px[3] = P1.x;   //botpt
	Py[3] = P1.y - 80;

	pWind->DrawPolygon(Px, Py, 4, style);
}

void Output::DrawEllipse(Point P1, GfxInfo EllipseGfxInfo, bool selected) const {

	if (P1.y - 27 <= UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight + 5 + 50;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = EllipseGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipseGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(EllipseGfxInfo.FillClr);
	}
	else
		style = FRAME;

	Point Pa, Pb;

	Pa.x = P1.x - 75;
	Pa.y = P1.y - 50;

	Pb.x = P1.x + 75;
	Pb.y = P1.y + 50;

	pWind->DrawEllipse(Pa.x, Pa.y, Pb.x, Pb.y, style);
}

// --------------------------------------------------------------------------------------------


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

