#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearDrawBar() const;


	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	///Make similar functions for drawing all other figure types.
	//------------------------------------------------------------------------------------------
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected = false) const; //Draw a line
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected = false) const; //Draw a triangle
	void DrawRhombus(Point P1, GfxInfo RhombusGfxInfo, bool selected = false) const;  //Draw a rhombus
	void DrawEllipse(Point P1, GfxInfo EllipseGfxInfo, bool selected = false) const;  //Draw a ellipse
	void CreateClrToolbar() const;
	//-------------------------------------------------------------------------------------------

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	void setCrntDrawColor(color changeColor);	//set current drawing color.
	void setCrntFillColor(color changeColor);	//set current fill color.

	~Output();
};

#endif