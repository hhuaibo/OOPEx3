#include "stdafx.h"
#include "Student.h"


int Student::size = 0;

Student::Student():
	name(_T("")),
	ID(_T("")),
	grade(_T("")),
	sub1(0.0),
	sub2(0.0),
	sub3(0.0)
{
	++size;
}

Student::Student(CString name, CString ID, CString grade, double  sub1, double  sub2, double  sub3):
	name(name),
	ID(ID),
	grade(grade),
	sub1(sub1),
	sub2(sub2),
	sub3(sub3)
{
	++size;
}

Student::~Student()
{
	--size;
}

