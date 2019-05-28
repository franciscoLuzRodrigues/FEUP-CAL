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
private:
	vector<School> schools;
	vector<BusStop> allBusStops;
	vector<BusStop> busStops;
	vector<Student> students;
	MutablePriorityQueue<Vertex<Node>> nearestV;
	School school;
	Garage garage;

public:
	/**
 	* @brief Graph tthat stores the map information loaded from the files
 	* 
 	*/
	Graph<Node> graph;

	/**
	 * @brief Construct a new Data Manager object
	 * 
	 */
	DataManager(){};

	/**
	 * @brief Reads Vertex information
	 * 
	 * @param fileName Name of the file to be read
	 * @return int - 0 if successfull and 1 if not
	 */
	int readNodeFile(string fileName);

	/**
	 * @brief Reads Edge information
	 * 
	 * @param fileName Name of the file to be read
	 * @return int - 0 if successfull and 1 if not
	 */
	int readEdgeFile(string fileName);

	/**
	 * @brief Reads information about points of interest such as schools and bus stops
	 * 
	 * @param fileName Name of the file to be read
	 * @return int - 0 if successfull and 1 if not
	 */
	int loadPointsOfInterest(string poiFilePath);

	/**
	 * @brief Adds school to the schools vector
	 * 
	 * @param school new school to be added
	 */
	void addSchool(School school);

	/**
	 * @brief Adds a student to the student vector
	 * 
	 * @param student new Student to be added
	 */
	void addStudent(Student student);

	/**
	 * @brief Adds a new busStop to the vector
	 * 
	 * @param busStop new BusStop to be added
	 */
	void addBusStop(BusStop busStop);

	/**
	 * @brief  Removes the student at position index of vector Students
	 * 
	 * @param index of the students vector
	 */
	void eraseStudent(int index) { students.erase(students.begin() + index); }

	/**
	 * @brief Removes the busStop at position index of vector busStops
	 * 
	 * @param index of the busStop vector
	 */
	void eraseBusStop(int index) { busStops.erase(busStops.begin() + index); }

	/**
	 * @brief Removes a bus from the garage vector of buses
	 * 
	 * @param index of the garage bus vector
	 */
	void eraseBus(int index) { garage.eraseBus(index); }

	/**
	 * @brief Get the Schools object
	 * 
	 * @return vector<School> all possible schools
	 */
	vector<School> getSchools() { return schools; }

	/**
	 * @brief Get the All Bus Stops vector
	 * 
	 * @return vector<BusStop>* all possible busStops
	 */
	vector<BusStop> *getAllBusStops() { return &allBusStops; }

	/**
	 * @brief Adds a bus stop to the AllBusStops vector
	 * 
	 * @param busStop new busStop
	 */
	void addAllBusStop(BusStop busStop);

	/**
	 * @brief Gets the vector with the busStops where the bus will have to pass
	 * 
	 * @return vector<BusStop>* busStopsVector
	 */
	vector<BusStop> *getBusStops() { return &busStops; }

	/**
	 * @brief Get the Students vector
	 * 
	 * @return vector<Student> vector with all the students
	 */
	vector<Student> getStudents() { return students; }

	//FRANCISCO

	/**
	 * @brief Generates a vector with the bus stops ordered by the position the bus has to pass them
	 * 
	 * @param bStops vector to be ordered
	 * @return vector<Node> with the nodes corresponding to each bus stop in order
	 */
	vector<Node> getPathNodes(vector<Node> &bStops);

	/**
	 * @brief Calculates each bus's path (using the njearest points to the garage)
	 * 
	 * @return vector<vector<Node>> vector of vectors where each vector represents a bus's path
	 */
	vector<vector<Node>> getMultPaths();

	/**
	 * @brief Get the path for each bus, generating a path using a vector of nodes 
	 * 
	 * @return vector<vector<Node>> vector where each index contains a complete path of a bus
	 */
	vector<vector<Node>> getPath();

	/**
	 * @brief Set the School object
	 * 
	 * @param school new school
	 */
	void setSchool(School school) { this->school = school; }

	/**
	 * @brief Set the Garage object
	 * 
	 * @param garage new garage
	 */
	void setGarage(Garage garage) { this->garage = garage; }

	/**
	 * @brief Get the Garage object
	 * 
	 * @return Garage the current garage
	 */
	Garage getGarage() { return garage; }

	/**
	 * @brief Adds a bus to a garage so it can be used for transport
	 * 
	 * @param bus  to be added
	 */
	void addBusToGarage(Bus bus) { garage.addBus(bus); }

	/**
	 * @brief Construct a new vector<Node> based on the busStops b
	 * 
	 * @param b Vector of busStops
	 * 
	 * @return vector<Node> vector with the nodes that correspond to the b busStops
	 */
	vector<Node> toVecNode(vector<BusStop> b);

	/**
	 * @brief Erases bus stops based on their ID
	 * 
	 * @param bStops vector where it is intended to delete
	 * @param id of the busStop to be deleted
	 */
	void eraseNodeWithID(vector<Node> &bStops, int id);

	/**
	 * @brief Find and returns the busStop with the vertex Node
	 * 
	 * @param temp vector of busStops
	 * @param node vertex to be foung
	 * @return BusStop* with vertex Node
	 */
	BusStop *getBusStopByNode(vector<BusStop> &temp, Vertex<Node> *node);

	/**
	 * @brief Adds a student a bus stop
	 * 
	 * @param student to be added to the bus stop
	 * @param index of the bus stop to wich the student will be added
	 */
	void increaseStudent(Student *student, int index);

	/**
	 * @brief Empties the queue and reinsertes all nodes in the queue in order to update it
	 * 
	 * @param newBusStop nodes to be added to the queue
	 */
	void updateQ(vector<Node> newBusStop);

	/**
	 * @brief Verifies if the number of students to be transported is less then the total capacity of all buses
	 * 
	 * @return true if the number of students to be transported is less then the total capacity of all buses
	 * @return false otherwise
	 */
	bool verifyNumberStudents();

	void organizeBuses();
};

#endif /* DATA_MANAGEMENT_H_ */
