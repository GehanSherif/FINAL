#include "GUI.h"
#include "../Courses/Course.h"
#include "../StudyPlan/AcademicYear.h"
#include <sstream>

GUI::GUI()
{
	pWind = new window(WindWidth, WindHeight, wx, wy);
	pWind->ChangeTitle(WindTitle);
	ClearDrawingArea();
	ClearStatusBar();
	CreateMenu();
}


//Clears the status bar
void GUI::ClearDrawingArea() const
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor);
	pWind->DrawRectangle(0, MenuBarHeight, WindWidth, WindHeight - StatusBarHeight);

}

void GUI::ClearStatusBar() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}

void GUI::CreateMenu() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, 0, WindWidth, MenuBarHeight);

	//You can draw the menu icons any way you want.

	//First prepare List of images paths for menu item
	string MenuItemImages[ITM_CNT];
	MenuItemImages[ITM_ADD] = "GUI\\Images\\Menu\\Menu_add_course.jpeg";
	MenuItemImages[ITM_EXIT] = "GUI\\Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_Drop] = "GUI\\Images\\Menu\\Menu_drop_course.jpeg";
	MenuItemImages[ITM_Load] = "GUI\\Images\\Menu\\Menu_load.jpg";
	MenuItemImages[ITM_Save] = "GUI\\Images\\Menu\\Menu_save.jpeg";
	MenuItemImages[ITM_AddNote] = "GUI\\Images\\Menu\\Menu_add_note.jpeg";
	MenuItemImages[ITM_Replace] = "GUI\\Images\\Menu\\Menu_replace.jpg";
	MenuItemImages[ITM_Reorder] = "GUI\\Images\\Menu\\Menu_Reorder.jpg";
	MenuItemImages[ITM_CourseInfo] = "GUI\\Images\\Menu\\Menu_Info.jpg";
	MenuItemImages[ITM_CRSStatus] = "GUI\\Images\\Menu\\Menu_Status.jpg";
	MenuItemImages[ITM_Filter] = "GUI\\Images\\Menu\\Menu_Filter.jpg";
	MenuItemImages[ITM_Report] = "GUI\\Images\\Menu\\Menu_Report.jpg";
	MenuItemImages[ITM_Minor] = "GUI\\Images\\Menu\\Menu_Minor.jpg";
	MenuItemImages[ITM_Concentration] = "GUI\\Images\\Menu\\Menu_Concentration.jpg";
	MenuItemImages[ITM_Major] = "GUI\\Images\\Menu\\Menu_Major.jpg";
	MenuItemImages[ITM_Grade] = "GUI\\Images\\Menu\\Menu_Grade.jpg";
	MenuItemImages[ITM_GPA] = "GUI\\Images\\Menu\\Menu_GPA.jpg";
	MenuItemImages[ITM_Level] = "GUI\\Images\\Menu\\Menu_Level.jpg";
	//TODO: Prepare image for each menu item and add it to the list
	pWind->SetFont(10, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(5,70 , "Add Course");
	pWind->DrawString(80,70 , "Delete Course");
	pWind->DrawString(150,70 , "Replace Course");
	pWind->DrawString(230, 70, "Load");
	pWind->DrawString(300, 70, "Save");
	pWind->DrawString(360, 70, "Add Note");
	pWind->DrawString(430, 70, "Reorder Course");
	pWind->DrawString(500, 70, "Course Info");
	pWind->DrawString(560, 70, "Select CRS Status");
	pWind->DrawString(640, 70, "Filter Options");
	pWind->DrawString(720, 70, "Report");
	pWind->DrawString(800, 70, "Minor");
	pWind->DrawString(850, 70, "Concentration");
	pWind->DrawString(930, 70, "Major");
	pWind->DrawString(1000, 70, "CRS Grade");
	pWind->DrawString(1070, 70, "GPA");
	pWind->DrawString(1120, 70, "Student Level");
	pWind->DrawString(1220, 70, "Exit");
	//Draw menu items one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * MenuItemWidth, 0, MenuItemWidth, MenuBarHeight-10);
}

////////////////////////    Output functions    ///////////////////

