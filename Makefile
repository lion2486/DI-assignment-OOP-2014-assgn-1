CC=g++
CFLAG=-O2
TESTFLAGS=-Wall -g
SOURCES=main.cpp List.cpp  building.cpp office.cpp entrance.cpp floor.cpp elevator.cpp
OBJS=main.o List.o building.o office.o entrance.o floor.o elevator.o
EXECUTABLE=main
LIB=

all: buildTests
	
buildTests: $(OBJS)
	$(CC) $(TESTFLAGS) $(OBJS) -o $(EXECUTABLE) $(LIB)

run:
	./$(EXECUTABLE) 150 40 50 8 10 100 10

main.o: main.cpp
	$(CC) -c $(TESTFLAGS) main.cpp -o main.o

List.o: List.cpp
	$(CC) -c $(TESTFLAGS) List.cpp -o List.o
	
building.o: building.cpp
	$(CC) -c $(TESTFLAGS) building.cpp -o building.o
	
floor.o: floor.cpp
	$(CC) -c $(TESTFLAGS) floor.cpp -o floor.o
	
entrance.o: entrance.cpp
	$(CC) -c $(TESTFLAGS) entrance.cpp -o entrance.o
	
office.o: office.cpp
	$(CC) -c $(TESTFLAGS) office.cpp -o office.o
	
elevator.o: elevator.cpp
	$(CC) -c $(TESTFLAGS) elevator.cpp -o elevator.o
	
clean:
	rm -f $(EXECUTABLE) $(OBJS)
