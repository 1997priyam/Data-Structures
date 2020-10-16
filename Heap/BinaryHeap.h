# pragma once

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class BinaryHeap
{
  vector<T> *data;      // create only when an object of this class is created.

  public:
  BinaryHeap(T val);

  T getTop();   // function to return top element of Heap.

  void remove();    // Function to remove element from Heap  : ALWAYS REMOVE TOP ELEMENT ONLY.

  void insert(T val); // Function to insert a value in heap

  int size();   // Returns size of Heap.

  bool isEmpty();   // Returns true if heap is empty else return false.

  void printHeap();   // Print all elements of heap

};

