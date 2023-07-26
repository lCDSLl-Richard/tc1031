// =================================================================
//
// File: main.cpp
// Author: Ricardo Fernandez
// Date: 01/09/22
//
// =================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		cout << "Invalid arguments" << endl;
		return -1;
	}

	ifstream inFile;
	ofstream outFile;

	inFile.open(argv[1]);
	outFile.open(argv[2]);

	int size = 0;
	inFile >> size;

	vector<int> vec(size);

	for (int i = 0; i < size; i++)
	{
		inFile >> vec[i];
	}
	vector<int> vec2 = vec;
	vector<int> vec3 = vec;

	outFile << bubbleSort(vec) << " " << selectionSort(vec2) << " " << insertionSort(vec3) << "\n\n";

	int nSearch = 0;
	inFile >> nSearch;

	int obj;
	int *res;

	for (int i = 0; i < nSearch; i++)
	{
		inFile >> obj;
		res = sequentialSearch(vec, obj);
		outFile << res[0] << " " << res[1] << " ";
		res = binarySearch(vec, obj);
		outFile << res[1] << endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}
