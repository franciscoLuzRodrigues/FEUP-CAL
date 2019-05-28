#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Graph.h"
#include "SchoolBus.h"
#include "DataManagement.h"
#include "graphviewer.h"
#include <string>

using namespace std;

vector<string> cityVec = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto", "Viseu", "MapTest1"};
DataManager dataMan;
void main_menu();

//INPUT VALIDATION//
/**
 * @brief Checks if the string inputed has a number when it is not supposed to
 * @param s String to be analyzed
 * @return Holds true if the string is correct
 */
bool hasNumber(string s)
{
    return(s.find_first_of("0123456789") == string::npos);
}

////GENERAL FUNCTIONS//// (used throughout project, mostly for input verification)
int Nav(int bottom, int top)
{ //tests for valid input keys and returns the inputed char
	int key;
	cin >> key;
	while (cin.fail() || key < bottom || key > top)
	{ //Problem with cin getting corrupted if several characters are introduced
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid Input!" << endl;
		cin >> key;
	}
	cin.clear();
	cin.ignore(100, '\n');
	return key;
}

void showStudents()
{
	int choice;
	for(unsigned int i=0; i<dataMan.getStudents().size(); i++)
	{
		cout << i << ". " << dataMan.getStudents().at(i).getName() << endl;
	}

	cout << dataMan.getStudents().size() << ". Exit" << endl;
	choice = Nav(0, dataMan.getStudents().size());
	
	if (choice == dataMan.getStudents().size())
	{
		main_menu();
	}

	dataMan.getStudents().at(choice).getInfo();
	//dataMan.printStudentAddress(dataMan.getStudents().at(choice).getName());
}

void removeStudent()
{
	string name;
	cout<<"What's the Student's name? "<<endl;
	cin>>name;
    while(!hasNumber(name))
    {
        cout << "Invalid name, try again: "<< endl;
        cin>>name;
    }
	
	for(unsigned int i=0;i<dataMan.getBusStops()->size(); i++)
	{
		int studentSize = dataMan.getBusStops()->at(i).getStudentsInStop().size();
		cout<<"busStopSize "<<dataMan.getBusStops()->at(i).getStudentsInStop().size()<<endl;
		for(int j=0; j< studentSize; j++)
		{
			cout<<"im burro "<< dataMan.getBusStops()->at(i).getStudentsInStop().at(j)->getName()<<endl;
			Student studentInStop =*dataMan.getBusStops()->at(i).getStudentsInStop().at(j);
			cout<<"Name q aparece "<<studentInStop.getName()<<" name pedido "<<name<<endl;
			fflush(stdout);
			if(studentInStop.getName() == name)
			{
				cout<<"studentSize"<<studentSize<<endl;
				if(studentSize > 1)
				{
					cout<<"entrei no >1"<<endl;

					dataMan.getBusStops()->at(i).eraseStudentInStop(j);
					cout<<"size agr "<<studentSize<<endl;
					fflush(stdout);
				}
				else
				{
					cout<<"entrei"<<endl;
					fflush(stdout);
					dataMan.eraseBusStop(i);
					cout<<"busStopSize agr "<<dataMan.getBusStops()->size()<<endl;
					fflush(stdout);
				}

			}
		}
	}

	for(unsigned int i=0; i<dataMan.getStudents().size(); i++)
		{
			if(dataMan.getStudents().at(i).getName() == name)
			{
				dataMan.eraseStudent(i);
				break;
			}
		}
}
void addStudent()
{
	Student s = Student("", 0);
	int choice;
	string name;
	int age;
	bool found = false;

	cout << "Student's Name" << endl;
	cin >> name;
    while(!hasNumber(name))
    {
        cout << "Invalid name, try again: "<< endl;
        cin>>name;
    }
	cout << "Student's age" << endl;
	cin >> age;
	while(cin.fail())
	{
		cout << "Invalid age, try again: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> age;
	}
	cout<<"What's the best busStop?"<<endl;

	for (unsigned int i = 0; i < dataMan.getAllBusStops()->size(); i++)
	{
		cout << i << ". " << dataMan.getAllBusStops()->at(i).getAddress() << endl;
	}

	cout << dataMan.getAllBusStops()->size() << ". Exit" << endl;
	choice = Nav(0, dataMan.getAllBusStops()->size());

	if (choice == dataMan.getAllBusStops()->size())
	{
		main_menu();
	}
	s.setAge(age);
	s.setName(name);
	dataMan.addStudent(s);
	for(unsigned int i=0;i<dataMan.getBusStops()->size(); i++)
	{
		if(dataMan.getBusStops()->at(i).getNode()->getInfo().getID() == dataMan.getAllBusStops()->at(choice).getNode()->getInfo().getID())
		{
			dataMan.increaseStudent(&s,i);
			found = true;
			break;  
		}
			

	}
	if(!found)
	{
		cout<< "\nHere"<< endl;
		dataMan.getAllBusStops()->at(choice).addStudentInStop(&s);
		cout << dataMan.getAllBusStops()->at(choice).getStudentsInStop().size()<<endl;
		dataMan.addBusStop(dataMan.getAllBusStops()->at(choice));

	}
	
/*	for(int i = 0; i < dataMan.getBusStops()->size(); i++){
		cout <<i<< ". "<<dataMan.getBusStops()->at(i).getStudentsInStop().size()<< endl;
	}*/
}

