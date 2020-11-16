#include <ostream>
#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::ostream;
using std::string;
using std::endl;
using std::vector;

class Person
{
  private: 
    string name;
    int32_t age;

  public:
    Person() {};
    Person(string name , int32_t age) {
      this->name = name;
      this->age = age;
    }

    Person (const Person& p1) {
        this->name = p1.name;
        this->age = p1.age;
    }

    const int32_t get_age()
    {
      return age;
    }

    const string get_name()
    {
      return name;
    }

    friend ostream & operator <<(ostream & os_stream, Person p)
    {
      os_stream << "\t Name: " << p.get_name() << ", Age: " << p.get_age() << endl;
      return os_stream;
    }
};

template<typename T=Person>
class circular_queue
{
  private :
    vector<T*> arr;
    int32_t read_head;
    int32_t write_head;
    int32_t max_capacity;

  public:
    circular_queue(int32_t);
    void enqueue(T element);
    void dequeue();
    T front();
    //void printQ();
};
