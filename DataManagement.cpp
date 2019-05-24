#include "DataManagement.h"

using namespace std;


void DataManager::addStudent(Student student) {
	
	students.push_back(student);
}

void DataManager::addSchool(School school) {

	schools.push_back(school);
}
void DataManager::addBusStop(BusStop busStop)
{
	busStops.push_back(busStop);
}

int DataManager::readNodeFile(string fileName)
{
	ifstream nodeFile;
	string nodeInfo;
	int nodeId;
	float nodeX, nodeY;

	nodeFile.open(fileName);
	if (!nodeFile.is_open())
	{
		cerr << "Input file not found, try again!" << endl;
		return 1;
	}

	getline(nodeFile, nodeInfo);

	while (!nodeFile.eof()) {
		getline(nodeFile, nodeInfo);
		nodeId = stoi(nodeInfo.substr(1, nodeInfo.find(',') - 1));
		nodeInfo.erase(0, nodeInfo.find(',') + 2);
		nodeX = stof(nodeInfo.substr(0, nodeInfo.find(',')));
		nodeInfo.erase(0, nodeInfo.find(',') + 2);
		nodeY = stof(nodeInfo.substr(0, nodeInfo.find(')')));

		Node node = Node(nodeId, nodeX, nodeY);
		graph.addVertex(node);
	}
	return 0;
}

Node getNode(int id, Graph<Node> &graph) {
	Node node(-1,-1,-1);
	for (auto v : graph.getVertexSet()) {
		if (v->getInfo().getID() == id)
			return (v->getInfo());
	}

	return node;
}

int DataManager::readEdgeFile(string fileName) {
	ifstream edgeFile;
	int edgeSrc, edgeDst;
	edgeFile.open(fileName);
	if (!edgeFile.is_open())
	{
		cerr << "Input file not found, try again!" << endl;
		return 1;
	}

	string edgeInfo;
	getline(edgeFile, edgeInfo);

	while (!edgeFile.eof()) {

		getline(edgeFile, edgeInfo);
		edgeSrc = stoi(edgeInfo.substr(1, edgeInfo.find(',') - 1));
		edgeInfo.erase(0, edgeInfo.find(',') + 2);
		edgeDst = stoi(edgeInfo.substr(0, edgeInfo.find(')')));
		Node scr = getNode(edgeSrc, graph);
		Node dst = getNode(edgeDst, graph);
		graph.addEdge(scr, dst, scr.getDistance(dst));
	}
	return 0;
}

int DataManager::loadPointsOfInterest(string fileName) {
	ifstream poiFile;
	poiFile.open(fileName);
	string line, sName, BSaddress;
	int nodeID, morningTime, afternoonTime;

	if (!poiFile.is_open())
	{
		cerr << "Input file not found, try again!" << endl;
		return 1;
	}

	getline(poiFile, line);

	while (!poiFile.eof())
	{
		getline(poiFile, line);

		if (line == "house")
		{
			break;
		}


		nodeID = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		sName = line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 2);
		morningTime = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		afternoonTime = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);


		for(unsigned int i=0;i<graph.getVertexSet().size(); i++)
		{
			if(graph.getVertexSet().at(i)->getInfo().getID() == nodeID)
			{
				School newSchool = School(sName, morningTime, afternoonTime, graph.getVertexSet().at(i));
				addSchool(newSchool);
				break;
			}
		}

	}

	while (!poiFile.eof())
	{
		getline(poiFile, line);
		nodeID = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		BSaddress = line.substr(0, line.find(','));

		for(unsigned int i=0;i<graph.getVertexSet().size(); i++)
		{
			if(graph.getVertexSet().at(i)->getInfo().getID() == nodeID)
			{
				BusStop newBS = BusStop(graph.getVertexSet().at(i), BSaddress);
				addBusStop(newBS);
				break;
			}

		}

	}
	return 0;
}

void DataManager::updateQ(){
	while(!nearestV.empty())
	{
		nearestV.extractMin();
	}

	for(unsigned int i = 0; i < busStops.size(); i++){
				Vertex<Node>*v = graph.findVertex(busStops.at(i).getNode()->getInfo());
				nearestV.insert(v);

		}
}

void DataManager::eraseNodeWithID(int id){
	for(unsigned int i = 0; i < busStops.size(); i++){
		if(busStops.at(i).getNode()->getInfo().getID() == id){
			busStops.erase(busStops.begin()+i);
			return;
		}
	}
}




vector<Node> DataManager::getPathNodes(Node garage, Node school){
	Vertex<Node> nearV(*new Node(-1,-1,-1));
	vector<Node> path;

    graph.dijkstraShortestPath(garage);
    updateQ();

    nearV = *nearestV.extractMin();
	path.push_back(garage);
	path.push_back(nearV.getInfo());
	unsigned int BSsize = busStops.size()+1;
	while(path.size() != BSsize){
		eraseNodeWithID(nearV.getInfo().getID());
		graph.dijkstraShortestPath(nearV.getInfo());
		updateQ();
		nearV = *nearestV.extractMin();
		path.push_back(nearV.getInfo());
	}

	path.push_back(school);

	return path;

}


vector<Node> DataManager::getPath(Node garage, Node school){

	vector<Node> temp, pathNode, finalPath;

	pathNode = getPathNodes(garage, school);
	for(unsigned int i = 0 ; i < pathNode.size(); i++){
		cout << "ID: "<< pathNode.at(i).getID()<<endl;
	}

	finalPath.push_back(garage);
	for(unsigned int j = 0; j < pathNode.size() -1; j++)
	{
		graph.dijkstraShortestPath(pathNode.at(j));
		temp = graph.getPath(pathNode.at(j), pathNode.at(j+1));

		for(unsigned int i = 1;i < temp.size(); i++){
			finalPath.push_back(temp.at(i));
			cout<<"temp "<<temp.at(i).getID();
		}
		cout<<endl;
	}

	return finalPath;


}

int DataManager::getPathDistance(vector<Node> path){

	Vertex<Node> *v = graph.findVertex(path.at(path.size()-1));
	return v->getDist();
}
