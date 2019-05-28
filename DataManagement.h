/*
* DataManagement.h
*/
#ifndef DATA_MANAGEMENT_H_
#define DATA_MANAGEMENT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "SchoolBus.h"
#include "Graph.h"

using namespace std;

class DataManager
{
private:						 //Data structures
	vector<School> schools;		 //Point of interest
	vector<BusStop> allBusStops; //Point of interest
	vector<BusStop> busStops;	//Point of interest
	vector<Student> students;
	MutablePriorityQueue<Vertex<Node>> nearestV;
	School school;
	Garage garage;
	//protected:
	//Graph<Node> graph;

public:
	Graph<Node> graph;
	DataManager(){};
	int readNodeFile(string fileName);
	int readEdgeFile(string fileName);
	int loadPointsOfInterest(string poiFilePath);
	void addSchool(School school);
	void addStudent(Student student);
	void addBusStop(BusStop busStop);
	void eraseStudent(int index) { students.erase(students.begin() + index); }
	void eraseBusStop(int index) { busStops.erase(busStops.begin() + index); }
	void eraseBus(int index) { garage.eraseBus(index); }
	vector<School> getSchools() { return schools; }
	vector<BusStop>* getAllBusStops() { return &allBusStops; }
	void addAllBusStop(BusStop busStop);
	vector<BusStop>* getBusStops() { return &busStops; }
	vector<Student> getStudents() { return students; }
	vector<Node> getPathNodes(vector<Node> &bStops);
	vector<vector<Node>> getMultPaths();
	int getPathDistance(vector<Node> path);
	vector<vector<Node>> getPath(); 
	void setSchool(School school) { this->school = school; }
	void setGarage(Garage garage) { this->garage = garage; }
	Garage getGarage() { return garage; }
	void addBusToGarage(Bus bus){garage.addBus(bus);}
	vector<Node>toVecNode(vector<BusStop> b);
	void eraseNodeWithID(vector<Node>& bStops, int id);
	BusStop* getBusStopByNode(vector<BusStop> &temp, Vertex<Node> *node);
	void increaseStudent(Student *student, int index);
	void updateQ(vector<Node> newBusStop);
	bool verifyNumberStudents();

};

#endif /* DATA_MANAGEMENT_H_ */
