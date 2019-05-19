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

		//sVec.push_back(&newSchool);

		//cout << sVec.at(0)->getName() << " " << morningTime << " " << afternoonTime << " "<< getNode(nodeID, graph).getId() << endl<<endl;

	}

	while (!poiFile.eof())
	{
		getline(poiFile, line);
		nodeID = stoi(line.substr(0, line.find(',')));
		cout << " " << stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		BSaddress = line.substr(0, line.find(','));
		cout << " " << line.substr(0, line.find(','));

		for(unsigned int i=0;i<graph.getVertexSet().size(); i++)
		{
			if(graph.getVertexSet().at(i)->getInfo().getID() == nodeID)
			{
				BusStop newBS = BusStop(graph.getVertexSet().at(i), BSaddress);
				//bVec.push_back(&newBS);
				addBusStop(newBS);
				break;
			}

		}
		//bVec.push_back(&newBS);
		//cout << " " << getNode(nodeID, graph).getId() <<" "<<BSaddress<< endl;
	}
	return 0;
}

vector<Node> DataManager::getPath(Node garage, Node school, vector<Node> busStops){
	vector<Node> path;

	if(busStops.size() == 0){
		graph.dijkstraShortestPath(garage);
		path = graph.getPath(garage,school);
		return path;
	}

	vector<Node> test = busStops;
	Node init = garage;
	int distance = INF;
	int size = busStops.size();

	graph.dijkstraShortestPath(garage);

	while(size-- > 0){
		int index;
		for(int i = 0; i < test.size(); i++){
			test = graph.getPath(garage,busStops.at(i));
			int newDist = getPathDistance(test);
			if(newDist < distance){
				distance = newDist;
				init = busStops[i];
				index = i;
			}
		}
		path.push_back(init);
		test.erase(test.begin()+index);
	}

	return path;
}

int DataManager::getPathDistance(vector<Node> path){
	int distance = 0;

	for(int i = 0; i < path.size()-1; i++){
		auto v1 = graph.findVertex(path[i]);
		auto v2 = graph.findVertex(path[i+1]);

		Edge<Node> e1 = v1->findEdge(v2->getInfo());

		distance += e1.getWeight();
	}

	return distance;
}
