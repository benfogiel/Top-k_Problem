//minHeap.cpp
//Author: Benjamin Fogiel
 
#include "minHeap.h"
#include <iostream>
#include<cstring>
#include<iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include "openssl/sha.h"
#include <random>

using namespace std;

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap+1;
    count = 0;
}

// Destructor
MinHeap::~MinHeap(){
	for (int i = 0; i < capacity; i++){
		free(harr[i]);
	}
	delete *harr;
}

// Inserts a new key 'k'
MinHeap::Node* MinHeap::insert()
{
    if (heap_size+1 == capacity)
    {
	swapMin();
        return harr[1];
    }

    Node *n = new Node();
    // First insert the new key at the end
    heap_size++;
    int i = heap_size;
    harr[i] = n;
    n->frequency = 1;
    n->c = count;
    count++;

    // Fix the min heap property if it is violated
    while (i != 1 && compare(parent(i),i))
    {
       swap(i,parent(i));
       i = parent(i);
    }
    return n;
}

// delete min
void MinHeap::deleteMin(){
	harr[0] = harr[1];       
	harr[1] = harr[heap_size];
	heap_size--;
	MinHeapify(1);
	return;
}

// Method to remove minimum element (or root) from min heap
void MinHeap::swapMin()
{
    // Store the minimum value, and remove it from heap
    harr[1]->frequency = harr[1]->frequency+1;
    harr[1]->c = count;
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
    if (l < heap_size && !compare(l,r))
    	smallest = l;
    if (r < heap_size && !compare(r,smallest))
        smallest = r;
    if (smallest != i)
    {
        swap(i, smallest);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void MinHeap::swap(int x, int y)
{
    Node *temp = harr[x];
    harr[x] = harr[y];
    harr[y] = temp;
}

// compares two nodes in the heap. Will return true if the first index (i) is greater than the second (j)
bool MinHeap::compare(int i, int j){
	if (harr[i]->frequency > harr[j]->frequency || (harr[i]->frequency == harr[j]->frequency && harr[i]->c < harr[j]->c))
		return true;
	return false;
}

void MinHeap::write(ofstream& file) {
	if (file.is_open()){
	while(heap_size > 1){
		file << "STRING" << harr[1]->hashElm->str << ":FREQUENCY" << harr[1]->frequency << ",";
		deleteMin();
	}
	}else cout << "no file was provided to write to" << endl;
	if(heap_size == 1) file << "STRING" << harr[1]->hashElm->str << ":FREQUENCY" << harr[1]->frequency;
		
}
