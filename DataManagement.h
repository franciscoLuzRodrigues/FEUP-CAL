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

class DataManager{
    private:       //Data structures
        vector<School > schools; //Point of interest
        vector<BusStop > busStops; //Point of interest
        vector<Student > students; 

        //Garage garage;

    protected:
    Graph<Node> graph;

    public:
		DataManager() {}
		int readNodeFile(string fileName);
		int readEdgeFile(string fileName);
        int loadPointsOfInterest(string poiFilePath);
        void addSchool(School school);
		void addStudent(Student student);
		void addBusStop(BusStop busStop);
		vector<School > getSchools() {return schools; }
		vector<BusStop > getBusStops() {return busStops; }
		vector<Student > getStudents() {return students; }

};

#endif /* DATA_MANAGEMENT_H_ */