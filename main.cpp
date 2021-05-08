// main.cpp
// Author: Benjamin Fogiel
#include<iostream>
#include "hashTable.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	// Initialize the HashTable Object
	stringstream input(argv[3]);
    int in = 0;
    input >> in;
    cout << in;
    HashTable h(in);

	// Construct the heap
	string line;
	string fn = argv[1];
	fstream f;
	f.open(fn.c_str(), ios::in);
	if(f.is_open())
	{
		while(getline(f,line))
		{
		stringstream linestream(line);
		string value;
		while(getline(linestream,value,','))
		{
			h.insertHash(value);
			cout << value << endl;
		}
		}
	}

	// Write the output file
	string file(argv[2]);
	h.writeHeap(file);

	return 0;
}