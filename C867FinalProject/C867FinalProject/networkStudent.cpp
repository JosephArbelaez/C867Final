/*
	networkStudent.cpp
	Aug 23, 2019
	Joseph Arbelaez
*/

#include "networkStudent.h"
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() {
	this->degree = NETWORK;
}
NetworkStudent::NetworkStudent(NetworkStudent& nStudent) {
	this->age = nStudent.age;
	this->firstName = nStudent.firstName;
	this->lastName = nStudent.lastName;
	this->days[0] = nStudent.days[0];
	this->days[1] = nStudent.days[1];
	this->days[2] = nStudent.days[2];
	this->degree = nStudent.degree;
	this->emailAddress = nStudent.emailAddress;
	this->studentId = nStudent.studentId;
}
NetworkStudent& NetworkStudent::operator=(const NetworkStudent& seStudent) {
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
NetworkStudent::~NetworkStudent() {
//	delete[] this->days;
}
Degree NetworkStudent::getDegreeProgram() {
	return degree;
}
