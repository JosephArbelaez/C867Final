/*
	roster.h
	Created on: Aug 23, 2019
	Author: Joseph Arbelaez
*/

#include <iostream>
#include "degree.h"
using namespace std;

#ifndef ROSTER_H_
#define ROSTER_H_


class Roster {
public:
	Roster();
	~Roster();
	void Add (string id, string firstName, string lastName, string email, int age, int x, int y, int z, Degree degree);
	void remove(string id);
	void printAll();
	void printAverageDaysInCourse(string id);
	void printInvalidEmails();
	void printByDegreeProgram(Degree DegreeProgram);
	Student* classRosterArray[5];
};


#endif
