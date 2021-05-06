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
	h.insert("sdf");
	h.printRoot();
	h.insert("sdff");
	h.printRoot();
	h.insert("sdfsdf");
	h.printRoot();
	h.insert("sdsdff");
	h.printRoot();
	h.insert("sdfff");
	h.printRoot();
	h.insert("sddfdff");
	h.printRoot();
    
	return 0;
}


