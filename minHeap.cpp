//minHeap.cpp
//Author: Benjamin Fogiel

#include "minHeap.h"
#include "hashTable.h"
#include <iostream>
#include<cstring>
#include<iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include "openssl/sha.h"
#include <random>
#include<vector>

using namespace std;

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap) : capacity(cap+1)
{
    heap_size = 1;
    count = 0;
    Node n = Node();
    harr.resize(0);
    harr.push_back(n);
}

/*
//Destructor
MinHeap::~MinHeap(){
	for (int i = 0; i < capacity; i++){
		free(harr[i]);
	}
	delete harr;
}
*/
// Inserts a new key 'k'
Node* MinHeap::insert(string str)
{
    if (harr.size() == capacity)
    {
	    swapMin(str);
        return &harr.at(1);
    }
    Node n = Node();
    // First insert the new key at the end
    int i = heap_size;
    harr.push_back(n);
    harr.at(i).frequency = 1;
    harr.at(i).c = count;
    harr.at(i).str = str;
    count++;
    heap_size++;

    // Fix the min heap property if it is violated
    while (i > 1 && compare(parent(i),i))
    {
       swap(i,parent(i));
       i = parent(i);
    }
    return &harr.at(i);
}

// delete min
Node* MinHeap::deleteMin(){
	harr.at(0) = harr.at(1);       
	harr.at(1) = harr.at(heap_size - 1);
    harr.pop_back();
	heap_size--;
	MinHeapify(1);
	return harr.at(0).hashElm;
}

// Method to remove minimum element (or root) from min heap
void MinHeap::swapMin(string str)
{
    // Store the minimum value, and remove it from heap
    harr.at(1).frequency++;
    harr.at(1).c = count;
    harr.at(1).str = str;
    count++;
    if (heap_size > 2)
    	MinHeapify(1);
    return;
}


// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && !compare(l,i))
    {
    	smallest = l;
    }
    if (r < heap_size && !compare(r,smallest))
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(i, smallest);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void MinHeap::swap(int x, int y)
{

    Node n = Node();
    n = harr.at(x);
    harr.at(x) = harr.at(y);
    harr.at(y) = n;
}

// compares two nodes in the heap. Will return true if the first index (i) is greater than the second (j)
bool MinHeap::compare(int i, int j){
	if ((harr.at(i).frequency > harr.at(j).frequency) || ((harr.at(i).frequency == harr.at(j).frequency) && (harr.at(i).c < harr.at(j).c)))
		return true;
	return false;
}

void MinHeap::writeMin(string file) {
    int freq;
    ofstream writeFile;
    writeFile.open(file, ios::app);
    if (writeFile.is_open()){
       while(heap_size > 2){
            //freq = h.writeMin();
            freq = harr.at(1).frequency;
            writeFile << "STRING" << harr.at(1).str << ":" << "Frequency" << freq << ",";
            deleteMin();
       }
       if(heap_size == 2)
       {
            freq = harr.at(1).frequency;
            writeFile << "STRING" << harr.at(1).str << ":" << "Frequency" << freq;
       }
    }else cout << "no file was provided to write to" << endl;
    writeFile.close();  
}

void MinHeap::printRoot() { cout << "Frequency: " << harr.at(1).frequency << " Count: " << harr.at(1).c << endl; }

string MinHeap::getRootString() { return harr.at(1).str; }

void MinHeap::iterateFreq(int i) { harr.at(i).frequency++; }
