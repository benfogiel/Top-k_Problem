//minHeap.h
// Author: Benjamin Fogiel

#include<iostream>
#include<cstring>
#include<climits>

#ifndef MINHEAP_H
#define MINHEAP_H

using namespace std;

// A class for Min Heap
class MinHeap
{
public:
    struct Node {
            int c;
            int frequency;
            Node* heapElm;
            Node* hashElm;
            string str;
    };
    // might be able to replace 999 with capacity under var declaration
    Node** harr = new Node*[999];
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap 
    int count; // tracks the age of each node in the heap 

    // Constructor
    MinHeap(int capacity);
 
    // Destructor
    ~MinHeap();

    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
  
    int parent(int i) { return i/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 1); }
  
    // to extract the root which is the minimum element
    void swapMin();
  
    // Inserts a new key
    Node* insert();

    //returns true if value at index i > j
    bool compare(int i, int j);

    // A utility function to swap two elements
    void swap(int x, int y);

    // Returns the string that refers to the root node
    string getRootString() { return harr[1]->hashElm->str; }

    //print heap in ascending order
    void write(ofstream& file);

    void deleteMin();

    void printRoot() { cout << harr[1]->frequency << endl; }
};

#endif
