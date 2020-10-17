&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Circular Queue</h2>

##### -> A circular queue is implemented using an array of fixed size.
##### -> The enqueue operation i.e insertion is performed at one end and the dequeue operation i.e deletion is performed at other.
##### -> This sort of CircularQueue is useful in for producer-consumer problems, where 1 part(producer) is writing to the queue and the other part (consumer) is reading/popping from the queue.
##### -> Once the max size is reached then the content of the queue is over-written (in production this should be handled explicitly)

##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/circularQueue
user@localhost:~/DataStructures/circularQueue$ make install
user@localhost:~/DataStructures/circularQueue$ make run

```

##### -> The code will take the size of circular\_queue as input and then the operation to perform.
<hr/>

### Technical Insights
##### -> Files and their contents are as : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | circular\_queue.h                         | Header file for circular queue                                          |
|2.  | circular\_queue.cpp                       | File containing the implementation.                                     |
|3.  | main.cpp                                  | Main file/Entrypoint                                                    |
|4.  | makefile                                  | File responsible for compiling/running etc                              |
                                                                                                                         
                                                                                                                         
                                                                                                                         
