// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Boat.h"
#include "bubbleSort.h"

using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		cout << "Invalid usage" << endl;
		return -1;
	}

	ifstream inFile;
	ofstream outFile;

	inFile.open(argv[1]);
	if (inFile.fail())
		return -1;

	outFile.open(argv[2]);
	if (outFile.fail())
		return -1;

	int numBoats = 0;
	string prefix = "";
	inFile >> numBoats >> prefix;

	vector<Boat *> boats(numBoats);

	string date, hour, entry, UBI;

	for (int i = 0; i < numBoats; i++)
	{
		inFile >> date >> hour >> entry >> UBI;
		boats[i] = new Boat(date, hour, entry, UBI);
	}

	vector<Boat *> filteredVector;

	for (int i = 0; i < numBoats; i++)
	{
		if (boats[i]->UBI.substr(0, 3) == prefix)
			filteredVector.push_back(boats[i]);
	}

	bubbleSort(filteredVector);

	for (int i = 0; i < filteredVector.size(); i++)
	{
		outFile << *(filteredVector[i]) << endl;
	}

	inFile.close();
	outFile.close();
}
