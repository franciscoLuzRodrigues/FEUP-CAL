#include "SchoolBus.h"

////////////////SCHOOL/////////////////////////////////

School::School(string name, int morningTime, int afternoonTime, Node *node)
{
	this->name = name;
	this->morningTime = morningTime;
	this->afternoonTime = afternoonTime;
	this->node = node;

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

////////////////STUDENT///////////////////////////////

Student::Student(string name, int age)
{
	this->name = name;
	this->age = age;

}

string Student::getName()
{
	return name;
}

void Student::setName(string name)
{
	this->name = name;
}

int Student::getAge()
{
	return age;
}

void Student::setAge(int age)
{
	this->age = age;
}


///////////////BUSSTOP////////////////////////////////

BusStop::BusStop(Node* node, string address)
{
	this->node = node;
	this->address = address;
}
vector<Student*> BusStop::getStudentsInStop()
{
	return studentsInStop;
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
int Bus::getBusId()
{
	return busId;
}
void Bus::setBusId()
{
	this->busId = busId;
}
School * Bus::getSchool()
{
	return school;
}
void Bus::setSchool(School * school)
{
	this->school = school;
}
bool Bus::getApt()
{
	return apt;
}
void Bus::setApt(bool apt)
{
	this->apt = apt;
}
int Bus::getCapacity()
{
	return capacity;
}
void Bus::setCapacity(int capacity)
{
	this->capacity = capacity;
}
int Bus::getOccupation()
{
	return occupation;
}
void Bus::setOccupation(int occupation)
{
	this->occupation = occupation;
}
//////////////GARAGE//////////////////////////////////

Garage::Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo)
{
	this->numberOfBuses = numberOfBuses;
	this->busesInGarage = busesInGarage;
	this->busesToGo = busesToGo;

}

vector<Bus*> Garage::getBusesInGarage()
{
	return busesInGarage;
}

vector<Bus*> Garage::getBusesToGo()
{
	return busesToGo;
}
