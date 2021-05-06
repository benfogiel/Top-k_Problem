// main.cpp
// Author: Benjamin Fogiel
#include<iostream>
#include "hashTable.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include "openssl/sha.h"

int main(int argc, char **argv)
{
	// Initialize the HashTable Object
	HashTable h(stoi(argv[3]));

	// Construct the heap
	std::string line;
	std::string fn = argv[1];
	std::fstream f;
	f.open(fn.c_str(), ios::in);
	if(f.is_open())
	{
		while(getline(f,line))
		{
		std::stringstream linestream(line);
		std::string value;
		while(getline(linestream,value,','))
		{
			h.insert(value);
		}
		}
	}

	// Write the output file
	std::string file(argv[2]);
	h.writeHeap(file);

	return 0;
}