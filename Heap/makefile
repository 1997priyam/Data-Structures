CFLAGS=-std=c++11 -Wall -O2 -Wsign-compare

all: binaryHeap

install: binaryHeap

binaryHeap: main.o binaryHeap.o
		$(CXX) $(CFLAGS) main.o -o binaryHeap

main.o: main.cpp
		$(CXX) $(CFLAGS) -c main.cpp

binaryHeap.o: BinaryHeap.h BinaryHeap.cpp
		$(CXX) $(CFLAGS) -c BinaryHeap.cpp

clean:
		rm -f *.o binaryHeap

clear:
		rm -f *.o binaryHeap

rm:
		rm -f *.o binaryHeap

run:
		./binaryHeap
