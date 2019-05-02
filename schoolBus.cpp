#include "SchoolBus.h"

////////////////SCHOOL/////////////////////////////////

School::School(string name, int morningTime, int afternoonTime, int x, int y)
{
	this->name = name;
	this->morningTime = morningTime;
	this->afternoonTime = afternoonTime;
	this->x = x;
	this->y = y;

}


////////////////STUDENT///////////////////////////////

Student::Student(string name, int age, School* school)
{
	this->name = name;
	this->age = age;
	this->school = school;
}

///////////////BUSSTOP////////////////////////////////

BusStop::BusStop(int x, int y, vector<Student*> studentsInStop)
{
	this->studentsInStop = studentsInStop;
	this->x = x;
	this->y = y;
}
//////////////BUS/////////////////////////////////////

Bus::Bus(int busId, School* school, vector<Student*> busStudents, bool apt, int capacity, int occupation)
{
	this->busId = busId;
	this->school = school;
	this->busStudents = busStudents;
	this->apt = apt;
	this->capacity = capacity;
	this->occupation = occupation;
}
//////////////GARAGE//////////////////////////////////

Garage::Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo, int x, int y)
{
	this->numberOfBuses = numberOfBuses;
	this->busesInGarage = busesInGarage;
	this->busesToGo = busesToGo;
	this->x = x;
	this->y = y;
}
