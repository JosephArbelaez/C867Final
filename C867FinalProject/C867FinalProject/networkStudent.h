/*
	networkStudent.h
	Created on: Aug 23, 2019
	Author: Joseph Arbelaez
*/

#ifndef NETWORKSTUDENT_H_
#define NETWORKSTUDENT_H_
#include "student.h"

class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(NetworkStudent&);
	~NetworkStudent();
	NetworkStudent& operator=(const NetworkStudent&);

	Degree getDegreeProgram();
private:
	Degree degree;
};

#endif
