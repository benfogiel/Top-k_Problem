// main.cpp
// Author: Benjamin Fogiel
#include<iostream>
#include "minHeap.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include "openssl/sha.h"

using namespace std;

int main(int argc, char **argv)
{
	MinHeap h(10);
	cout << "where is this break" << endl;
	h.insert();
	h.insert();
	h.insert();
	h.insert();
	h.insert();
	h.insert();
	ofstream writeFile;
        writeFile.open(argv[1], fstream::app);
        h.write(writeFile);
        writeFile.close();
        h.printRoot();
	return 0;
}


