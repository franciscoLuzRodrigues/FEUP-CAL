/*
 * SchoolBus.h
 */
#ifndef SCHOOLBUS_H_
#define SCHOOLBUS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class School {
	string name;
	int morningTime;
	int afternoonTime;
	int x;
	int y;

public:
	School(string name, int morningTime, int afternoonTime, int x, int y);
	string getName();
	void setName(string name);
	int getMorningTime();
	void setMorningTime(int time);
	int getAfternoonTime();
	void setAfternoonTime(int time);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

class Student {
	string name;
	int age;
	School* school;

public:
	Student(string name, int age, School* school);
	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	School* getSchool();
	void setSchool(School* school);
};

class BusStop {
	vector<Student*> studentsInStop;
	int x;
	int y;

public:
	BusStop(int x, int y, vector<Student*> studentsInStop);
	vector<Student*> getStudentsInStop();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

class Bus {
	int busId;
	School* school;
	vector<Student*> busStudents;
	bool apt;
	int capacity;
	int occupation;

public:
	Bus(int busId, School* school, vector<Student*> busStudents, bool apt, int capacity, int occupation);
	int getBusId();
	void setBusId();
	School* getSchool();
	void setSchool(School* school);
	bool getApt();
	void setApt(bool apt);
	int getCapacity();
	void setCapacity(int capacity);
	int getOccupation();
	void setOccupation(int occupation);
};

class Garage {
	int numberOfBuses;
	vector<Bus*> busesInGarage;
	vector<Bus*> busesToGo;
	int x;
	int y;

public:
	Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo, int x, int y);
	vector<Bus*> getBusesInGarage();
	vector<Bus*> getBusesToGo();
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};



#endif /* SCHOOLBUS_H_ */
