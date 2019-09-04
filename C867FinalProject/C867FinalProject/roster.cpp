/*
	roster.cpp
	Aug 23, 2019
	Joseph Arbelaez
*/

#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <crtdbg.h>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

// Variables
int pointer = 0;

Roster::Roster()
{
	for (int i = 0; i < 5; i++)
		classRosterArray[i] = new Student();
}
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "classRosterArray deleted!" << endl;
}

void Roster::Add(string id, string firstName, string lastName, string email, int age, int x, int y, int z, Degree degree) {

	if (degree == SECURITY) {
		SecurityStudent bob;
		bob.SetStudentID(id);
		bob.SetFirstName(firstName);
		bob.SetLastName(lastName);
		bob.SetEmail(email);
		bob.SetAge(age);
		bob.SetDays(x, y, z);
		bob.SetDegree(degree);
		*classRosterArray[pointer] = bob;
		pointer++;
	}
	else if (degree == NETWORK) {
		NetworkStudent bob;
		bob.SetStudentID(id);
		bob.SetFirstName(firstName);
		bob.SetLastName(lastName);
		bob.SetEmail(email);
		bob.SetAge(age);
		bob.SetDays(x, y, z);
		bob.SetDegree(degree);
		*classRosterArray[pointer] = bob;
		pointer++;
	}
	else if (degree == SOFTWARE) {
		SoftwareStudent bob;
		bob.SetStudentID(id);
		bob.SetFirstName(firstName);
		bob.SetLastName(lastName);
		bob.SetEmail(email);
		bob.SetAge(age);
		bob.SetDays(x, y, z);
		bob.SetDegree(degree);
		*classRosterArray[pointer] = bob;
		pointer++;
	}
}
void Roster::remove(string id) {
	bool studentFound = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentId() == id) {
			studentFound = true;
			classRosterArray[i] = new Student;
		}
	}

	if (!studentFound) {
		cout << "Error: Student does not exist." << endl;
	}
	else {
		cout << "Student Deleted" << endl;
	}
}
void Roster::printAll() {
	
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++) {
		Student* bob = classRosterArray[i];
		bob->Print();
		switch (classRosterArray[i]->getDegreeProgram()) {
		case 0:
			cout << "SECURITY" << endl;
			break;
		case 1:
			cout << "NETWORK" << endl;
			break;
		case 2:
			cout << "SOFTWARE" << endl;
			break;
		}
		cout << endl;
	}
}
void Roster::printAverageDaysInCourse(string id) {
	bool studentFound = false;
	int x = 0, y = 0, z = 0;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentId() == id) {
			x = classRosterArray[i]->GetDays()[0];
			y = classRosterArray[i]->GetDays()[1];
			z = classRosterArray[i]->GetDays()[2];
			studentFound = true;
			cout << id <<" - AVERAGE DAYS:" << ((x + y + z) / 3) << endl;
			break;
		}
	}

	if (!studentFound) {
		cout << "ERROR: STUDENT DOESN'T EXIST!!!!" << endl;

	}
}
void Roster::printInvalidEmails() {
	vector<string> invalidEmailVector(0);
	string email = "";

	for (int i = 0; i < 5; i++) {
		email = classRosterArray[i]->GetEmail();

		if (email.find(' ') != string::npos) {
			invalidEmailVector.push_back(classRosterArray[i]->GetEmail());
		} if (email.find('@') == string::npos || email.find('.') == string::npos) {
			invalidEmailVector.push_back(classRosterArray[i]->GetEmail());
		}
	}
 
	if (invalidEmailVector.size() > 0) {
		for (int i = 0; i < invalidEmailVector.size(); i++) {
			cout << invalidEmailVector[i] << endl;
		}
	}
	if (invalidEmailVector.size() == 0) {
		cout << "All emails are valid.";
	}
}
void Roster::printByDegreeProgram(Degree DegreeProgram) {
	string name = "";

	switch (DegreeProgram) {
	case 0:
		cout << "Students in Security degree program " << endl;
		break;	
	case 1:
		cout << "Students in Network degree program " << endl;
		break;	
	case 2:
		cout << "Students in Software degree program " << endl;
		break;
	default:
		cout << "DEGREE DOESN'T EXIST!!" << endl;
	}

	cout << "---------------------------------------" << endl;

	for (int i = 0; i < 5; i++) {
		Degree degree = classRosterArray[i]->getDegreeProgram();

		if (degree == DegreeProgram) {
			name = classRosterArray[i]->GetFirstName() + ", " + classRosterArray[i]->GetLastName();
			cout << name << endl;
		} 
	}
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Joseph,Arbelaez,Jarbel3@wgu.edu,29,12,29,30,SOFTWARE"
	};
	int count = sizeof(studentData) / sizeof(studentData[0]);
	char security[] = "SECURITY";
	char networking[] = "NETWORK";
	char software[] = "SOFTWARE";
	Roster classRoster;

	for (int i = 0; i < count; i++) {
		if (studentData[i].find(security) != string::npos) {
			size_t position = 0;
			string str = studentData[i];
			string tempstr = "";
			string strArray[9];
			int i = 0;

			while ((position = str.find(",")) != string::npos) {
				tempstr = str.substr(0, position);
				strArray[i] = tempstr;
				str.erase(0, position + 1);
				i++;
			}

			classRoster.Add(strArray[0], strArray[1], strArray[2], strArray[3], stoi(strArray[4]), stoi(strArray[5]), stoi(strArray[6]), stoi(strArray[7]), SECURITY);
			continue;

		}
		else if (studentData[i].find(networking) != string::npos) {
			size_t position = 0;
			string str = studentData[i];
			string tempstr = "";
			string strArray[9];
			int i = 0;

			while ((position = str.find(",")) != string::npos) {
				tempstr = str.substr(0, position);
				strArray[i] = tempstr;
				str.erase(0, position + 1);
				i++;
			}

			classRoster.Add(strArray[0], strArray[1], strArray[2], strArray[3], stoi(strArray[4]), stoi(strArray[5]), stoi(strArray[6]), stoi(strArray[7]), NETWORK);
			continue;

		}
		else if (studentData[i].find(software) != string::npos) {
			size_t position = 0;
			string str = studentData[i];
			string tempstr = "";
			string strArray[9];
			int i = 0;

			while ((position = str.find(",")) != string::npos) {
				tempstr = str.substr(0, position);
				strArray[i] = tempstr;
				str.erase(0, position + 1);
				i++;
			}

			classRoster.Add(strArray[0], strArray[1], strArray[2], strArray[3], stoi(strArray[4]), stoi(strArray[5]), stoi(strArray[6]), stoi(strArray[7]), SOFTWARE);
			continue;
		}
	}

	// To Screen
	cout << "Course: C867 Scripting and Programming" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: #001007709" << endl;
	cout << "Name: Joseph Arbelaez" << endl << endl;


	// Functions
	//classRoster.printAll();
	//classRoster.printInvalidEmails();

	//for (int i = 0; i < count; i++) {
	//	string id = classRoster.classRosterArray[i]->GetStudentId();
	//	classRoster.printAverageDaysInCourse(id);
	//}	
	
	//classRoster.printByDegreeProgram(NETWORK);
	//classRoster.remove("A3");
	//classRoster.remove("A3");

}