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

using namespace std;

int main(int argc, char **argv)
{
	HashTable h(5);
	ifstream myfile;
	myfile.open("testIn.txt");
	string line;
	while(getline(myfile,line))
	{	
		stringstream linestream(line);
		string value;
		while(getline(linestream,value,','))
		{
			h.insert(value);	
		}
	}
	myfile.close();
	ofstream writeFile;
	writeFile.open("textOut.txt", fstream::app);
	h.writeHeap(writeFile);
	writeFile.close();
	return 0;
}
