#include "Course.h"
#include "../GUI/GUI.h"
Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	credits = crd;
}

Course::~Course()
{
}

Course_Code Course::getCode() const
{
	return code;
}

string Course::getTitle() const
{
	return Title;
}
void Course :: settype(Course_Type coursetype)
{
	type = coursetype;
}
Course_Type Course:: gettype() const
{
	return type;
}
list<Course_Code>* Course::getCoReq()
{
	return &CoReq;
}
list<Course_Code>* Course:: getPreReq()
{
	return &PreReq;
}
//return course credits
int Course::getCredits() const
{
	return credits;
}

void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
}
void Course::setyearsem(int year, SEMESTER sem) 
{
	yearsem.year = year;
	yearsem.sem = sem;
}
YearSem Course::getyearsem() const
{
	return yearsem;
}
void Course::setStatus(CourseStatus newstatus)
{
	status = newstatus;
	if (status == Done || status == Replaced)
		Done = 1;
	else
		Done = 0;
}
CourseStatus Course::getStatus() const
{
	return status;
}
bool Course::isDone() const
{
	return Done;
}
void Course:: addPreReq(Course_Code code)
{
	PreReq.push_back(code);
}
void Course:: addCoReq(Course_Code code)
{
	CoReq.push_back(code);
}
bool Course:: isHide() const
{
	return Hide;
}
void Course::setHide(bool i)
{
	Hide = i;
}
bool Course::get_checkcore() const
{
	return checkcore;
}
void Course::set_checkcore(bool chh)
{
	checkcore = chh;
}
bool Course::get_checkpre() const
{
	return checkpre;
}
void Course::set_checkpre(bool ck)
{
	checkpre = ck;
}
GPA_letter Course::get_gpa_letter() const
{
	return gpa_letter;
}
void Course::set_gpa_letter(GPA_letter gpa_letter)
{
	this->gpa_letter = gpa_letter;
}
bool Course:: getsuitabletime() const
{
	return suitabletime;
}
void Course::setsuitabletime(bool t)
{
	suitabletime = t;
}