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

void vehicle_menu()
{
	int choice;

	cout << "----------------------" << endl;
	cout << "|      VEHICLES       |" << endl;
	cout << "----------------------" << endl << endl;
	cout << "0. Remove Vehicles" << endl;
	cout << "1. Add Vehicle" << endl;
	cout << "2. Exit" << endl;

	switch (Nav(0, 2))
	{
	case 0:

		break;
	case 1:

		break;
	case 2:
		main_menu();
		break;
	default:
		break;
	}
}

void student_menu()
{
	int choice;
	string name;
	int age;


	cout << "----------------------" << endl;
	cout << "|      STUDENTS       |" << endl;
	cout << "----------------------" << endl << endl;
	cout << "0. Remove Student" << endl;
	cout << "1. Add Student" << endl;
	cout << "2. Exit" << endl;

	Student s = Student("", 0);
	switch (Nav(0, 2))
	{
	case 0:

		break;
	case 1:
		cout << "Digite o nome" << endl;
		cin >> name;
		cout << "Digite a idade" << endl;
		cin >> age;
		s.setAge(age);
		s.setName(name);
		dataMan.addStudent(s);
		break;
	case 2:
		main_menu();
		break;
	default:
		break;
	}
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

}

bool isInPath(vector<Node> path, int ID1, int ID2){
	for(int i = 0; i < path.size()-1; i++){
		if(path.at(i).getID() == ID1 && path.at(i+1).getID() == ID2) return true;
	}
	return false;
}



void drawResult(vector<Node> path){
	GraphViewer gv = GraphViewer(1000,1000,false);
		gv.createWindow(1000,1000);

		for(int i = 0; i < dataMan.graph.getNumVertex(); i++){
			int idNo = dataMan.graph.getVertexSet().at(i)->getInfo().getID();
			int x = dataMan.graph.getVertexSet().at(i)->getInfo().getX();
			int y = dataMan.graph.getVertexSet().at(i)->getInfo().getY();
			gv.addNode(idNo, x, y);
		}

		for(int i = 0; i < path.size(); i++){
			int idNo = path.at(i).getID();
			//int x = path.at(i).getX();
			//int y = path.at(i).getY();
			gv.setVertexColor(idNo,BLUE);
		}

		int idA = 0;

				for(int i = 0; i < dataMan.graph.getNumVertex(); i++){
					int idNo1 = dataMan.graph.getVertexSet().at(i)->getInfo().getID();

					vector<Edge<Node> > adj = dataMan.graph.getVertexSet().at(i)->getAdj();

					for(int j = 0; j < adj.size(); j++){
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
		main_menu();
	}

	string nodeFile ="T05/" + cityVec.at(choice) + "/T05_nodes_X_Y_"+ cityVec.at(choice) + ".txt";
	string edgeFile = "T05/" + cityVec.at(choice) + "/T05_edges_" + cityVec.at(choice) + ".txt";
	string tagFile = "T05/" + cityVec.at(choice) + "/T05_tags_" + cityVec.at(choice) + ".txt";
	cout<<nodeFile<<" "<< edgeFile<<" "<<tagFile<<" "<<endl;

	dataMan.readNodeFile(nodeFile);
	dataMan.readEdgeFile(edgeFile);

	dataMan.loadPointsOfInterest(tagFile);

	dataMan.getPath(dataMan.getSchools().at(0).getNode()->getInfo(),dataMan.getSchools().at(1).getNode()->getInfo());


	//drawResult(path);

	schoolChoice_menu();
}

void main_menu()
{
	cout << "----------------------" << endl;
	cout << "|      MAIN MENU     |" << endl;
	cout << "----------------------" << endl;
	cout << "0. Choose a city" << endl;
	cout << "1. Vehicle Menu" << endl;
	cout << "2. Student Menu" << endl;
	cout << "3. Exit" << endl;

	switch (Nav(0, 3))
	{
	case 0:
		city_menu();
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
	main_menu();
	return 0;
}
