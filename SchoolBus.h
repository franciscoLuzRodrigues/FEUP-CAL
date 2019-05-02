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

};

class Student {
	string name;
	int age;
	School* school;

public:
	Student(string name, int age, School* school);

};

class BusStop {
	vector<Student*> studentsInStop;
	int x;
	int y;

public:
	BusStop(int x, int y, vector<Student*> studentsInStop);
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

};

class Garage {
	int numberOfBuses;
	vector<Bus*> busesInGarage;
	vector<Bus*> busesToGo;
	int x;
	int y;

public:
	Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo, int x, int y);
};

















#endif /* SCHOOLBUS_H_ */