//Prints a message on the status bar
void GUI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;
	pWind->SetFont(17, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(MsgX, WindHeight - MsgY, msg);
	
	
}

//////////////////////////////////////////////////////////////////////////
void GUI::UpdateInterface() const
{

	pWind->SetBuffering(true);
	//Redraw everything
	CreateMenu();
	ClearStatusBar();
	ClearDrawingArea();
	pWind->UpdateBuffer();
	pWind->SetBuffering(false);

}

////////////////////////    Drawing functions    ///////////////////
void GUI::DrawStatus() const
{
	pWind->SetFont(25, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->SetBrush(LIGHTSTEELBLUE);
	pWind->DrawRectangle(1020, 560, 1330, 600);
	pWind->DrawString(1030, 570, "Available Status:");
	pWind->SetFont(13, BOLD, BY_NAME, "Arial");
	pWind->DrawRectangle(1020, 610, 1090, 640);
	pWind->DrawString(1040, 620, "Done");
	pWind->DrawRectangle(1100, 610, 1170, 640);
	pWind->DrawString(1110, 620, "In Progress");
	pWind->DrawRectangle(1180, 610, 1250, 640);
	pWind->DrawString(1190, 620, "Pending");
	pWind->DrawRectangle(1260, 610, 1330, 640);
	pWind->DrawString(1270, 620, "Replaced");
}
void GUI:: DrawFilterOptions() const
{
	pWind->SetFont(25, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->SetBrush(LIGHTSTEELBLUE);
	pWind->DrawRectangle(1020, 560, 1250, 600);
	pWind->DrawString(1030, 570, "Available Filters:");
	pWind->SetFont(13, BOLD, BY_NAME, "Arial");
	pWind->DrawRectangle(1020, 610, 1070, 640);
	pWind->DrawString(1030, 620, "Year");
	pWind->DrawRectangle(1080, 610, 1130, 640);
	pWind->DrawString(1090, 620, "Sem");
	pWind->DrawRectangle(1140, 610, 1190, 640);
	pWind->DrawString(1150, 620, "Univ");
	pWind->DrawRectangle(1200, 610, 1250, 640);
	pWind->DrawString(1210, 620, "Major");
	pWind->DrawRectangle(1260, 610, 1310, 640);
	pWind->DrawString(1270, 620, "Track");
	pWind->DrawRectangle(1260, 560, 1310, 600);
	pWind->DrawString(1270, 570, "Default");
}
void GUI::DrawCourse(const Course* pCrs)
{
	if(pCrs->isHide()==0)
	{ 
		graphicsInfo gInfo = pCrs->getGfxInfo();
		if (pCrs->get_checkpre() == 0 || pCrs->get_checkcore() == 0)
			pWind->SetBrush(ORANGERED);
		else if (pCrs->getsuitabletime() == 0)
			pWind->SetBrush(ORANGE);
	    else
	    {
		if (pCrs->isSelected())
			pWind->SetBrush(PINK);
		else
			pWind->SetBrush(FillColor);
	    }
		if (pCrs->gettype() == MajorElective||pCrs->getCode()=="CIE XXX"||pCrs->getCode()=="NANENG XXX")
		{
			pWind->SetPen(MajorColor, 2);
			pWind->DrawEllipse(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
		}
		else
		{
			if (pCrs->gettype() == UnivCompulsory || pCrs->gettype() == UnivElective || pCrs->getCode() == "SCH XXX")
				pWind->SetPen(UnivColor, 2);
			else if (pCrs->gettype() == MajorCompulsory)
				pWind->SetPen(MajorColor, 2);
			else if (pCrs->gettype() == TrackCompulsory)
				pWind->SetPen(TrackColor, 2);
			else if (pCrs->gettype() == Concentration1Compulsory || pCrs->gettype() == Concentration1Elective)
				pWind->SetPen(Con1Color, 2);
			else if (pCrs->gettype() == Concentration2Compulsory || pCrs->gettype() == Concentration2Elective)
				pWind->SetPen(Con2Color, 2);
			else if (pCrs->gettype() == Concentration3Compulsory || pCrs->gettype() == Concentration3Elective)
				pWind->SetPen(Con3Color, 2);
			else if (pCrs->gettype() == Minor)
				pWind->SetPen(MinorColor, 2);
			else  pWind->SetPen(DrawColor, 2);
			pWind->DrawRectangle(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
		}
		pWind->DrawLine(gInfo.x, gInfo.y + CRS_HEIGHT / 2, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT / 2);

		//Write the course code and credit hours.
		int Code_x = gInfo.x + CRS_WIDTH * 0.15;
		int Code_y = gInfo.y + CRS_HEIGHT * 0.05;
		pWind->SetFont(12, BOLD, BY_NAME, "Gramound");
		pWind->SetPen(MsgColor);

		ostringstream crd;
		pWind->SetPen(DrawColor);
		crd << "crd:" << pCrs->getCredits();
		pWind->DrawString(Code_x, Code_y, pCrs->getCode());
		pWind->DrawString(Code_x, Code_y + CRS_HEIGHT / 2, crd.str());
	}
}

void GUI::DrawAcademicYear(const AcademicYear* pY)
{
	graphicsInfo gInfo = pY->getGfxInfo();
	//Verical Lines
	pWind->SetPen(BLACK, 2);
	pWind->SetFont(25, BOLD, BY_NAME, "Arial");
	pWind->SetBrush(PINK);
	pWind->DrawRectangle(0, 130, 1500, 200);

	pWind->DrawString(120, 100, "YEAR 1");
	pWind->DrawLine(270, 100, 270, 550);

	pWind->DrawString(380, 100, "YEAR 2");
	pWind->DrawLine(540, 100, 540, 550);

	pWind->DrawString(650, 100, "YEAR 3");
	pWind->DrawLine(810, 100, 810, 550);

	pWind->DrawString(910, 100, "YEAR 4");
	pWind->DrawLine(1080, 100, 1080, 550);

	pWind->DrawString(1200, 100, "YEAR 5");

	pWind->SetPen(BLACK, 1);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawLine(90, 130, 90, 550);
	pWind->DrawLine(180, 130, 180, 550);
	pWind->DrawString(40, 150, "FALL");
	pWind->DrawString(100, 150, "SPRING");
	pWind->DrawString(190, 150, "SUMMER");

	pWind->DrawString(300, 150, "FALL");
	pWind->DrawString(370, 150, "SPRING");
	pWind->DrawString(460, 150, "SUMMER");
	pWind->DrawLine(360, 130, 360, 550);
	pWind->DrawLine(450, 130, 450, 550);

	pWind->DrawString(580, 150, "FALL");
	pWind->DrawString(650, 150, "SPRING");
	pWind->DrawString(730, 150, "SUMMER");
	pWind->DrawLine(630, 130, 630, 550);
	pWind->DrawLine(720, 130, 720, 550);

	pWind->DrawString(840, 150, "FALL");
	pWind->DrawString(910, 150, "SPRING");
	pWind->DrawString(1000, 150, "SUMMER");
	pWind->DrawLine(900, 130, 900, 550);
	pWind->DrawLine(990, 130, 990, 550);

	pWind->DrawString(1100, 150, "FALL");
	pWind->DrawString(1180, 150, "SPRING");
	pWind->DrawString(1280, 150, "SUMMER");
	pWind->DrawLine(1170, 130, 1170, 550);
	pWind->DrawLine(1260, 130, 1260, 550);


	//Horizonatal Lines
	pWind->DrawLine(10, 130, 3000, 130);
	pWind->DrawLine(10, 200, 3000, 200);

	pWind->SetBrush(DARKGRAY);

	pWind->DrawRectangle(220, 560, 1000, 630);
	pWind->SetPen(BLACK, 20);
	pWind->DrawString(20, 580, "Wrtie Your Notes Here : ");

	


	///TODO: compelete this function to:
	//		1- Draw a rectangle for the academic year 
	//		2- Draw a sub-rectangle for each semester
	//Then each course should be drawn inside rect of its year/sem

}


////////////////////////    Input functions    ///////////////////
//This function reads the position where the user clicks to determine the desired action
//If action is done by mouse, actData will be the filled by mouse position
ActionData GUI::GetUserAction(string msg) const
{
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;


	// Flush out the input queues before beginning
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();

	PrintMsg(msg);

	while (true)
	{
		int x, y;
		ctInput = pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		ktInput = pWind->GetKeyPress(cKeyData);

		if (ktInput == ESCAPE)	//if ESC is pressed,return CANCEL action
		{
			return ActionData{ CANCEL };
		}


		if (ctInput == LEFT_CLICK)	//mouse left click
		{
			//[1] If user clicks on the Menu bar
			if (y >= 0 && y < MenuBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADD: return ActionData{ ADD_CRS };	//Add course
				case ITM_Drop: return ActionData{ DEL_CRS }; //Drop Course
				case ITM_Replace: return ActionData{ REPLACE_CRS }; //Replace Course
				case ITM_AddNote: return ActionData{ Add_Note }; //Add Note
				case ITM_Load: return ActionData{ LOAD }; //import study plan
				case ITM_Reorder: return ActionData{ Reorder_Course }; //Drag and drop Course
				case ITM_EXIT: return ActionData{ EXIT };		//Exit
				case ITM_CourseInfo: return ActionData{ CRS_Info };		//course info
				case ITM_CRSStatus: return ActionData{ CRS_Status };		
				case ITM_Filter: return ActionData{ Filter };
				case ITM_Report: return ActionData{ Report };
				case ITM_Grade: return ActionData{ Grade };
				case ITM_GPA: return ActionData{ GPA };
				case ITM_Level: return ActionData{ Level };
				case ITM_Concentration: return ActionData{ Concentration };
				case ITM_Minor: return ActionData{ minor };
				case ITM_Major: return ActionData{ Major };
				default: return ActionData{ MENU_BAR };	//A click on empty place in menu bar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= MenuBarHeight && y < WindHeight - StatusBarHeight)
			{
				return ActionData{ DRAW_AREA,x,y };	//user want clicks inside drawing area
			}

			//[3] User clicks on the status bar
			return ActionData{ STATUS_BAR };
		}
	}//end while

}

YearSem GUI::GetYearSem(int x,int y) const
{
	YearSem yearsem;
	yearsem.year = -1;
	yearsem.sem = FALL;
	int yearwidth = 270;
	int semwidth = 90;
			if (y >= 200 && y <700)
			{
				
				int ClickedYearOrder = (x / yearwidth);
				int ClickedSemOrder = (x / semwidth);
				
				switch (ClickedYearOrder)
				{
				case 0: yearsem.year = 1;
					break;
				case 1: yearsem.year = 2;
					break;
				case 2: yearsem.year = 3;
					break;
				case 3: yearsem.year = 4;
					break;
				case 4: yearsem.year = 5;
					break;
				}
				switch (ClickedSemOrder)
				{
				case 0: yearsem.sem = FALL;
					break;
				case 1: yearsem.sem = SPRING;
					break;
				case 2: yearsem.sem = SUMMER;
					break;
				case 3: yearsem.sem = FALL;
					break;
				case 4: yearsem.sem = SPRING;
					break;
				case 5: yearsem.sem = SUMMER;
					break;
				case 6: yearsem.sem = FALL;
					break;
				case 7: yearsem.sem = SPRING;
					break;
				case 8: yearsem.sem = SUMMER;
					break;
				case 9: yearsem.sem = FALL;
					break;
				case 10: yearsem.sem = SPRING;
					break;
				case 11: yearsem.sem = SUMMER;
					break;
				case 12: yearsem.sem = FALL;
					break;
				case 13: yearsem.sem = SPRING;
					break;
				case 14: yearsem.sem = SUMMER;
					break;

				}
				return yearsem;
			}
			return yearsem;

}

string GUI::GetSrting() const
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar



	string userInput;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);

		switch (Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if (userInput.size() > 0)
				userInput.resize(userInput.size() - 1);
			break;

		default:
			userInput += Key;
		};

		PrintMsg(userInput);
	}

}
void GUI::PrintNote(string Note) const
{
						
	int NoteX = 222;
	int NoteY = 560;

	// Print the Note
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->SetPen(NoteColor);
	pWind->DrawString(NoteX, NoteY, Note);
}





GUI::~GUI()
{
	delete pWind;
}

