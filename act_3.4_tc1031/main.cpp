// =================================================================
//
// File: main.cpp
// Author: Ricardo Fernandez
// Date: 2022-11-18
//
// =================================================================
#include <iostream>
#include <fstream>
#include "heap.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{

	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	int size, number;
	infile >> size;
	Heap<int> heap(size);

	for (int i = 0; i < size; i++)
	{
		infile >> number;
		heap.add(number);
	}

	int comps = 0;
	int acum = 0;

	while (heap.getCount() > 1)
	{
		comps = heap.remove() + heap.remove();
		heap.add(comps);
		acum += comps - 1;
	}
	outfile << acum << endl;
	return 0;
}
