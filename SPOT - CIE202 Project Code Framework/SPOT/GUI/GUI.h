#pragma once
#include <string>
using namespace std;

#include "..\DEFs.h"
#include "CMUgraphicsLib\CMUgraphics.h"

class Course;
class AcademicYear;
//user interface class
class GUI
{

	enum MENU_ITEM //The items of the menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_ADD,		//Add a new course

						//TODO: Add more items names here
						ITM_Drop, //Drop a course
						ITM_Replace, //replace course 
						ITM_Load,
						ITM_Save,
						ITM_AddNote,
						ITM_Reorder,// Drag and drop course
						ITM_CourseInfo,
						ITM_CRSStatus,
						ITM_Filter,
						ITM_Report,
						ITM_Minor,
						ITM_Concentration,
						ITM_Major,
						ITM_Grade,
						ITM_GPA,
						ITM_Level,
						ITM_EXIT, //Exit item
						ITM_CNT 	//no. of menu items ==> This should be the last line in this enum


	};

	//Some constants for GUI
	static const int	WindWidth =1500, WindHeight =700,//Window width and height
		wx = -2, wy = -2,		//Window starting coordinates
		StatusBarHeight = 60,	//Status Bar Height
		MenuBarHeight = 80,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		MenuItemWidth = 70;		//Width of each item in the menu



	color DrawColor = BLACK;		//Drawing color
	color FillColor = LIGHTSKYBLUE;		//Filling color (for courses)
	color HiColor = RED;			//Highlighting color
	color ConnColor = GREEN;		//Connector color
	color MsgColor = BLUE;			//Messages color
	color BkGrndColor = LIGHTGRAY;	//Background color
	color StatusBarColor = DARKGRAY;//statusbar color
	color NoteColor = BLUE;			//Note color
	color UnivColor = BLUE;
	color TrackColor = DARKVIOLET;
	color MajorColor = LIGHTCORAL;
	color Con1Color = WHITE;
	color Con2Color = DARKGREEN ;
	color Con3Color = YELLOW;
	color MinorColor = DARKTURQUOISE;
	string WindTitle = "Study-Plan Organizational Tool (SPOT)";

	window* pWind;
public:
	GUI();
	void CreateMenu() const;
	void ClearDrawingArea() const;
	void ClearStatusBar() const;	//Clears the status bar

	//output functions
	void PrintMsg(string msg) const;		//prints a message on status bar
	void PrintNote(string Note) const;      //prints a note 
	//Drawing functions
	void DrawCourse(const Course* );
	void DrawAcademicYear(const AcademicYear*);
	void UpdateInterface() const;
	void DrawStatus() const;
	void DrawFilterOptions() const;
	//input functions
	ActionData GUI::GetUserAction(string msg = "") const;
	YearSem GUI::GetYearSem(int x,int y) const;
	string GetSrting() const;
	

	~GUI();
};

