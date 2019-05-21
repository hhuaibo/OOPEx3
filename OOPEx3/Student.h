#pragma once
class Student
{
public:
	Student();
	Student(CString name, CString ID, CString grade, double  sub1, double  sub2, double  sub3);
	~Student();

public:

	CString name;
	CString ID;
	CString grade;
	double  sub1;
	double  sub2;
	double  sub3;
	static int size;
};