//hashTable.cpp
//Author: Benjamin Fogiel

#include "hashTable.h"
#include "minHeap.h"
#include <iostream>
#include<cstring>
#include<iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <random>

using namespace std;

HashTable::HashTable(int size) 
{ 
    tableLen = nextPrime(size*2); 
    numElm = 0; 
    cap = size; 
    Node n = Node();
    n.str = "";
    n.frequency = -1;
    n.heapElm = 0;
    htarr.resize(tableLen, n);
    MinHeap* heap = new MinHeap(cap); 
    h = heap;
}

void HashTable::insertHash(string s)
{

    int i;
    i = search(s);

    // if elm already exists
    if (htarr.at(i).heapElm != 0)
    {
        htarr.at(i).heapElm->frequency = htarr.at(i).heapElm->frequency + 1;
        return;
    }

    // if heap is full
    if (numElm == cap)
    {
    	deleteElm(h->getRootString());
        insertHash(s);
        return;
    }

    htarr.at(i).str = s;
    htarr.at(i).frequency = 1;
    htarr.at(i).heapElm = h->insert(&htarr.at(i));
    numElm++;
    return;
}

// deletes elm in Hash Table
void HashTable::deleteElm(string s){
    int i = search(s);
    // The heapElm pointer is the indication of if the bin is full
    htarr.at(i).heapElm = nullptr;
    numElm--;
}

int HashTable::search(string s){
    stringstream hashstr(s);
    int hash = 0;
    hashstr >> hash;
    int index = hash % tableLen;
    int counter = 1;
    while((htarr.at(index).str.compare(s) != 0) && (htarr.at(index).heapElm != 0))
    {
        index = (hash + counter*counter)%tableLen;
        counter++;
    }
    return index;
}

bool HashTable::isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

// Function to return the smallest
// prime number greater than N
int HashTable::nextPrime(int N)
{
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) 
    {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

void HashTable::writeHeap(string file) 
{ 
    h->writeMin(file);
}