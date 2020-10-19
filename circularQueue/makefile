CFLAGS=-std=c++11 -Wall -O2

all: circular_queue

install: circular_queue

circular_queue: main.o circular_queue.o
		$(CXX) $(CFLAGS) main.o circular_queue.o -o circular_queue

main.o: main.cpp circular_queue.h
		$(CXX) $(CFLAGS) -c main.cpp -o main.o

circular_queue.o : circular_queue.cpp circular_queue.h
		$(CXX) $(CFLAGS) -c circular_queue.cpp -o circular_queue.o

clear:
	rm -f *.o circular_queue

clean:
	rm -f *.o circular_queue

rm:
	rm -f *.o circular_queue

run:
		./circular_queue