void addVehicle()
{
	int id,capacity;

	cout << "Bus ID" << endl;
	cin >> id;
	while(cin.fail())
	{
		cout << "Invalid ID, try again: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> id;
	}
	cout << "Bus capacity" << endl;
	cin >> capacity;
	while(cin.fail())
	{
		cout << "Invalid capacity, try again: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> capacity;
	}


Bus bus(id,1,capacity,0);
dataMan.addBusToGarage(bus);

}

void showVehicles()
{
	int choice;
	for(unsigned int i=0; i<dataMan.getGarage().getBuses().size(); i++)
	{
		cout << i << ". " << dataMan.getGarage().getBuses().at(i).getBusId() << endl;
	}

	cout << dataMan.getGarage().getBuses().size() << ". Exit" << endl;
	choice = Nav(0, dataMan.getGarage().getBuses().size());

	if (choice == dataMan.getGarage().getBuses().size())
	{
		main_menu();
	}

	dataMan.getGarage().getBuses().at(choice).getInfo();

}

void removeVehicle()
{
	int id;
	cout<<"Vehicle ID"<<endl;
	cin>>id;

	for(unsigned int i=0; i<dataMan.getGarage().getBuses().size(); i++)
	{
		if(dataMan.getGarage().getBuses().at(i).getBusId() == id)
		{
			dataMan.eraseBus(i);
			break;
		}
	}
}

void vehicle_menu()
{
	int choice;

	cout << "----------------------" << endl;
	cout << "|      VEHICLES       |" << endl;
	cout << "----------------------" << endl << endl;
	cout << "0. Add Vehicle" << endl;
	cout << "1. Remove Vehicles" << endl;
	cout << "2. show all Vehicles" << endl;
	cout << "3. Exit" << endl;

	switch (Nav(0, 3))
	{
	case 0:
		addVehicle();
		break;
	case 1:
		removeVehicle();
		break;
	case 2:
		showVehicles();
		break;
	case 3:
		main_menu();
		break;
	default:
		break;
	}

	main_menu();
}

void student_menu()
{
	cout << "----------------------" << endl;
	cout << "|      STUDENTS       |" << endl;
	cout << "----------------------" << endl << endl;
	cout << "0. Add Student" << endl;
	cout << "1. Remove Student" << endl;
	cout << "2. Show students" << endl;
	cout << "3. Exit" << endl;

	switch (Nav(0, 3))
	{
	case 0:
		addStudent();
		break;
	case 1:
		removeStudent();
		break;
	case 2:
		showStudents();
		break;
	case 3:
		main_menu();
		break;
	default:
		break;
	}
	main_menu();
}

