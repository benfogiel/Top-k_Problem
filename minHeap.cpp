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
#include <random>
#include<vector>

using namespace std;

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap) : capacity(cap)
{
    heap_size = 0;
    count = 0;
    Node n = Node();
    harr.resize(0);
    harr.push_back(n);
}

// Inserts a new Node
void MinHeap::insert(Node* hash)
{
    if (harr.size() == capacity + 1)
    {
        harr.at(1).hashElm = hash;
        hash->heapElm = &harr.at(1);
	    swapMin(hash->str);
        return;
    }
    Node n = Node();
    // First insert the new key at the end
    int i = harr.size();
    harr.push_back(n);
    harr.at(i).frequency = 1;
    harr.at(i).c = count;
    harr.at(i).str = hash->str;
    harr.at(i).hashElm = hash;
    hash->heapElm = &harr.at(i);
    count++;
    heap_size++;

    // Fix the min heap property if it is violated
    while (i > 0 && compare(parent(i),i))
    {
       swap(i,parent(i));
       i = parent(i);
    }
    return;
}

// delete min
void MinHeap::deleteMin(){
	harr.at(0) = harr.at(1);       
	swap(1, harr.size()-1);
    harr.pop_back();
	heap_size--;
	MinHeapify(1);
}

// Method to remove minimum element (or root) from min heap
void MinHeap::swapMin(string str)
{
    // Store the minimum value, and remove it from heap
    harr.at(1).frequency++;
    harr.at(1).c = count;
    harr.at(1).str = str;
    count++;
    if (heap_size > 1)
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
    if (l < heap_size+1 && !compare(l,i))
    {
    	smallest = l;
    }
    if (r < heap_size+1 && !compare(r,smallest))
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
    harr.at(x).hashElm->heapElm = &harr.at(y);
    harr.at(y).hashElm->heapElm = &harr.at(x);
    std::swap(harr[x],harr[y]);
}

// compares two nodes in the heap. Will return true if the first index (i) is greater than the second (j)
bool MinHeap::compare(int i, int j){
	if ((harr.at(i).frequency > harr.at(j).frequency) || ((harr.at(i).frequency == harr.at(j).frequency) && (harr.at(i).c < harr.at(j).c)))
		return true;
	return false;
}

void MinHeap::printRoot() { cout << "Frequency: " << harr.at(1).frequency << " Count: " << harr.at(1).c << endl; }

string MinHeap::getRootString() { return harr.at(1).str; }

void MinHeap::iterateFreq(string s) {
    for (int i = 1; i < heap_size + 1; i++)
    {
        if (harr.at(i).str.compare(s) == 0)
        {
            harr.at(i).frequency++;
            MinHeapify(i);
            return;
        }
    }
    cout << "MinHeap::iterateFreq did not find the element in the heap" << endl;
    exit(1);
}
