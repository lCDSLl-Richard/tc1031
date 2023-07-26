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
#include "bubbleSort.h"
#include "Boat.h"

using namespace std;

string dateHandler(string date)
{
	switch (stoi(date))
	{
	case 1:
		return "jan";
		break;
	case 2:
		return "feb";
		break;
	case 3:
		return "mar";
		break;
	case 4:
		return "apr";
		break;
	case 5:
		return "may";
		break;
	case 6:
		return "jun";
		break;
	case 7:
		return "jul";
		break;
	case 8:
		return "aug";
		break;
	case 9:
		return "sep";
		break;
	case 10:
		return "oct";
		break;
	case 11:
		return "nov";
		break;
	case 12:
		return "dec";
		break;
	}
	return "undefined";
}

string dateHandler(int date)
{
	switch (date)
	{
	case 1:
		return "jan";
		break;
	case 2:
		return "feb";
		break;
	case 3:
		return "mar";
		break;
	case 4:
		return "apr";
		break;
	case 5:
		return "may";
		break;
	case 6:
		return "jun";
		break;
	case 7:
		return "jul";
		break;
	case 8:
		return "aug";
		break;
	case 9:
		return "sep";
		break;
	case 10:
		return "oct";
		break;
	case 11:
		return "nov";
		break;
	case 12:
		return "dec";
		break;
	}

	return "undefined";
}

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		cout << "Invalid usage" << endl;
		return -1;
	}

	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);
	if (inFile.fail())
		return -1;
	if (outFile.fail())
		return -1;

	int numBoats = 0;
	string prefix = "";
	inFile >> numBoats >> prefix;

	vector<Boat *> boats;

	string date, hour, entry, UBI;

	for (int i = 0; i < numBoats; i++)
	{
		inFile >> date >> hour >> entry >> UBI;
		if (UBI.substr(0, 3) == prefix)
			boats.push_back(new Boat(date, hour, entry, UBI));
	}

	bubbleSort(boats);

	vector<Boat *> m;
	vector<Boat *> r;

	for (int i = 1; i < 13; i++)
	{
		for (Boat *b : boats)
		{
			if (stoi(b->date.substr(3, 2)) == i)
			{
				if (b->entry == "M")
				{
					m.push_back(b);
				}
				else
				{
					r.push_back(b);
				}
			}

			if (stoi(b->date.substr(3, 2)) > i)
				break;
		}
		if (m.size() > 0 || r.size() > 0)
			outFile << dateHandler(i) << endl;

		if (m.size() != 0)
		{
			outFile << "M " << m.size() << ": ";
			for (Boat *b : m)
			{
				outFile << b->UBI << " ";
			}
			outFile << endl;
		}

		if (r.size() != 0)
		{
			outFile << "R " << r.size() << ": ";
			for (Boat *b : r)
			{
				outFile << b->UBI << " ";
			}
			outFile << endl;
		}
		r.clear();
		m.clear();
	}

	return 0;
}