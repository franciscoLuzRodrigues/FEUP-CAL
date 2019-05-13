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

void School::setY(int y)
{
	this->y = y;
}


////////////////STUDENT///////////////////////////////

Student::Student(string name, int age, School* school)
{
	this->name = name;
	this->age = age;
	this->school = school;
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

School* Student::getSchool()
{
	return school;
}

void Student::setSchool(School* school)
{
	this->school = school;
}

///////////////BUSSTOP////////////////////////////////

BusStop::BusStop(int x, int y, vector<Student*> studentsInStop)
{
	this->studentsInStop = studentsInStop;
	this->x = x;
	this->y = y;
}
vector<Student*> BusStop::getStudentsInStop()
{
	return studentsInStop;
}
int BusStop::getX()
{
	return x;
}
void BusStop::setX(int x)
{
	this->x = x;
}
int BusStop::getY()
{
	return y;
}
void BusStop::setY(int y)
{
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

Garage::Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo, int x, int y)
{
	this->numberOfBuses = numberOfBuses;
	this->busesInGarage = busesInGarage;
	this->busesToGo = busesToGo;
	this->x = x;
	this->y = y;
}

vector<Bus*> Garage::getBusesInGarage()
{
	return busesInGarage;
}

vector<Bus*> Garage::getBusesToGo()
{
	return busesToGo;
}

int Garage::getX()
{
	return x;
}

void Garage::setX(int x)
{
	this->x = x;
}

int Garage::getY()
{
	return y;
}

void Garage::setY(int y)
{
	this->y = y;
}
