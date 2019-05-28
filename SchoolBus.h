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
	
	/**@brief Node ID;  */
	int id;
	
	/**@brief X coordinate;  */
	float x;
	
	/**@brief Y coordinate;  */
	float y;

	public:
	/**
	 * @brief Construct a new Node object
	 * 
	 * @param id Node id
	 * @param x X coordinate
	 * @param y Y coordinate
	 */
	Node(int id, float x, float y) { this->id = id; this->x = x; this->y = y; }

	/**
	 * @brief Gets node ID
	 * 
	 * @return int ID Node id
	 */
	int getID(){ return id;}

	/**
	 * @brief Gets node X coordinate
	 * 
	 * @return float Node's X coordinate
	 */
	float getX(){return x;}

	/**
	 * @brief Gets node Y coordinate
	 * 
	 * @return float Node's Y coordinate
	 */
	float getY(){return y;}

	/**
	 * @brief Sets the Id
	 * 
	 * @param id new id
	 */
	void setId(int id){this->id = id;}

	/**
	 * @brief Sets the X coordinate
	 * 
	 * @param x new X 
	 */
	void setX(float x){this->x = x;}

	/**
	 * @brief Sets the X coordinate
	 * 
	 * @param y 
	 */
	void setY(float y){this->y = y;}

	/**
	 * @brief operator used to compare nodes
	 * 
	 * @param other node to be compared
	 * @return true if nodes are the same
	 * @return false if nodes are not the same
	 */
	bool operator == (Node other) {
		if (this->id == other.getID())
			if (this->x == other.getX())
				if (this->y == other.getY())
					return true;
		return false;
	}

	/**
	 * @brief operator used to copy data from one Node to another
	 * 
	 * @param other node to be copied
	 */
	void operator = (Node other) {
		this->id = other.getID();
		this->x = other.getX();
		this->y = other.getY();
	}

	/**
	 * @brief Get the distance between this node and another
	 * 
	 * @param other node at unkown distance
	 * @return double distance between the nodes
	 */
	double getDistance(Node other) {
		return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2));
	}
	
};


class School {
	
	/**@brief school's name;  */
	string name;

	/**@brief time at which school opens;  */
	int morningTime;

	/**@brief time at which school closes;  */
	int afternoonTime;

	/**@brief Vertex that defines school coordinates;  */
	Vertex<Node> *node;

public:
	/**
	 * @brief Construct a new School object
	 * 
	 */
	School(){}
	/**
	 * @brief Construct a new School object
	 * 
	 * @param name of the school
	 * @param morningTime time at which school opens
	 * @param afternoonTime time at which school closes
	 * @param node Vertex that defines school coordinates
	 */
	School(string name, int morningTime, int afternoonTime, Vertex<Node> *node);

	/**
	 * @brief Gets name of the school
	 * 
	 * @return string name of school
	 */
	string getName();

	/**
	 * @brief Set name of the school
	 * 
	 * @param name new name
	 */
	void setName(string name);

	/**
	 * @brief Get Morning Time
	 * 
	 * @return int morning time
	 */
	int getMorningTime();

	/**
	 * @brief Set Morning Time 
	 * 
	 * @param time new morning time
	 */
	void setMorningTime(int time);

	/**
	 * @brief Get Afternoon Time
	 * 
	 * @return int afternoon time
	 */
	int getAfternoonTime();

	/**
	 * @brief Set the Afternoon Time object
	 * 
	 * @param time new afternoon time
	 */
	void setAfternoonTime(int time);

	/**
	 * @brief Set the Vertex that contains the school's node
	 * 
	 * @param node new node
	 */
	void setNode(Vertex<Node>* node) { this->node = node; }

	/**
	 * @brief Get school's vertex
	 * 
	 * @return Vertex<Node>* node
	 */
	Vertex<Node>* getNode() { return node; }
};

class Student {

	/**@brief Student name;  */
	string name;

	/**@brief Student age;  */
	int age;

public:
	/**
	 * @brief Construct a new Student object
	 * 
	 * @param name of the student
	 * @param age of the student
	 */
	Student(string name, int age);

	/**
	 * @brief Get student's name
	 * 
	 * @return string student's name
	 */
	string getName();

	/**
	 * @brief Set student's name
	 * 
	 * @param name new student's name
	 */
	void setName(string name);

	/**
	 * @brief Get student's age
	 * 
	 * @return int student's age
	 */
	int getAge();

	/**
	 * @brief Set student's age
	 * 
	 * @param age new student's age
	 */
	void setAge(int age);

	/**
	 * @brief Get student's information
	 * 
	 */
	void getInfo();

	/**
	 * @brief operator used to compare students
	 * 
	 * @param other student to be compared
	 * @return true if students are the same
	 * @return false if students are not the same
	 */
	bool operator ==(Student other){
		if(this->name == other.getName() && this->age == other.getAge())
				return true;
			else return false;
	}
};

class BusStop {

