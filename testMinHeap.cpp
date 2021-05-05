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
	MinHeap h(3);
	cout << "where is this line" << endl;
	h.insert();
	h.printRoot();
	h.insert();
	h.printRoot();
	h.insert();
	h.printRoot();
	h.insert();
	h.printRoot();
	h.insert();
	h.printRoot();
	h.insert();
	h.printRoot();

    h.write(argv[1]);
    
	return 0;
}


