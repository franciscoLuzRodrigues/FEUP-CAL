/*
 * SchoolBus.h
 */
#ifndef SCHOOLBUS_H_
#define SCHOOLBUS_H_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Graph.h"

using namespace std;

class Node {
	int id;
	float x;
	float y;
	//int value;

	public:
	Node(int id, float x, float y) { this->id = id; this->x = x; this->y = y; }
	int getID(){ return id;}
	float getX(){return x;}
	float getY(){return y;}
	//int getValue(){return value;}

	void setId(int id){this->id = id;}
	void setX(float lat){this->x = lat;}
	void setY(float lon){this->y = lon;}
	//void setValue(int value){this->value = value;}


	bool operator == (Node other) {
		if (this->id == other.getID())
			if (this->x == other.getX())
				if (this->y == other.getY())
					return true;
		return false;
	}

	void operator = (Node other) {
		this->id = other.getID();
		this->x = other.getX();
		this->y = other.getY();
	}

	double getDistance(Node other) {
		return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2));
	}
	
};


class School {
	string name;
	int morningTime;
	int afternoonTime;
	Vertex<Node> *node;

public:
	School(){}
	School(string name, int morningTime, int afternoonTime, Vertex<Node> *node);
	string getName();
	void setName(string name);
	int getMorningTime();
	void setMorningTime(int time);
	int getAfternoonTime();
	void setAfternoonTime(int time);
	void setNode(Vertex<Node>* node) { this->node = node; }
	Vertex<Node>* getNode() { return node; }
};

class Student {
	string name;
	int age;

public:
	Student(string name, int age);
	string getName();
	void setName(string name);
	int getAge();
	void setAge(int age);
	void getInfo();
};

class BusStop {
	vector<Student*> studentsInStop;
	string address;
	Vertex<Node> *node;

public:
	BusStop(Vertex<Node> *node,string address);
	vector<Student*> getStudentsInStop();
	void addStudentInStop(Student* student){studentsInStop.push_back(student);}
	void eraseStudentInStop(int index){studentsInStop.erase(studentsInStop.begin() + index);}
	string getAddress(){return address;}
	void setAddress(string address){this->address = address;}
	void setNode(Vertex<Node> *node) { this->node = node; }
	Vertex<Node> * getNode() { return node; }
};

class Bus {
	int busId;
	bool apt;
	int capacity;
	int occupation;

public:
	Bus(int busId, bool apt, int capacity, int occupation);
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
	vector<Bus*> companyVehicles;
	Vertex<Node> *node;

public:
	Garage(vector<Bus*> busesInGarage, int numberOfBuses, Vertex<Node> *node);
	vector<Bus *> getBuses(){return companyVehicles;}
	Vertex<Node> *getNode(){return node;}
};

#endif /* SCHOOLBUS_H_ */
