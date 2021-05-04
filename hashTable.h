//hashTable.h
// Author: Benjamin Fogiel

#include<iostream>
#include<cstring>
#include<climits>
#include<fstream>
#include "minHeap.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

bool isPrime(int n);
int nextPrime(int N);
string sha256(const string str);

// A class for Min Heap
class HashTable
{
public:
    // Constructor
    HashTable(int size) { tableLen = nextPrime(size); numElm = 0; cap = size; }

    // Destructor
    ~HashTable();

    // Search for element returns index or -1 if not found
    int search(string s);

    // Insert
    void insert(string s);

    // Delete Element
    void deleteElm(string s);

    //print heap ascending order
    void writeHeap(ofstream& file);

private:
    int numElm;
    int cap;
    int tableLen = nextPrime(cap);
    MinHeap::Node** htarr = new MinHeap::Node*[tableLen];
    MinHeap h = MinHeap(cap);
};

#endif
