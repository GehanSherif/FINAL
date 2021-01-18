#include <iostream>
#include "AcademicYear.h"
#include "../GUI/GUI.h"
using namespace std;
AcademicYear::AcademicYear()
{
	//TODO: make all necessary initializations
}


AcademicYear::~AcademicYear()
{
}

//Adds a course to this year in the spesified semester
bool AcademicYear::AddCourse(Course* pC, SEMESTER sem)
{
	//TODO:
	//This function still needs many checks to be compelete
	YearCourses[sem].push_back(pC);
	TotalCredits += pC->getCredits();
	
	//TODO: acording to course type incremenet corrsponding toatl hours for that year


	return true;
}
graphicsInfo AcademicYear::DropCourse(int X, int Y,SEMESTER sem)
{
	graphicsInfo a ;
	a.x = NULL;
	a.y = NULL;
	
	for (auto YC = YearCourses[sem].begin(); YC != YearCourses[sem].end(); YC++)
	{
		Course* j = *YC;
		graphicsInfo pos = j->getGfxInfo();
		if (X == pos.x && Y == pos.y)
		{
			a = pos;
			TotalCredits -= j->getCredits();
			YearCourses[sem].erase(YC);
			return a;

		}
	}
	return a;
}
int AcademicYear::getsemcredits(SEMESTER sem) const
{
	int credits = 0;
	for (auto i = YearCourses[sem].begin(); i != YearCourses[sem].end(); i++)
	{
		credits += (*i)->getCredits();
	}
	return credits;
}
Course* AcademicYear:: getpCRS(int x, int y, SEMESTER sem)
{
	for (auto YC = YearCourses[sem].begin(); YC != YearCourses[sem].end(); YC++)
	{
		Course* j = *YC;
		graphicsInfo pos = j->getGfxInfo();
		if (x == pos.x && y == pos.y)
			return j;
	}
	return NULL;
}
void AcademicYear::DrawMe(GUI* pGUI) const
{
	pGUI->DrawAcademicYear(this);
	//Draw all semesters inside this year by iterating on each semester list
	//to get courses and draw each course
	
	for (int sem = FALL; sem < SEM_CNT; sem++)
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			(*it)->DrawMe(pGUI);	//call DrawMe for each course in this semester
		}
}
list<Course*>* AcademicYear::getlist(SEMESTER sem)
{
	return &YearCourses[sem];
}
int AcademicYear::getstudentlevel() const
{
	int credits = 0;
	for (int s = 0; s < 3; s++)
	{
		SEMESTER sem;
		switch (s)
		{
		case 0: sem = FALL;
			break;
		case 1: sem = SPRING;
			break;
		case 2: sem = SUMMER;
			break;
		}
		for (auto i = YearCourses[sem].begin(); i != YearCourses[sem].end(); i++)
		{
			if ((*i)->isDone())
				credits += (*i)->getCredits();
		}
		return credits;
	}
}