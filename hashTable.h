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

// A class for Min Heap
class HashTable
{
public:
    
    vector<Node> htarr;

    int numElm;
    int cap;
    int tableLen;
    MinHeap h = MinHeap(cap);

    bool isPrime(int n);
    int nextPrime(int N);
    // Constructor
    HashTable(int size);

    // Destructor
    //~HashTable();

    // Search for element returns index or -1 if not found
    int search(string s);

    // Insert
    void insert(string s);

    // Delete Element
    void deleteElm(string s);

    //print heap ascending order
    void writeHeap(string file);

    string sha256(const string str);
};

#endif
