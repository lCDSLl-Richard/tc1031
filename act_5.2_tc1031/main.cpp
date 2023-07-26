// =================================================================
//
// File: main.cpp
// Author: Ricardo Fernandes
// Date: 2022-11-24
//
// =================================================================
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{

	ifstream inFile(argv[1]);
	ofstream outFile(argv[2]);

	map<string, int> salaries;

	int numSalaries, numJobs;

	inFile >> numSalaries >> numJobs;

	for (int i = 0; i < numSalaries; i++)
	{
		string job;
		int salary;
		inFile >> job >> salary;
		salaries[job] = salary;
	}

	int acum = 0;
	for (int i = 0; i < numJobs; i++)
	{
		while (true)
		{
			string job;
			inFile >> job;
			if (job == ".")
				break;
			acum += salaries[job];
		}
		outFile << acum << endl;
		acum = 0;
	}

	return 0;
}
