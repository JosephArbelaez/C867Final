/*
	softwareStudent.h
	Created on: Aug 23, 2019
	Author: Joseph Arbelaez
*/

#ifndef SOFTWARESTUDENT_H_
#define SOFTWARESTUDENT_H_
#include "student.h"

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(SoftwareStudent&);
	~SoftwareStudent();
	SoftwareStudent& operator=(const SoftwareStudent&);

	Degree getDegreeProgram();
private:
	Degree degree;
};

#endif
