/*
	securityStudent.h
	Created on: Aug 23, 2019
	Author: Joseph Arbelaez
*/

#ifndef SECURITYSTUDENT_H_
#define SECURITYSTUDENT_H_
#include "student.h"

class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(SecurityStudent&);
	~SecurityStudent();
	SecurityStudent& operator=(const SecurityStudent&);

	Degree getDegreeProgram();
private:
	Degree degree;
};

#endif
