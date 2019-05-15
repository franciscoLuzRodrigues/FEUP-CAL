


using namespace std;

int readNodeFile(string fileName, Graph<Node> &graph)
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

Node getNode(int id, Graph<Node> &graph){
	for (auto v : graph.getVertexSet()){
		if (v->getInfo().getId() == id)
			return (v->getInfo());
	}
}

int readEdgeFile(string fileName,Graph<Node> &graph){
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
		Node scr = getNode(edgeSrc,graph);
		Node dst = getNode(edgeDst,graph);
		graph.addEdge(scr, dst,scr.getDistance(dst));
	}
	return 0;
}

int readTagFile(string fileName, vector<School*> &sVec, vector<BusStop*> &bVec, Graph<Node> &graph){
	ifstream poiFile;
	poiFile.open(fileName);
	string line, sName, BSaddress;
	int nodeID, morningTime, afternoonTime;

	if (!poiFile.is_open())
	{
		cerr << "Input file not found, try again!" << endl;
		return 1;
	}

		getline(poiFile,line);

 	while (!poiFile.eof())
	{
		getline(poiFile, line);

		if (line == "house")
		{
			break;
		}


		nodeID = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') +2);
		sName =line.substr(0, line.find(','));
		line.erase(0, line.find(',') + 2);
		morningTime = stoi(line.substr(0,line.find(',')));
		line.erase(0, line.find(',') + 2);
		afternoonTime = stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		School newSchool = School(sName,morningTime,afternoonTime,&getNode(nodeID, graph)); 
		sVec.push_back(&newSchool);
		//addSchool(&newSchool);
		//cout << sVec.at(0)->getName() << " " << morningTime << " " << afternoonTime << " "<< getNode(nodeID, graph).getId() << endl<<endl;

	}

	while (!poiFile.eof())
	{
		getline(poiFile, line);
		nodeID = stoi(line.substr(0, line.find(',')));
		cout<<" "<< stoi(line.substr(0, line.find(',')));
		line.erase(0, line.find(',') + 2);
		BSaddress = line.substr(0, line.find(','));
		cout << " " << line.substr(0, line.find(','));
		BusStop newBS = BusStop(&getNode(nodeID, graph),BSaddress);
		bVec.push_back(&newBS);
		//cout << " " << getNode(nodeID, graph).getId() <<" "<<BSaddress<< endl;
	}
	return 0;
}


