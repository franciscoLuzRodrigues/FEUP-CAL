/*
 * SchoolBus.h
 */
#ifndef SCHOOLBUS_H_
#define SCHOOLBUS_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
	int id;
	int x;
	int y;
	//int value;

	public:

	Node(int id, float x, float y) { this->id = id; this->x = x; this->y = y; }
	int getId(){ return id;}
	float getX(){return x;}
	float getY(){return y;}
	//int getValue(){return value;}

	void setId(int id){this->id = id;}
	void setX(float lat){this->x = lat;}
	void setY(float lon){this->y = lon;}
	//void setValue(int value){this->value = value;}

	bool operator == (Node other) {
		if (this->id == other.getId())
			if (this->x == other.getX())
				if (this->y == other.getY())
					return true;
		return false;
	}

	void operator = (Node other) {
		this->id == other.getId();
		this->x == other.getX();
		this->y == other.getY();
	}

	double getDistance(Node other) {
		return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2));
	}

	
};


class School {
	string name;
	int morningTime;
	int afternoonTime;
	float x;
	float y;

public:
	School(string name, int morningTime, int afternoonTime, float x, float y);
	string getName();
	void setName(string name);
	int getMorningTime();
	void setMorningTime(int time);
	int getAfternoonTime();
	void setAfternoonTime(int time);
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
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
	float x;
	float y;

public:
	BusStop(float x, float y, vector<Student*> studentsInStop);
	vector<Student*> getStudentsInStop();
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
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
	Garage(int numberOfBuses, vector<Bus*> busesInGarage, vector<Bus*> busesToGo, float x, float y);
	vector<Bus*> getBusesInGarage();
	vector<Bus*> getBusesToGo();
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
};



#endif /* SCHOOLBUS_H_ */
