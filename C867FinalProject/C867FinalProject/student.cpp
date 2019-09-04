/*
	student.cpp
	Aug 23, 2019
	Joseph Arbelaez
*/

#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

Student::Student() {
	this->studentId = "";
	this->firstName = "-";
	this->lastName = "-";
	this->emailAddress = "-";
	this->age = 0;
	this->days[3];
	this->degree;
}
Student::Student(string id, string firstName, string lastName, string email, int age, int x, int y, int z, Degree degree) {
	this->studentId = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = email;
	this->age = age;
	this->days[3];
	this->days[0] = x;
	this->days[1] = y;
	this->days[2] = z;
	this->degree = degree;
}
Student::Student(Student& Student) {
	this->age = Student.age;
	this->firstName = Student.firstName;
	this->lastName = Student.lastName;
	this->days[0] = Student.days[0];
	this->days[1] = Student.days[1];
	this->days[2] = Student.days[2];
	this->degree = Student.degree;
	this->emailAddress = Student.emailAddress;
	this->studentId = Student.studentId;
}
Student& Student::operator=(const Student& Student) {
	this->age = Student.age;
	this->firstName = Student.firstName;
	this->lastName = Student.lastName;
	this->days[0] = Student.days[0];
	this->days[1] = Student.days[1];
	this->days[2] = Student.days[2];
	this->degree = Student.degree;
	this->emailAddress = Student.emailAddress;
	this->studentId = Student.studentId;
	return *this;
}
Student::~Student(){
	
}
string Student::GetStudentId() {
	return studentId;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmail() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int* Student::GetDays() {
	return days;
}

void Student::SetStudentID(string id) {
	this->studentId = id;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmail(string email) {
	this->emailAddress = email;
}
void Student::SetAge(int age) {
	this->age = age;
}
void Student::SetDays(int x, int y, int z){
	this-> days[0] = x;
	this-> days[1] = y;
	this-> days[2] = z;
}
void Student::SetDegree(Degree degree) {
	this->degree = degree;
}

void Student::Print() {
	cout << studentId << endl << firstName << endl << lastName << endl << emailAddress << endl << age << endl << days[0] << endl << days[1] << endl << days[2] << endl;
}

Degree Student::getDegreeProgram() {
	return degree;
}