#include "SchoolBus.h"

////////////////SCHOOL/////////////////////////////////

School::School(string name, int morningTime, int afternoonTime, Vertex<Node> *node)
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


void Student::getInfo()
{
	cout<<endl;
	cout << "------------------------" << endl;
	cout << "|Name: "<< name       << endl;
	cout << "|Age: "<< age      << endl;
	cout << "------------------------" << endl;
}




///////////////BUSSTOP////////////////////////////////

BusStop::BusStop(Vertex<Node> *node, string address)
{
	this->node = node;
	this->address = address;
}
vector<Student*>* BusStop::getStudentsInStop()
{
	return &studentsInStop;
}

//////////////BUS/////////////////////////////////////

Bus::Bus(bool apt, int capacity, int occupation)
{
	this->apt = apt;
	this->capacity = capacity;
	this->occupation = occupation;
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

void Bus::getInfo()
{
	cout<<endl;
	cout << "------------------------" << endl;
	cout << "|apt: "<< apt       << endl;
	cout << "|Capacity: "<< capacity      << endl;
	cout << "------------------------" << endl;
}

//////////////GARAGE//////////////////////////////////

Garage::Garage(vector<Bus> busesInGarage, int numberOfBuses, Vertex<Node> *node)
{
	companyVehicles = busesInGarage;
	this->numberOfBuses = numberOfBuses;
	this->node = node;
}

