
#include"BinaryHeap.h"

  template<typename T>
  BinaryHeap<T> :: BinaryHeap(T firstVal)
  {
    data = new vector<T>;     
    data->push_back(firstVal);
  }


  template<typename T>
  T BinaryHeap<T> :: getTop()      // function to return top element of Heap.
  {
    return data->at(0);   // Simply return element at 0th index.
  }


  template<typename T>
  void BinaryHeap<T> :: printHeap()
  {
    cout <<"[*] The elements of Heap are as : "<<endl;
    for (unsigned int i = 0 ; i < data->size() ; i++)
      cout << " "<<data->at(i);
    cout <<endl;
  }


  template<typename T>
  int BinaryHeap<T> :: size()   // Returns size of Heap.
  {
    return data->size();
  }


  template<typename T>
  bool BinaryHeap<T> :: isEmpty()    // Returns true if heap is empty else return false.
  {
    return data->size()>0 ? "true":"false";
  } 


  template<typename T>
  void BinaryHeap<T> :: remove()    // Function to remove element from Heap  : ALWAYS REMOVE TOP ELEMENT ONLY.
  {
    if (data->size() == 0)
      return;     // Cannot remove when already empty

    // Swap root with the last element then pop the last and call heapify function.
    data->at(0) = data->at(data->size()-1);
    data->pop_back();  // No need to save it.
    
    // Ensure that Heap order property is satisfied.
    // Top Down now, to check that root satisfies Heap Order Property.

    // Check if child exists of root.
    int parent     = 0;     // Hard-Coded becuase it's obv. initially it would be that only.
    int dataSize = (int)data->size();

    while (parent < dataSize)
    {
      int leftChild  = 2*parent + 1;     
      int rightChild = 2*parent + 2;


      if ( (leftChild < dataSize-1) && (rightChild < dataSize-1) )
      {
        // Both left and right exists
        // Swap parent with smaller of leftChild/rightchild

        if ( (data->at(parent) > data->at(leftChild)) || (data->at(parent) > data->at(rightChild)) )
        {
          int smaller = data->at(leftChild) < data->at(rightChild) ? leftChild : rightChild;
          swap (data->at(parent) , data->at(smaller));
          parent = smaller;
        }
        else
        // All good break from loop , parent is smallest
        break;

      }
      // Only if left child exists
      else if (leftChild < (int)data->size() && (data->at(leftChild) < data->at(parent) ) )
        {
          swap (data->at(leftChild) , data->at(parent));
          parent = leftChild;
        }
      else
        // All good break from loop , parent is smallest
        break;
      }
    
    return;
  }


  template<typename T>
  void BinaryHeap<T> :: insert(T val) // Function to insert a value in heap
  {
    // Push_back element in the array and call heapofy.
    data->push_back(val);
    
    // Ensure that Heap order property is satisfied.

    if (data->size() == 1) // No need to call heapify on empty heap.
      return;

    // Heap Order property
    
    int childIndex = data->size()-1;
    int parentIndex = (childIndex-1)/2;
    
    // Check for all parents
    while (childIndex > 0) 
    {
      if (data->at(childIndex) <= data->at(parentIndex))     // 'Child-Value' Less than 'Parent-Value' = Min Heap.
      {
        // swap them and check for parent too.
        T temp = data->at(parentIndex);
        data->at(parentIndex) = data->at(childIndex);
        data->at(childIndex) = temp;

        // Now child index and parentIndex will be modified
        childIndex = parentIndex;
        parentIndex = (childIndex-1)/2;
      }
      else
        break;
    }
    // Heap order property satisfied above.
    return;
  }

