#include <iostream>
#include <string>

#include "Graph.h"
#include "SchoolBus.h"
using namespace std;


Graph<int> createTestGraph()
{
	Graph<int> myGraph;

	for(int i = 1; i < 8; i++)
		myGraph.addVertex(i);

	myGraph.addEdge(1, 2, 2);
	myGraph.addEdge(1, 4, 7);
	myGraph.addEdge(2, 4, 3);
	myGraph.addEdge(2, 5, 5);
	myGraph.addEdge(3, 1, 2);
	myGraph.addEdge(3, 6, 5);
	myGraph.addEdge(4, 3, 1);
	myGraph.addEdge(4, 5, 1);
	myGraph.addEdge(4, 7, 4);
	myGraph.addEdge(5, 7, 2);
	myGraph.addEdge(6, 4, 3);
	myGraph.addEdge(7, 6, 4);

	// to force undirected graph...
	myGraph.addEdge(2, 1, 2);
	myGraph.addEdge(4, 1, 7);
	myGraph.addEdge(4, 2, 3);
	myGraph.addEdge(5, 2, 5);
	myGraph.addEdge(1, 3, 2);
	myGraph.addEdge(6, 3, 5);
	myGraph.addEdge(3, 4, 1);
	myGraph.addEdge(5, 4, 1);
	myGraph.addEdge(7, 4, 4);
	myGraph.addEdge(7, 5, 2);
	myGraph.addEdge(4, 6, 3);
	myGraph.addEdge(6, 7, 4);

	return myGraph;
}

int main()
{
	Graph<int> graph = createTestGraph();

	return 0;
}