bool isInPath(vector<Node> path, int ID1, int ID2){
	for(unsigned int i = 0; i < path.size()-1; i++){
		if(path.at(i).getID() == ID1 && path.at(i+1).getID() == ID2) return true;
	}
	return false;
}

void drawResult(vector<Node> path){
	GraphViewer gv = GraphViewer(1000,1000,false);
		gv.createWindow(1000,1000);

		for(unsigned int i = 0; i < dataMan.graph.getNumVertex(); i++){
			int idNo = dataMan.graph.getVertexSet().at(i)->getInfo().getID();
			int x = dataMan.graph.getVertexSet().at(i)->getInfo().getX();
			int y = dataMan.graph.getVertexSet().at(i)->getInfo().getY();
			gv.addNode(idNo, x, y);
		}

		for(unsigned int i = 0; i < path.size(); i++){
			int idNo = path.at(i).getID();
			gv.setVertexColor(idNo,BLUE);
		}

		int idA = 0;

				for(int i = 0; i < dataMan.graph.getNumVertex(); i++){
					int idNo1 = dataMan.graph.getVertexSet().at(i)->getInfo().getID();

					vector<Edge<Node> > adj = dataMan.graph.getVertexSet().at(i)->getAdj();

					for(unsigned int j = 0; j < adj.size(); j++){
						int idNo2 = adj.at(j).getDst().getInfo().getID();
						gv.addEdge(idA, idNo1, idNo2, EdgeType::DIRECTED);
						if(isInPath(path,idNo1,idNo2)){
							gv.setEdgeColor(idA,ORANGE);
						}
						idA++;
					}
				}

		gv.rearrange();

		char a;
		cin >> a;

		gv.closeWindow();
}

void drawMultiPaths(vector<vector<Node>> path){
	vector<string> colors = {"ORANGE", "RED", "GREEN", "CYAN", "YELLOW", "MAGENTA", "PINK", "WHITE", "GRAY"};

	int minX = dataMan.graph.getVertexSet().at(0)->getInfo().getX();
	int minY = dataMan.graph.getVertexSet().at(0)->getInfo().getY();

	for(unsigned int i = 0; i < dataMan.graph.getNumVertex(); i++){
		int x = dataMan.graph.getVertexSet().at(i)->getInfo().getX();
		int y = dataMan.graph.getVertexSet().at(i)->getInfo().getY();

		if(x < minX) minX = x;
		if(y < minY) minY = y;
	}

	GraphViewer gv = GraphViewer(1000,1000,false);
	gv.createWindow(1000,1000);

	for(unsigned int i = 0; i < dataMan.graph.getNumVertex(); i++){
		int idNo = dataMan.graph.getVertexSet().at(i)->getInfo().getID();
		int x = dataMan.graph.getVertexSet().at(i)->getInfo().getX() - minX;
		int y = minY - dataMan.graph.getVertexSet().at(i)->getInfo().getY();
		gv.addNode(idNo, x, y);
	}

	for(int i = 0; i < path.size(); i++){
		vector<Node> subPath = path.at(i);

		for(unsigned int j = 0; j < subPath.size(); j++){
			int idNo = subPath.at(j).getID();
			gv.setVertexColor(idNo,MAGENTA);
		}

		int idA = 0;

		for(int j = 0; j < dataMan.graph.getNumVertex(); j++){
			int idNo1 = dataMan.graph.getVertexSet().at(j)->getInfo().getID();

			vector<Edge<Node> > adj = dataMan.graph.getVertexSet().at(j)->getAdj();

			for(unsigned int k = 0; k < adj.size(); k++){
				int idNo2 = adj.at(k).getDst().getInfo().getID();
				gv.addEdge(idA, idNo1, idNo2, EdgeType::DIRECTED);
				if(isInPath(subPath,idNo1,idNo2)){
					gv.setEdgeThickness(idA,1.5);
					gv.setEdgeColor(idA,colors.at(i%9));
				}
				idA++;
			}
		}
	}
	gv.rearrange();

	char a;
	cin >> a;

	gv.closeWindow();
}

