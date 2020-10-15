
#include "BinaryHeap.cpp"

void help()
{
  cout << endl<<"\t\t\t Min Heap"<<endl;
  cout <<"[*] Select as follows : "<<endl;
  cout << "\t 1. For Insertion "<<endl;
  cout << "\t 2. To fetch top element "<<endl;
  cout << "\t 3. To Remove top element from Heap "<<endl;
  cout << "\t 4. To print entire Heap "<<endl;
  cout << "\t 5. To print size of Heap "<<endl;
  cout << "\t 6. To clearScreen"<<endl;
  cout << "\t 9. To Quit : ";
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}


int main( int argc,  char *argv[]){

	clearScreen();
  int x;
  cout << "[*] Enter first element of heap of MinHeap: ";
  cin >>x ;
  BinaryHeap<int> bHeap(x);

  while (true)
  {
    int option , value;
    help();
    cin>>option;
    switch(option)
    {
      case 1:
        cout <<"[*] Enter value to insert : ";
        cin>>value;
        bHeap.insert(value);
        cout <<"[*] Value inserted successfully in heap"<<endl;
        break;
      case 2:
        cout <<"[*] Top value in MinHeap : " << bHeap.getTop()<<endl;
        break;
      case 3:
        cout <<"[*] Deleting top value from MinHeap"<<endl;
        bHeap.remove();
        break;
      case 4:
        bHeap.printHeap();
        break;
      case 5:
        cout << "[*] Current size of heap is : " <<bHeap.size()<<endl;
        break;
      case 6:
        clearScreen();
        break;
      case 9:
        return 0;
      default:
        cout <<"\t[#] That ain't an option, try again..."<<endl;
        break;
    }
    }
  }
