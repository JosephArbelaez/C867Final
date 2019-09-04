/*
	softwareStudent.cpp
	Aug 23, 2019
	Joseph Arbelaez
*/

#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() {
	this->degree = SOFTWARE;
}
SoftwareStudent::SoftwareStudent(SoftwareStudent& soStudent) {
	this->age = soStudent.age;
	this->firstName = soStudent.firstName;
	this->lastName = soStudent.lastName;
	this->days[0] = soStudent.days[0];
	this->days[1] = soStudent.days[1];
	this->days[2] = soStudent.days[2];
	this->degree = soStudent.degree;
	this->emailAddress = soStudent.emailAddress;
	this->studentId = soStudent.studentId;
}
SoftwareStudent& SoftwareStudent::operator=(const SoftwareStudent& seStudent) {
	this->age = seStudent.age;
	this->firstName = seStudent.firstName;
	this->lastName = seStudent.lastName;
	this->days[0] = seStudent.days[0];
	this->days[1] = seStudent.days[1];
	this->days[2] = seStudent.days[2];
	this->degree = seStudent.degree;
	this->emailAddress = seStudent.emailAddress;
	this->studentId = seStudent.studentId;
	return *this;
}
SoftwareStudent::~SoftwareStudent() {
//	delete[] this->days;
}
Degree SoftwareStudent::getDegreeProgram() {
	return degree;
}