void schoolChoice_menu()
{
	int choice;
	cout << "----------------------" << endl;
	cout << "|    Which School?   |" << endl;
	cout << "----------------------" << endl << endl;

	for (unsigned int i = 0; i < dataMan.getSchools().size(); i++)
	{
		cout << i << ". " << dataMan.getSchools().at(i).getName() << endl;
	}

	cout << dataMan.getSchools().size() << ". Exit" << endl;
	choice = Nav(0, dataMan.getSchools().size());

	if (choice == dataMan.getSchools().size())
	{
		main_menu();
	}

	dataMan.setSchool(dataMan.getSchools().at(choice));


		vector<vector<Node>> p = dataMan.getPath();

		for(unsigned int i = 0; i < p.size(); i++){
			for(unsigned int j = 0; j < p.at(i).size(); j++){
				cout << "Bus "<< i<< " Node: "<< p.at(i).at(j).getID() << endl;
			}
		}

		if(p.size() == 0)
		{
			cout<<"Try Again"<<endl;
			main_menu();
		}

		//drawResult(p.at(0));
		drawMultiPaths(p);

		main_menu();
}




void drawGraph()
{
	GraphViewer gv = GraphViewer(1000, 1000, false);
	gv.createWindow(1000, 1000);

	for (unsigned int i = 0; i < dataMan.graph.getNumVertex(); i++)
	{
		int idNo = dataMan.graph.getVertexSet().at(i)->getInfo().getID();
		int x = dataMan.graph.getVertexSet().at(i)->getInfo().getX();
		int y = dataMan.graph.getVertexSet().at(i)->getInfo().getY();
		gv.addNode(idNo, x, y);
	}

	int idA = 0;

	for (int i = 0; i < dataMan.graph.getNumVertex(); i++)
	{
		int idNo1 = dataMan.graph.getVertexSet().at(i)->getInfo().getID();

		vector<Edge<Node>> adj = dataMan.graph.getVertexSet().at(i)->getAdj();

		for (unsigned int j = 0; j < adj.size(); j++)
		{
			int idNo2 = adj.at(j).getDst().getInfo().getID();
			gv.addEdge(idA, idNo1, idNo2, EdgeType::DIRECTED);
			idA++;
		}
	}

	gv.rearrange();

	char a;
	cin >> a;

	gv.closeWindow();
}

void city_menu()
{
	int choice;
	cout << "----------------------" << endl;
	cout << "|       CITIES       |" << endl;
	cout << "----------------------" << endl<<endl;

	for (unsigned int i = 0; i < cityVec.size(); i++)
	{
		cout << i << ". " << cityVec.at(i)<<endl;
	}

	cout << cityVec.size() << ". Exit" << endl;
	choice = Nav(0, cityVec.size());

	if (choice == cityVec.size())
	{
		return;
	}

	string nodeFile ="T05/" + cityVec.at(choice) + "/T05_nodes_X_Y_"+ cityVec.at(choice) + ".txt";
	string edgeFile = "T05/" + cityVec.at(choice) + "/T05_edges_" + cityVec.at(choice) + ".txt";
	string tagFile = "T05/" + cityVec.at(choice) + "/T05_tags_" + cityVec.at(choice) + ".txt";
	//cout<<nodeFile<<" "<< edgeFile<<" "<<tagFile<<" "<<endl;

	dataMan.readNodeFile(nodeFile);
	dataMan.readEdgeFile(edgeFile);

	dataMan.loadPointsOfInterest(tagFile);


	main_menu();
}

void main_menu()
{
	cout << "----------------------" << endl;
	cout << "|      MAIN MENU     |" << endl;
	cout << "----------------------" << endl;
	cout << "0. Show path" << endl;
	cout << "1. Vehicle Menu" << endl;
	cout << "2. Student Menu" << endl;
	cout << "3. Exit" << endl;

	switch (Nav(0, 3))
	{
	case 0:
		schoolChoice_menu();
		break;
	case 1:
		vehicle_menu();
		break;
	case 2:
		student_menu();
		break;
	case 3:
		return;
	default:
		break;
	}
}

int main()
{
	city_menu();
	return 0;
}
