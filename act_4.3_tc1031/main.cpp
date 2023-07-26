// =================================================================
//
// File: main.cpp
// Author: Ricardo Fernandez
// Date: 2022-11-23
//
// =================================================================
#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);

	int numEdges;
	string cityFrom;
	string cityTo;

	inFile >> numEdges;

	Graph<string> graph;
	for (int i = 0; i < numEdges; i++)
	{
		inFile >> cityFrom >> cityTo;
		graph.addEdge(cityFrom, cityTo);
	}

	int numQueries, depth;
	string startCity;
	inFile >> numQueries;
	for (int i = 0; i < numQueries; i++)
	{
		inFile >> startCity >> depth;
		set<string> neighbors = graph.getNeighbors(startCity);
		neighbors.insert(startCity);
		int currentDepth = 1;

		while (currentDepth < depth)
		{
			set<string> newNeighbors;
			for (string neighbor : neighbors)
			{
				set<string> temp = graph.getNeighbors(neighbor);
				newNeighbors.insert(temp.begin(), temp.end());
			}
			neighbors.insert(newNeighbors.begin(), newNeighbors.end());
			currentDepth++;
		}

		outFile << "Case " << i + 1 << ": " << graph.numVertices() - neighbors.size()
						<< " ports not reachable from port " << startCity << " with MNP = "
						<< depth << "." << endl;
	}

	return 0;
}
