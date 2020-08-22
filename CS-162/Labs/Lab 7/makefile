CC = g++

EXE_FILE = shapes

all: $(EXE_FILE)

$(EXE_FILE): shape.o rectangle.o circle.o square.o main.o
	$(CC) shape.o rectangle.o circle.o square.o main.o -o $(EXE_FILE)

main: 
	$(CC) -c main.cpp	

shape: 
	$(CC) -c shape.h shape.cpp 

rectangle:
	$(CC) -c rectangle.h rectangle.cpp 

circle:
	$(CC) -c circle.h circle.cpp

square: 
	$(CC) -c square.h square.cpp
clean:
	rm -f *.o $(EXE_FILE)



