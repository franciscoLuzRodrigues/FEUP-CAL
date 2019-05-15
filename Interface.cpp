#include <iostream>
#include <string>
#include <fstream>

#include "Graph.h"
#include "SchoolBus.h"
#include "FileData.h"
#include <string>

using namespace std;

vector<string> cityVec = {"Aveiro", "Braga", "Coimbra", "Ermesinde", "Fafe", "Gondomar", "Lisboa", "Maia", "Porto", "Viseu"};

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

void city_menu()
{
	int choice;
	cout << "----------------------" << endl;
	cout << "|       CYTIES       |" << endl;
	cout << "----------------------" << endl<<endl;

	for (unsigned int i = 0; i < cityVec.size(); i++)
	{
		cout << i << ". " << cityVec.at(i)<<endl;
	}

	choice = Nav(0, cityVec.size());
	string nodeFile ="T05/" + cityVec.at(choice) + "/T05_nodes_X_Y_"+ cityVec.at(choice) + ".txt";
	string edgeFile = "T05/" + cityVec.at(choice) + "/T05_edges_" + cityVec.at(choice) + ".txt";
	string tagFile = "T05/" + cityVec.at(choice) + "/T05_tags_" + cityVec.at(choice) + ".txt";
	cout<<nodeFile<<" "<< edgeFile<<" "<<tagFile<<" "<<endl;

	//readNodeFile(nodeFile);
	readFileEdge(edgeFile);
}

void main_menu()
{
	cout << "----------------------" << endl;
	cout << "|      MAIN MENU     |" << endl;
	cout << "----------------------" << endl;
	cout << "0. Choose a city" << endl;
	cout << "1. Exit" << endl;

	switch (Nav(0, 1))
	{
	case 0:
		city_menu();
		break;
	case 1:
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
