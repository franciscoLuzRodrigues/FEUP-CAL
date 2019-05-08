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

string School::getName()
{
	return name;
}

void School::setName(string name)
{
	this->name = name;
}

int School::getMorningTime()
{
	return morningTime;
}

void School::setMorningTime(int time)
{
	morningTime = time;
}

int School::getAfternoonTime()
{
	return afternoonTime;
}

void School::setAfternoonTime(int time)
{
	afternoonTime = time;
}

int School::getX()
{
	return x;
}

void School::setX(int x)
{
	this->x = x;
}

int School::getY()
{
	return y;
}

void School::getY(int y)
{
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
