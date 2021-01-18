#include <iostream>
#include "StudyPlan.h"
#include "C:\Users\Gehan\Desktop\SPOT - CIE202 Project Code Framework\SPOT\GUI\GUI.h"
using namespace std;

StudyPlan::StudyPlan()
{
	//By default, the study plan starts with 5 years
	//More year can be added
	for (int i = 0; i < 5; i++)
		plan.push_back(new AcademicYear);
}

//adds a course to the study plan in certain year, semester
//year idetifies year number to add course to 1=first, 2 = 2nd,....
bool StudyPlan::AddCourse(Course* pC, int year, SEMESTER sem)
{
	//TODO: add all requried checks to add the course 

	plan[year - 1]->AddCourse(pC, sem);
	
	return true;
}
graphicsInfo StudyPlan::DropCourse(int x,int y,int year,SEMESTER sem)
{
	
	graphicsInfo a=plan[year-1]->DropCourse( x, y,sem);
	return a;
}
bool StudyPlan::AddNote(string Note)
{
	PlanNotes = Note;

	return true;
}
void StudyPlan::DrawMe(GUI* pGUI) const
{
	//Plan draws all year inside it.
	for (int i = 0; i < plan.size(); i++)
		plan[i]->DrawMe(pGUI);
	pGUI->PrintNote(PlanNotes);
}

Course* StudyPlan::getpCRS(int x, int y, int year, SEMESTER sem)
{
	return plan[year - 1]->getpCRS(x, y, sem);

}
StudyPlan::~StudyPlan()
{
}
AcademicYear* StudyPlan::getyear(int year)
{
	return plan[year - 1];
}
int StudyPlan::getsemcredits(int year, SEMESTER sem) const
{
	return plan[year - 1]->getsemcredits(sem);
}
int StudyPlan::getstudentlevel() const
{
	int credits=0;
	for (int year = 1; year < 6; year++)
	{
		credits = credits + plan[year - 1]->getstudentlevel();
	}
	return credits;

}