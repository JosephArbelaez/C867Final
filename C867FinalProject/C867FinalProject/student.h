/*
	student.h
	Created on: Aug 23, 2019
	Author: Joseph Arbelaez
*/

#include <iostream>
#include "degree.h"
using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
public:
	Student();
	Student(string id, string firstName, string lastName, string email, int age, int x, int y, int z, Degree degree);
	Student(Student&);
	Student& operator=(const Student&);
	~Student();

	string GetStudentId();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDays();
	virtual Degree getDegreeProgram();

	void SetStudentID(string id);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDays(int x,int y,int z);
	void SetDegree(Degree degree);

	virtual void Print();
protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[3];
	Degree degree;
};

#endif
