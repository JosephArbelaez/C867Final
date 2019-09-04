/*
	securityStudent.cpp
	Aug 23, 2019
	Joseph Arbelaez
*/

#include <iostream>
using namespace std;
#include "SecurityStudent.h"

SecurityStudent::SecurityStudent() {
	this->degree = SECURITY;
}
SecurityStudent::SecurityStudent(SecurityStudent& seStudent) {
	this->age = seStudent.age;
	this->firstName = seStudent.firstName;
	this->lastName = seStudent.lastName;
	this->days[0] = seStudent.days[0];
	this->days[1] = seStudent.days[1];
	this->days[2] = seStudent.days[2];
	this->degree = seStudent.degree;
	this->emailAddress = seStudent.emailAddress;
	this->studentId = seStudent.studentId;
}
SecurityStudent& SecurityStudent::operator=(const SecurityStudent& seStudent) {
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
SecurityStudent::~SecurityStudent() {
	//delete[] this->days;
}
Degree SecurityStudent::getDegreeProgram() {
	return degree;
}
