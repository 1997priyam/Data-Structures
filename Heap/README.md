&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Binary Heap</h2>

##### -> A Binary Heap is a Binary Tree with these extra characteristics :

|S.No| Property             | Explaination
|----| ---------------------|--------------------
|1.  | Complete Binary Tree |  The Tree is complete, it means all the nodes are filled except the last level which might be empty , this property helps storing the heap in an array, thus using lesser space.
|2.  | Heap Order Property/Heapify |  Min Heap or Max Heap, it means either the root of the heap will be the smallest element of heap or the biggest always resp.


##### -> Based on `Min/Max` heap the heap whenever we seek to get top element it will return the `Max/Min` element but this doesn't mean it stores the element in a sorted order, **because it doesn't**.
##### -> So basically , a HEAP is a *`Complete binary Tree in an Array`* with some additional functions.
##### -> Since the heap will always be a complete binary Tree thus it's max height would be O(logN).where 'n' is the number of nodes in heap.
##### -> In the array representation of heap the nodes are stored as : 

|S.No| Node         | Location        | 
|----| -------------|-----------------|
|1.  | Parent       | **k** th index  | 
|2.  | Left Child   | 2\***k** + 1    | 
|3.  | Right Child  | 2\***k** + 2    | 

##### -> Time Complexities : 
|S.No| Operation                          | Time Complexity                                                   | 
|----| -----------------------------------|------------------------------------------------------------------ |
|1.  | Insertion                          | O(1)(push_back in vector) + O(logN)(for heapify) (Worst Case)     | 
|2.  | Deletion                           | O(1)(pop_back in vector)  + O(logN)(for heapify)  (Worst Case)    | 
|3.  | getMin/Max (based on type of heap) | O(1)                                                              | 

##### -> All of these operations are O(1) + time complexity of heapify function, which helps to satisfy heap order property.

##### -> Deletion can only be done at end (unless you use heap order property.)
##### -> Heap Order Property : The root must be greater/smaller than either of it's childs  depending on Max/Min Heap resp and this is for entire Tree.

##### -> `MinHeap` is implemented in the code.
##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/Tree/Heap
user@localhost:~/DataStructures/Tree/Heap$ make install
user@localhost:~/DataStructures/Tree/Heap$ make run

```

##### -> The folder structure is as follows : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | BinaryHeap.h                              | Class definition of Binary Heap.                                        |
|2.  | BinaryHeap.cpp                            | Class Implementation of Binary Heap.                                    |
|3.  | main.cpp                                  | Main file which runs the program                                        |
|4.  | makefile                                  | File responsible for compiling/running etc                              |

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h3>Note : </h3>                                                                                                                                                          

##### -> We don't use Balanced binary tree because balancing adds up more time complexity and moreover it's easier to store and perform the reqd operations for Heap in an Array.
##### -> Complete Binary Tree : It is a Binary Tree in which the nodes in the bottom most level are filled in left-to-right order and we cannot jump insertion to a new level untill the previous level is completely filled.