	/**@brief vector of students in the busStop;  */
	vector<Student*> studentsInStop;
	
	/**@brief busStop address;  */
	string address;
	
	/**@brief node where it's located;  */
	Vertex<Node> *node;

public:
	/**
	 * @brief Construct a new Bus Stop object
	 * 
	 * @param node Vertex that contains Bus Stop location
	 * @param address of the Bus Stop
	 */
	BusStop(Vertex<Node> *node,string address);

	/**
	 * @brief Get pointer to vector containing the students at this bus stop
	 * 
	 * @return vector<Student*>* pointer to vector containing the students
	 */
	vector<Student*>* getStudentsInStop();

	/**
	 * @brief Adds a student to the Bus Stop
	 * 
	 * @param student to be added
	 */
	void addStudentInStop(Student* student){studentsInStop.push_back(student);}

	/**
	 * @brief Erases a student from the Bus Stop
	 * 
	 * @param index of the student in studentsInStop vector
	 */
	void eraseStudentInStop(int index){studentsInStop.erase(studentsInStop.begin() + index);}

	/**
	 * @brief Get the Address of the bus stop
	 * 
	 * @return string addrees
	 */
	string getAddress(){return address;}

	/**
	 * @brief Set the Address of the bus stop
	 * 
	 * @param address new bus stop address
	 */
	void setAddress(string address){this->address = address;}

	/**
	 * @brief Set the Node(Vertex<Node>) of the bus stop 
	 * 
	 * @param node new Vertex<Node>
	 */
	void setNode(Vertex<Node> *node) { this->node = node; }
	
	/**
	 * @brief Get the Node(Vertex<Node>) of the bus stop
	 * 
	 * @return Vertex<Node>* Vertex
	 */
	Vertex<Node> * getNode() { return node; }
};

class Bus {

	/**@brief true if the bus isn't apt;  */
	bool apt;
	
	/**@brief bus capatity;  */
	int capacity;
	
	/**@brief number of students in the bus;  */
	int occupation;

public:

	/**
	 * @brief Construct a new Bus object
	 * 
	 * @param apt - checks if bus can transport
	 * @param capacity - bus's capacity
	 * @param occupation - bus's curret occupation
	 */
	Bus(bool apt, int capacity, int occupation);
	
	/**
	 * @brief Get the bus's destination
	 * 
	 * @return School* - pointer to a School object that corresponds to the bus destination
	 */
	School* getSchool();

	/**
	 * @brief Set the bus's destination
	 * 
	 * @param school - pointer to a School object that corresponds to the bus destination
	 */
	void setSchool(School* school);

	/**
	 * @brief Get the Apt object
	 * 
	 * @return true if bus is able to transport (is not broken)
	 * @return false otherwise
	 */
	bool getApt();

	/**
	 * @brief Set the Apt object
	 * 
	 * @param apt 
	 */
	void setApt(bool apt);

	/**
	 * @brief Get the bus Capacity
	 * 
	 * @return int 
	 */
	int getCapacity();

	/**
	 * @brief Set the bus Capacity
	 * 
	 * @param capacity 
	 */
	void setCapacity(int capacity);
	
	/**
	 * @brief Get the bus Occupation
	 * 
	 * @return amount of students in the bus
	 */
	int getOccupation();

	/**
	 * @brief Set the bus Occupation
	 * 
	 * @param new occupation value 
	 */
	void setOccupation(int occupation);

	/**
	 * @brief Displays the bus information
	 * 
	 */
	void getInfo();
};

class Garage {

	/**@brief number of buses in the bus;  */
	int numberOfBuses;

	/**@brief vector with the vehicles;  */
	vector<Bus> companyVehicles;

	/**@brief node where the garage is located;  */
	Vertex<Node> *node;

public:

	/**
	 * @brief Construct a new Garage object
	 * 
	 * @param busesInGarage vector with all the buses in the garage
	 * @param numberOfBuses number of buses in the garage
	 * @param node Node where the garage is located
	 */
	Garage(vector<Bus> busesInGarage, int numberOfBuses, Vertex<Node> *node);

	/**
	 * @brief Construct a new Garage object
	 * 
	 */
	Garage(){}

	/**
	 * @brief Get the Buses vector
	 * 
	 * @return vector<Bus > vector of buses
	 */
	vector<Bus > getBuses(){return companyVehicles;}

	/**
	 * @brief Get the vertex object
	 * 
	 * @return Vertex<Node>* vertex
	 */
	Vertex<Node> *getNode(){return node;}

	/**
	 * @brief Adds a new bus to the garage
	 * 
	 * @param bus new bus to be added
	 */
	void addBus(Bus bus){companyVehicles.push_back(bus);}

	/**
	 * @brief removed a bus from the buses vector
	 * 
	 * @param index of the bus to be removed
	 */
	void eraseBus(int index){companyVehicles.erase(companyVehicles.begin() + index);}
};

#endif /* SCHOOLBUS_H_ */
