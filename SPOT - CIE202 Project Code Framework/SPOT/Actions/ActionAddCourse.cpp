#include "ActionAddCourse.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>
ActionAddCourse::ActionAddCourse(Registrar* p):Action(p)
{
}
bool ActionAddCourse::Execute()
{
	GUI* pGUI = pReg->getGUI();	
	
	pGUI->PrintMsg("Add Course to plan: Enter course Code(e.g. CIE202):");
	Course_Code code = pGUI->GetSrting();
	CourseInfo CRS_Info = pReg->getCourseInfo(code);
	if (CRS_Info.Credits != 0)
	{
		//TODO: add input validation


		ActionData actData = pGUI->GetUserAction("Select a year to add coures to:(To be implemented in phase1) we will just draw coures where user clicks");
		//TODO: add input validation

		int x, y;
		if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
		{
			//get coord where user clicked
			x = actData.x;
			y = actData.y;
			YearSem yearsem = pGUI->GetYearSem(x, y);
			if (yearsem.year != -1)
			{
				graphicsInfo gInfo = pReg->getnewpostion(x, y);
				//TODO: given course code, get course title, crd hours from registrar
				//For now, we will add any dummy values

				string Title = CRS_Info.Title;
				int crd = CRS_Info.Credits;
				Course* pC = new Course(code, Title, crd);
				pC->setGfxInfo(gInfo);
				pC->settype(pReg->coursetype(code));
				pC->setyearsem(yearsem.year, yearsem.sem);
				for (auto j = CRS_Info.CoReqList.begin(); j < CRS_Info.CoReqList.end(); j++)
					pC->addCoReq(*j);
				for (auto i = CRS_Info.PreReqList.begin(); i < CRS_Info.PreReqList.end(); i++)
					pC->addPreReq(*i);
				//TODO: Ask registrar to add course to the year selected by the user
				//TODO: add the course to the correct year obtained from registrar
				//For the seke of demo, we will add the course to the 1st year, 1st semester
				StudyPlan* pS = pReg->getStudyPlan();
				pS->AddCourse(pC, yearsem.year, yearsem.sem);

			}
			else
				pGUI->PrintMsg("Wrong Area!!");
		}

	}
	else
		pGUI->PrintMsg("Wrong Code!!");
	//TODO:
	

	return true;
}


ActionAddCourse::~ActionAddCourse()
{
}
