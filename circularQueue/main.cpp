
#include "circular_queue.cpp"

#define print(x,y) cout <<"\t"<<x<<" : "<<y<<endl


void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}

void help()
{
  cout << "[*] Enter as follows : "<<endl;
  cout << "\t1. Insert(at rear) in circular_queue" <<endl;
  cout << "\t2. Print front of circular Queue" <<endl;
  cout << "\t3. Remove front of circular Queue" <<endl;
  //cout << "\t4. Print all elems" << endl;
  cout << "\t9. To Quit" <<endl;
  return;
}

int main( )		{

  int32_t max_size_t , age; 
  string name; 
  cout << "[*] Enter max_size of circular_queue : ";
  cin  >> max_size_t;
  circular_queue<Person> q(max_size_t);

  clearScreen();
  while (true) 
  {
    help();
    int choice;
    cout << "\n[*] Enter choice: ";
    cin>>choice;
    if ( choice < 1 || choice > 10 )
    {
      cerr << "[#] Invalid choice, please run again and provide valid input" << endl;
      exit(1);   // user screwed up
    }
    switch (choice)
    {
      case 1:
        {
          cout << "\t[*] Enter Name of Person : ";
          cin>>name;
          cout << "\t[*] Enter age of Person : ";
          cin>>age;
          q.enqueue( Person(name , age) );
          break;
        }
      case 2:
        {
          Person p;
          try {
              cout << "[*] Front element in circular_queue : " << q.front() << endl;
          }
          catch (string &s) {
              cout << s << endl;
          }

          break;
        }
      case 3:
        {
          try {
              q.dequeue();
          }
          catch (string &s) {
              cout << s << endl;
          }
          break;
        }
      //case 4: {
      //          q.printQ();
      //        }
      //        break;
      case 9:
        return 0;
      default:
        {
          cout << "\t[#] That ain't an option, try again..."<<endl;
          break;
        }
    }
  }
  return 0;
}
