
#include "circular_queue.h"

template<typename T>
circular_queue<T>::circular_queue(int32_t max_elements)
{
  read_head = 0;
  write_head = 0;
  max_capacity = max_elements;
  arr = vector<T*> (max_capacity);
}

template<typename T>
T circular_queue<T>::front()
{
  string crash = "CRASH: No object exists";
  Person *p = arr.at(read_head % max_capacity);
  if (p == nullptr)
      throw (crash);
  return *p;
}

template<typename T>
void circular_queue<T>::enqueue (T element)
{
    if (arr[write_head% max_capacity] != nullptr)
        cout << "Over-writing : " << *arr[write_head% max_capacity] ;
  arr[ (write_head++ % max_capacity ) ] = new T(element);
  //arr[10] = element;
  //cout << arr.size();
}

template<typename T>
void circular_queue<T>::dequeue ()
{
  string crash = "CRASH: No object exists";
  Person *p = arr.at(read_head % max_capacity);
  if (p == nullptr)
      throw (crash);
  arr[read_head++ % max_capacity] = nullptr;  // start reading from next element
}

/*
template<typename T>
void circular_queue<T>::printQ() {
    int rd = read_head;
    for (int i = 0 ; i < (int)arr.size(); i ++) {
        if (arr[i] == nullptr)
            continue;
        cout << i << "." << *arr[i];
        rd++;
    }
    return;
}
*/
