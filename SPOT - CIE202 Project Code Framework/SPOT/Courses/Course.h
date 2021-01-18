#pragma once
#include <string>
#include <list>
using namespace std;
#include "..\DEFs.h"

#include "../GUI/Drawable.h"

//Base class for all types of courses
class Course : public Drawable
{
	const Course_Code code;	//course code: e.g. "CIE202". This is the course ID
	const string Title;		//course title: e.g. "Fundamentals of Computer Programming"
	int credits;	//no. of course credits
	Course_Type type;	//Univ, track, or major.....etc.
	bool Done=1;		//Done or not yet?
	list<Course_Code> PreReq;	//list of prerequisites
	list<Course_Code> CoReq;	//list of prerequisites
	CourseStatus status;
	YearSem yearsem;
	bool Hide = 0;
	bool checkcore = 0;
	bool checkpre = 0;
	bool suitabletime = 0;
	GPA_letter gpa_letter=F;
public:
	Course(Course_Code r_code,string r_title, int crd);
	string getTitle() const;
	string getCode() const;
	int getCredits() const;
	void settype(Course_Type coursetype);
	Course_Type gettype() const;
	bool isDone() const;
	bool isHide() const;
	void setHide(bool i);
	void addPreReq(Course_Code code);
	void addCoReq(Course_Code code);
	list<Course_Code>* getCoReq();
	list<Course_Code>* getPreReq();
	void setyearsem(int year, SEMESTER sem);
	YearSem getyearsem() const; 
	void setStatus(CourseStatus newstatus);
	CourseStatus getStatus() const;
	void DrawMe(GUI*) const;
	bool get_checkcore() const;
	void set_checkcore(bool chh);
	bool get_checkpre() const;
	void set_checkpre(bool ck);
	bool getsuitabletime() const;
	void setsuitabletime(bool t);
	virtual ~Course();
	GPA_letter get_gpa_letter() const;
	void set_gpa_letter(GPA_letter gpa_letter);
};
